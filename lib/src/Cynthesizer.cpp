#include "Cynthesizer.h"

bool key_depressed = false;

auto Cynthesizer::make_piano_key(Note n, color c) {
    auto p_key = share(layered_button(
            left_margin(
                    7,
                    rbox(c, 10)
            ),
            left_margin(
                    7,
                    rbox(c.level(0.8), 10)
            ))
    );
    piano_keys[p_key] = n;
    return hold(p_key);

}

auto Cynthesizer::make_piano() {
    return layer(
            vsize(
                    125,
                    htile(
                            hspacer(95),
                            make_piano_key(Note::CS, colors::dark_slate_gray),
                            hspacer(50),
                            make_piano_key(Note::DS, colors::dark_slate_gray),
                            hspacer(190),
                            make_piano_key(Note::FS, colors::dark_slate_gray),
                            hspacer(50),
                            make_piano_key(Note::GS, colors::dark_slate_gray),
                            hspacer(50),
                            make_piano_key(Note::AS, colors::dark_slate_gray),
                            hspacer(235)
                    )
            ),
            htile(
                    make_piano_key(Note::C_lo, colors::ivory),
                    make_piano_key(Note::D, colors::ivory),
                    make_piano_key(Note::E, colors::ivory),
                    make_piano_key(Note::F, colors::ivory),
                    make_piano_key(Note::G, colors::ivory),
                    make_piano_key(Note::A, colors::ivory),
                    make_piano_key(Note::B, colors::ivory),
                    make_piano_key(Note::C_hi, colors::ivory)
            )
    );
}

auto Cynthesizer::make_dial(int index, std::string my_label, int starting_lvl) {
    dials[index] = share(
            dial(
                    radial_marks<20>(basic_knob<100>()),
                    starting_lvl
            )
    );

    auto markers = vgrid(
            bottom_margin(10, label(std::move(my_label))),
            radial_labels<15>(
                    hold(dials[index]),
                    0.7,                                   // Label font size (relative size)
                    "0", "1", "2", "3", "4",               // Labels
                    "5", "6", "7", "8", "9", "10"
            )
    );
    return align_center_middle(markers);
}

auto Cynthesizer::make_radio_buttons() {
    auto sine_wave = radio_button("Sine wave");
    auto square_wave = radio_button("Square wave");
    auto sawtooth_wave = radio_button("Sawtooth wave");
    auto triangle_wave = radio_button("Triangle wave");

    sine_wave.select(true);

    radio_buttons[0] = share(sine_wave);
    radio_buttons[1] = share(square_wave);
    radio_buttons[2] = share(sawtooth_wave);
    radio_buttons[3] = share(triangle_wave);

    return group("Waveform",
                 margin({10, 10, 20, 20},
                        top_margin(25,
                                   vtile(
                                           top_margin(10, align_left(hold(radio_buttons[0]))),
                                           top_margin(10, align_left(hold(radio_buttons[1]))),
                                           top_margin(10, align_left(hold(radio_buttons[2]))),
                                           top_margin(10, align_left(hold(radio_buttons[3])))
                                   )
                        )
                 )
    );
}

auto Cynthesizer::make_controls_upper(view &view_) {
    return hgrid(
            make_radio_buttons(),
            make_dial(0, "Attack", 0),
            make_dial(1, "Decay", 0)
    );
}

auto Cynthesizer::make_markers() {
    auto track = basic_track<5, false>();
    return slider_labels<10>(
            slider_marks<40>(track),         // Track with marks
            0.8,                             // Label font size (relative size)
            "0", "1", "2", "3", "4",         // Labels
            "5", "6", "7", "8", "9", "10"
    );
}

auto Cynthesizer::make_slider() {
    auto temp_slider = slider(
            basic_thumb<25>(),
            make_markers(),
            0
    );
    vib_slider = share(temp_slider);
    return vgrid(label("Vibrato"), hold(vib_slider));
}

auto Cynthesizer::make_controls_lower(view &view_) {
    return hgrid(
            align_middle(hmargin({20, 20}, make_slider())),
            make_dial(2, "Sustain", 1),
            make_dial(3, "Release", 0)
    );
}

void Cynthesizer::set_controls(view &view_) {
    dials[0]->on_change =
            [this](float val) {
                sound_out.setAttack(val);
                std::cout << val << std::endl;
            };
    dials[1]->on_change =
            [this](float val) {
                sound_out.setDecay(val);
            };
    dials[2]->on_change =
            [this](float val) {
                sound_out.setSustain(val);
            };
    dials[3]->on_change =
            [this](float val) {
                sound_out.setRelease(val);
            };

    radio_buttons[0]->on_click =
            [this](bool sine) {
                if (sine) sound_out.setWave(0);
                std::cout << "sine! " << sine << std::endl;
            };
    radio_buttons[1]->on_click =
            [this](bool square) {
                if (square) sound_out.setWave(1);
                std::cout << "square!" << square << std::endl;
            };
    radio_buttons[2]->on_click =
            [this](bool sawtooth) {
                if (sawtooth) sound_out.setWave(2);
                std::cout << "sawtooth!" << sawtooth << std::endl;
            };
    radio_buttons[3]->on_click =
            [this](bool triangle) {
                if (triangle) sound_out.setWave(3);
                std::cout << "triangle!" << triangle << std::endl;
            };

    vib_slider->on_change =
            [this](float val) {
                sound_out.setVibrato(val);
                std::cout << val << std::endl;
            };


    for (const auto& p: piano_keys) {
        p.first->on_click =
                [p, this](bool pressed) {
                    key_depressed = !key_depressed;
                    if (key_depressed) {
                        sound_out.playNote(p.second);
                    }
                    else sound_out.stopNote();
                };
    }
}

int Cynthesizer::run(int argc, char *argv[]) {

    rect const &bounds = rect{base_x, base_y,
                              base_x + win_width, base_y + win_height};
    app _app(argc, argv, "Cynthesizer", "com.id");
    window _win(
            _app.name(),
            window::style::with_title | window::style::closable | window::style::miniaturizable,
            bounds);
    _win.on_close = [&_app]() { _app.stop(); };

    view view_(_win);

    view_.content(
            vgrid(
                    make_controls_upper(view_),
                    make_controls_lower(view_),
                    make_piano()
            ),
            background
    );

    set_controls(view_);

    _app.run();
    return 0;
}