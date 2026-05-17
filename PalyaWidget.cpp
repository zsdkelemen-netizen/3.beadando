#include "PalyaWidget.hpp"

using namespace genv;

PalyaWidget::PalyaWidget(int x, int y, int sz, int m, std::function<void(int)> cb)
    : Widget(x, y, sz, m), _kattintas_callback(cb) {

    _tabla = std::vector<std::vector<int>>(7, std::vector<int>(6, 0));
}

void PalyaWidget::rajzol() const {
    gout << move_to(_x, _y) << color(50, 100, 255) << box(_sz, _m);

    for (int o = 0; o < 7; ++o) {
        for (int s = 0; s < 6; ++s) {
            int px = _x + o * 100 + 10;
            int py = _y + s * 100 + 10;

            if (_tabla[o][s] == 0) {
                gout << move_to(px, py) << color(0, 0, 0) << box(80, 80);
            } else if (_tabla[o][s] == 1) {
                gout << move_to(px, py) << color(255, 50, 50) << box(80, 80);
            } else if (_tabla[o][s] == 2) {
                gout << move_to(px, py) << color(255, 255, 50) << box(80, 80);
            }
        }
    }
}

void PalyaWidget::kezel(event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left) {
        if (felette(ev.pos_x, ev.pos_y)) {
            int oszlop = (ev.pos_x - _x) / 100;
            if (oszlop >= 0 && oszlop < 7) {
                _kattintas_callback(oszlop);
            }
        }
    }
}

void PalyaWidget::set_mezo(int oszlop, int sor, int ertek) {
    _tabla[oszlop][sor] = ertek;
}