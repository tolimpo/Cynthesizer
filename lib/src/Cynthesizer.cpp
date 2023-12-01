#include "Cynthesizer.h"
#include <elements.hpp>

using namespace cycfi::elements;

auto constexpr bkd_color = rgba(35, 35, 37, 255);
auto background = box(bkd_color);

//auto blue_rbox =
//        align_center_middle(
//                fixed_size(
//                        {100, 50},
//                        rbox(colors::medium_blue, 10)
//                )
//        );


auto btn_rbox(color c) {
    return
            margin(
                    {5, 5, 5, 5},
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
            btn_rbox(colors::black.level(0.8))
    );
}

auto make_piano() {
    return layer(
            hgrid(
                    make_black_key(),
                    make_black_key(),
                    make_black_key(),
                    make_black_key(),
                    make_black_key()
            ),
            hgrid(
                    make_white_key(),
                    make_white_key(),
                    make_white_key(),
                    make_white_key(),
                    make_white_key(),
                    make_white_key(),
                    make_white_key(),
                    make_white_key()
            )
    );
//    return hgrid(
//            make_white_key(),
//            make_white_key(),
//            make_white_key(),
//            make_white_key(),
//            make_white_key(),
//            make_white_key(),
//            make_white_key(),
//            make_white_key()
//    );
}

auto make_control_panel() {
    return btn_rbox(colors::black);
}

auto make_screen() {
    return vgrid(
            make_control_panel(),
            make_piano()
    );
}

int Cynthesizer::run(int argc, char *argv[]) {
    app _app(argc, argv, "Cynthesizer", "com.id");
    window _win(_app.name());
    _win.on_close = [&_app]() { _app.stop(); };

    view view_(_win);

    view_.content(
            align_center_bottom(make_screen()),
            background
    );

    _app.run();
    return 0;
}