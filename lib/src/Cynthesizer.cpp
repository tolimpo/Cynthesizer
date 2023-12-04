#include "Cynthesizer.h"
#include <elements.hpp>
#include <utility>

using namespace cycfi::elements;

float base_x = 20;
float base_y = 20;
float win_width = 1120;
float win_height = 800;

auto constexpr bkd_color = rgba(35, 35, 37, 255);
auto background = box(bkd_color);

using dial_ptr = std::shared_ptr<dial_base>;
dial_ptr dials[4];

//auto blue_rbox =
//        align_center_middle(
//                fixed_size(
//                        {100, 50},
//                        rbox(colors::medium_blue, 10)
//                )
//        );


auto btn_rbox(color c) {
    return
            left_margin(
                    7,
                    rbox(c, 10)
            );

//            fixed_size(
//                    {50, 200},
//                    rbox(c, 10)
//            );
}

// TODO make piano keys
//auto make_htile_aligns()
//{
//    auto _box = left_margin(
//            { 10 },
//            vsize(150, rbox_)
//    );
//
//    return margin(
//            { 0, 50, 10, 10 },
//            htile(
//                    valign(0.0, _box),
//                    valign(0.2, _box),
//                    valign(0.4, _box),
//                    valign(0.6, _box),
//                    valign(0.8, _box),
//                    valign(1.0, _box)
//            )
//    );
//}

auto make_white_key() {

    return layered_button(
            btn_rbox(colors::ivory),            // Normal state
            btn_rbox(colors::ivory.level(0.8))  // Pushed state
    );
}

auto make_black_key() {
    return layered_button(
            btn_rbox(colors::black),
//            btn_rbox(colors::black),
            btn_rbox(colors::green.level(0.8))
    );
}

auto make_piano() {
//    return vsize(
//            180,
    return
            layer(
                    vsize(
                            125,
                            htile(
                                    hspacer(95),
                                    make_black_key(),
                                    hspacer(50),
                                    make_black_key(),
                                    hspacer(190),
                                    make_black_key(),
                                    hspacer(50),
                                    make_black_key(),
                                    hspacer(50),
                                    make_black_key(),
                                    hspacer(235)
                            )
                    ),
                    htile(
                            make_white_key(),
                            make_white_key(),
                            make_white_key(),
                            make_white_key(),
                            make_white_key(),
                            make_white_key(),
                            make_white_key(),
                            make_white_key()
                    )
//            )
            );
}

auto make_dial(int index, std::string my_label) {
    dials[index] = share(
            dial(
                    radial_marks<20>(basic_knob<100>()),
                    (index + 1) * 0.25
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

auto make_controls_upper(view &view_) {
//    return rbox(colors::indian_red, 10);
    auto sine_wave = radio_button("Sine wave");
    auto square_wave = radio_button("Square wave");
    auto sawtooth_wave = radio_button("Sawtooth wave");
    auto triangle_wave = radio_button("Triangle wave");

    sine_wave.select(true);

    auto radio_buttons =
            group("Waveform",
                  margin({10, 10, 20, 20},
                         top_margin(25,
                                    vtile(
                                            top_margin(10, align_left(sine_wave)),
                                            top_margin(10, align_left(square_wave)),
                                            top_margin(10, align_left(sawtooth_wave)),
                                            top_margin(10, align_left(triangle_wave))
                                    )
                         )
                  )
            );

    return hgrid(
            radio_buttons,
//            rbox(colors::indian_red, 10)
            make_dial(0, "Attack"),
            make_dial(1, "Decay")
    );


}

template<bool is_vertical>
auto make_markers() {
    auto track = basic_track<5, is_vertical>();
    return slider_labels<10>(
            slider_marks<40>(track),         // Track with marks
            0.8,                             // Label font size (relative size)
            "0", "1", "2", "3", "4",         // Labels
            "5", "6", "7", "8", "9", "10"
    );
}

auto make_controls_lower(view &view_) {
    auto vibrato = vgrid(

            label("Vibrato"),
            slider(
                    basic_thumb<25>(),
                    make_markers<false>(),
                    0
            )
    );
    return hgrid(
            align_middle(hmargin({20, 20}, vibrato)),
            make_dial(2, "Sustain"),
            make_dial(3, "Release")
    );
//    return rbox(colors::goldenrod, 10);
}

int Cynthesizer::run(int argc, char *argv[]) {

    rect const &bounds = rect{base_x, base_y,
                              base_x + win_width, base_y + win_height};
//    float win_width = 100;
//    float win_height = 100;
    app _app(argc, argv, "Cynthesizer", "com.id");
    window _win(
            _app.name(),
            window::style::with_title | window::style::closable | window::style::miniaturizable,
            bounds);
    _win.on_close = [&_app]() { _app.stop(); };

    view view_(_win);

    view_.content(
            vgrid(
//                    vsize(
//                            12,
                    make_controls_upper(view_),
                    make_controls_lower(view_),
//                            ),
                    make_piano()
            ),
//    align_center_bottom(make_screen()),
            background
    );

    _app.run();
    return 0;
}