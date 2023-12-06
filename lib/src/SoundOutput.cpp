#include "SoundOutput.h"
#include "Tonic.h"
#include "RtAudio.h"
#include <iostream>

using namespace Tonic;

///////////////////////////////////////////////////
// Tonic stuff, not in SoundOutput class
// because it's specific to the implementation
const unsigned int nChannels = 2;
RtAudio dac;
RtAudio::StreamParameters rtParams;
unsigned int bufferFrames = 512; // 512 sample frames
static Synth synth;
ControlTrigger adsr_trigger;
Generator tone;
ADSR env;
int renderCallback(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
                   double streamTime, RtAudioStreamStatus status, void *userData) {
    synth.fillBufferOfFloats((float *) outputBuffer, nBufferFrames, nChannels);
    return 0;
}
///////////////////////////////////////////////////

SoundOutput::SoundOutput() {
    rtParams.deviceId = dac.getDefaultOutputDevice();
    rtParams.nChannels = nChannels;

    // default values for ADSR
    attack = 0;
    decay = 0;
    sustain = 0.5;
    release = 0;

    // populate note_pitch map
    note_pitch[Note::C_lo] = 261.63;
    note_pitch[Note::CS] = 277.18;
    note_pitch[Note::D] = 293.66;
    note_pitch[Note::DS] = 311.13;
    note_pitch[Note::E] = 329.63;
    note_pitch[Note::F] = 349.23;
    note_pitch[Note::FS] = 369.99;
    note_pitch[Note::G] = 392;
    note_pitch[Note::GS] = 415.3;
    note_pitch[Note::A] = 440;
    note_pitch[Note::AS] = 466.16;
    note_pitch[Note::B] = 493.88;
    note_pitch[Note::C_hi] = 523.25;

    dac.openStream(&rtParams, nullptr, RTAUDIO_FLOAT32, Tonic::sampleRate(),
                   &bufferFrames, &renderCallback, nullptr, nullptr);
    dac.startStream();
    dac.stopStream();
}

void SoundOutput::setAttack(float val) {
    attack = val * 2;
}
void SoundOutput::setDecay(float val) {
    decay = val * 2;
}
void SoundOutput::setSustain(float val) {
    sustain = val * 0.5;
}
void SoundOutput::setRelease(float val) {
    release = val * 2;
}

void SoundOutput::setVibrato(float val) {
    vibrato = val * 5;
}

void SoundOutput::setWave(int val) {
    wave = val;
}


void SoundOutput::playNote(Note n) {
    switch (wave) {
        case 0:
            tone = SineWave().freq(note_pitch[n]);
            break;
        case 1:
            tone = SquareWaveBL().freq(note_pitch[n]);
            break;
        case 2:
            tone = SawtoothWaveBL().freq(note_pitch[n]);
            break;
        case 3:
            tone = TriangleWave().freq(note_pitch[n]);
            break;
        default:
            std::cout << "impossible case" << std::endl;
    }

    env = ADSR()
            .attack(attack)
            .decay(decay)
            .sustain(sustain)
            .release(release)
            .trigger(adsr_trigger);

    adsr_trigger.trigger();
    synth.setOutputGen(tone * env + SineWave().freq(vibrato));
    dac.startStream();
}

void SoundOutput::stopNote() {
    dac.stopStream();

}

SoundOutput::~SoundOutput() {
    dac.closeStream();
}



