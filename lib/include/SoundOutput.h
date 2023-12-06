#ifndef CYNTHESIZER_SOUNDOUTPUT_H
#define CYNTHESIZER_SOUNDOUTPUT_H


#include <unordered_map>

enum class Note {
    C_lo, CS, D, DS, E, F, FS, G, GS, A, AS, B, C_hi,
};

class SoundOutput {
private:
    std::unordered_map<Note, float> note_pitch;
    float attack;
    float decay;
    float sustain;
    float release;
    float vibrato;

    // Wave is represented by a number. Should be an enum,
    // but this works for now
    // 0 = sine
    // 1 = square
    // 2 = sawtooth
    // 3 = triangle
    int wave;

public:
    SoundOutput();
    ~SoundOutput();
    void setAttack(float val);
    void setDecay(float val);
    void setSustain(float val);
    void setRelease(float val);
    // 0 is no vibrato, 1 is full vibrato
    void setVibrato(float val);

    // 0 = sine
    // 1 = square
    // 2 = sawtooth
    // 3 = triangle
    void setWave(int val);

    void playNote(Note n);
    void stopNote();
};

#endif //CYNTHESIZER_SOUNDOUTPUT_H
