# CS3520 - Final Project - Cynthesizer

Developer Name: Oreste Olimpo

## Overview

A C++ Synthesizer. It is a piano with some sound controls. I used the 
[elements](https://github.com/cycfi/elements) library to create my GUI, and the 
[Tonic](https://github.com/TonicAudio/Tonic) library for audio synthesis. I also had to include
[RtAudio](https://github.com/thestk/rtaudio) for real-time audio output.

## How to Run the Program

I developed this program on Windows. The external libraries were compiled into dynamic-link libraries,
so I think it will only work on Windows.

1. Download the repo.
2. Build and run in CLion. All external libraries and the Cynthesizer itself will build with the "Cynthesizer"
run configuration. If desired, the external libraries can be built individually with their respective
run configurations.

## Things to Consider

- Both elements and Tonic are not particularly well-documented. A lot of the time I spent on this was
sifting through the libraries themselves to figure out what was capable.
- I edited the elements library to make the piano keys function in the way I intended. I probably could
have extended the elements button class, but I did not want to figure that out.
- The piano keys can be finicky with pressing. Try not to overlap keyboard presses, switch them too fast, 
or move the mouse pointer of the piano key once clicked.
- When the keys are clicked with the mouse, they will darken in color. This effect does not happen when the keyboard
is used. I tried making this work, but it requires a bit more thought in handling keyboard presses.
- The white keys cannot be clicked in the regions between the black keys. There are invisible "spacers"
to spread out the black keys, but they block that portion of the white keys.
- The elements library was difficult to work with as sizing and stretching of GUI elements is not straightforward.
I opted for an un-resizeable window, so that all GUI elements are fixed sizes.
- The Release knob does not function. I would need to do something more clever with the sound to allow it to perform
its "release". As I have it right now, when a piano key is released, the sound output stream is just stopped. This
stops the sound before it can do its "release".

## Future Ideas

- Make the GUI resizeable, where all GUI elements resize accordingly
- Remove my changes to the elements library and create a new piano key class that extends
the elements button class (allowing for keyboard presses to be used.
- Re-work sound output such that the Release knob functions
- Add more ways to manipulate sound

Let me know if you have a good idea for my Cynthesizer!
