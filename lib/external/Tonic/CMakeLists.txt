cmake_minimum_required(VERSION 3.16)
project(Tonic)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(examples/Standalone/RTAudio)

add_library(Tonic SHARED
        src/Tonic.h
        src/Tonic/ADSR.cpp
        src/Tonic/ADSR.h
        src/Tonic/Arithmetic.cpp
        src/Tonic/Arithmetic.h
        src/Tonic/AudioFileUtils.cpp
        src/Tonic/AudioFileUtils.h
        src/Tonic/BasicDelay.cpp
        src/Tonic/BasicDelay.h
        src/Tonic/BitCrusher.cpp
        src/Tonic/BitCrusher.h
        src/Tonic/BLEPOscillator.cpp
        src/Tonic/BLEPOscillator.h
        src/Tonic/BufferFiller.cpp
        src/Tonic/BufferFiller.h
        src/Tonic/BufferPlayer.cpp
        src/Tonic/BufferPlayer.h
        src/Tonic/CombFilter.cpp
        src/Tonic/CombFilter.h
        src/Tonic/CompressorLimiter.cpp
        src/Tonic/CompressorLimiter.h
        src/Tonic/ControlArithmetic.cpp
        src/Tonic/ControlArithmetic.h
        src/Tonic/ControlCallback.cpp
        src/Tonic/ControlCallback.h
        src/Tonic/ControlChangeNotifier.cpp
        src/Tonic/ControlChangeNotifier.h
        src/Tonic/ControlComparison.cpp
        src/Tonic/ControlComparison.h
        src/Tonic/ControlConditioner.cpp
        src/Tonic/ControlConditioner.h
        src/Tonic/ControlCounter.cpp
        src/Tonic/ControlCounter.h
        src/Tonic/ControlDbToLinear.cpp
        src/Tonic/ControlDbToLinear.h
        src/Tonic/ControlDelay.cpp
        src/Tonic/ControlDelay.h
        src/Tonic/ControlFloor.cpp
        src/Tonic/ControlFloor.h
        src/Tonic/ControlGenerator.cpp
        src/Tonic/ControlGenerator.h
        src/Tonic/ControlMetro.cpp
        src/Tonic/ControlMetro.h
        src/Tonic/ControlMetroDivider.cpp
        src/Tonic/ControlMetroDivider.h
        src/Tonic/ControlMidiToFreq.cpp
        src/Tonic/ControlMidiToFreq.h
        src/Tonic/ControlParameter.cpp
        src/Tonic/ControlParameter.h
        src/Tonic/ControlPrinter.cpp
        src/Tonic/ControlPrinter.h
        src/Tonic/ControlPulse.cpp
        src/Tonic/ControlPulse.h
        src/Tonic/ControlRandom.cpp
        src/Tonic/ControlRandom.h
        src/Tonic/ControlRecorder.cpp
        src/Tonic/ControlRecorder.h
        src/Tonic/ControlSnapToScale.cpp
        src/Tonic/ControlSnapToScale.h
        src/Tonic/ControlStepper.cpp
        src/Tonic/ControlStepper.h
        src/Tonic/ControlSwitcher.cpp
        src/Tonic/ControlSwitcher.h
        src/Tonic/ControlTrigger.cpp
        src/Tonic/ControlTrigger.h
        src/Tonic/ControlTriggerFilter.cpp
        src/Tonic/ControlTriggerFilter.h
        src/Tonic/ControlValue.cpp
        src/Tonic/ControlValue.h
        src/Tonic/ControlXYSpeed.cpp
        src/Tonic/ControlXYSpeed.h
        src/Tonic/DelayUtils.cpp
        src/Tonic/DelayUtils.h
        src/Tonic/DSPUtils.cpp
        src/Tonic/DSPUtils.h
        src/Tonic/Effect.cpp
        src/Tonic/Effect.h
        src/Tonic/Filters.cpp
        src/Tonic/Filters.h
        src/Tonic/FilterUtils.cpp
        src/Tonic/FilterUtils.h
        src/Tonic/FixedValue.cpp
        src/Tonic/FixedValue.h
        src/Tonic/Generator.cpp
        src/Tonic/Generator.h
        src/Tonic/LFNoise.cpp
        src/Tonic/LFNoise.h
        src/Tonic/Mixer.cpp
        src/Tonic/Mixer.h
        src/Tonic/MonoToStereoPanner.cpp
        src/Tonic/MonoToStereoPanner.h
        src/Tonic/Noise.cpp
        src/Tonic/Noise.h
        src/Tonic/RampedValue.cpp
        src/Tonic/RampedValue.h
        src/Tonic/RectWave.cpp
        src/Tonic/RectWave.h
        src/Tonic/Reverb.cpp
        src/Tonic/Reverb.h
        src/Tonic/RingBuffer.cpp
        src/Tonic/RingBuffer.h
        src/Tonic/SampleTable.cpp
        src/Tonic/SampleTable.h
        src/Tonic/SawtoothWave.cpp
        src/Tonic/SawtoothWave.h
        src/Tonic/SineWave.cpp
        src/Tonic/SineWave.h
        src/Tonic/SquareWave.h
        src/Tonic/StereoDelay.cpp
        src/Tonic/StereoDelay.h
        src/Tonic/Synth.cpp
        src/Tonic/Synth.h
        src/Tonic/TableLookupOsc.cpp
        src/Tonic/TableLookupOsc.h
        src/Tonic/TonicCore.h
        src/Tonic/TonicFrames.cpp
        src/Tonic/TonicFrames.h
        src/Tonic/TriangleWave.h
)

#target_link_libraries(Tonic rtaudio)

target_include_directories(Tonic PRIVATE src)
#target_include_directories(Tonic PRIVATE ../RtAudio)

add_custom_command(TARGET Tonic
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy libTonicd.dll ${CMAKE_CURRENT_BINARY_DIR}/../../..
)