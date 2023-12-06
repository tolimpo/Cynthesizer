# CS3520 - Final Project - Cynthesizer

Developer Name: Oreste Olimpo

---

## Overview

A C++ Synthesizer. It is a piano with some sound controls. I used the 
[elements](https://github.com/cycfi/elements]) library to create my GUI, and the 
[Tonic](https://github.com/TonicAudio/Tonic) library for audio synthesis. I also had to include
[RtAudio](https://github.com/thestk/rtaudio) for audio output.

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
- The piano does not support keyboard presses. I did a lot of searching and did not find a way to add key
handling to on-screen buttons
- The piano keys can be finicky if one is pressed, the mouse pointer moves away, and then released. Once 
a piano key is pressed, the mouse pointer must be released on the same piano key to work properly.
- The white keys cannot be pressed in the regions between the black keys. There are invisible "spacers"
to spread out the black keys, but they block that portion of the white keys.
- The elements library was difficult to work with as sizing and stretching of GUI elements is not straightforward.
I opted for an un-resizeable window, so that all GUI elements are fixed sizes.
- The Release knob does not function. I would need to do something more clever with the sound to allow it to perform
its "release". As I have it right now, when a piano key is released, the sound output stream is just stopped. This
stops the sound before it can do its "release".

## Future Ideas

- Make the GUI resizeable, where all GUI elements resize accordingly
- Support keyboard presses
- Re-work sound output such that the Release knob functions
- Add more ways to manipulate sound

Let me know if you have a good idea for my Cynthesizer!