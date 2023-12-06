#ifndef CYNTHESIZER_CYNTHESIZER_H
#define CYNTHESIZER_CYNTHESIZER_H

#include <elements.hpp>
#include "SoundOutput.h"

using namespace cycfi::elements;

using dial_ptr = std::shared_ptr<dial_base>;
using radio_button_ptr = std::shared_ptr<basic_button>;
using slider_ptr = std::shared_ptr<basic_slider_base>;
using piano_map = std::unordered_map<Note, std::shared_ptr<layered_button>>;
using key_map = std::unordered_map<key_code, Note>;

class Cynthesizer {

private:
    // Main window background color
    float base_x = 20;
    float base_y = 20;
    float win_width = 1120;
    float win_height = 800;
    static constexpr color bkd_color = rgba(35, 35, 37, 255);
    box_element background = box(bkd_color);
    dial_ptr dials[4];
    radio_button_ptr radio_buttons[4];
    slider_ptr vib_slider;
    piano_map note_to_piano_key;
    key_map keyboard_to_note;


    SoundOutput sound_out;

    auto make_piano_key(Note n, color c);
    auto make_piano();
    auto make_dial(int index, std::string my_label, int starting_lvl);
    auto make_radio_buttons();
    auto make_controls_upper(view &view_);
    auto make_markers();
    auto make_slider();
    auto make_controls_lower(view &view_);

    void set_controls(view& view_);

public:
    Cynthesizer();
    int run(int argc, char *argv[]);
};

#endif //CYNTHESIZER_CYNTHESIZER_H
