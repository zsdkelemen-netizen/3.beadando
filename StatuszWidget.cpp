#include "StatuszWidget.hpp"

using namespace genv;

StatuszWidget::StatuszWidget(int x, int y, int sz, int m) : Widget(x, y, sz, m), _szoveg("Jatek indul!") {}

void StatuszWidget::rajzol() const {
    gout << move_to(_x, _y) << color(30, 30, 30) << box(_sz, _m);
    int t_w = gout.twidth(_szoveg);
    gout << move_to(_x + _sz/2 - t_w/2, _y + _m/2 + 5) << color(255, 255, 255) << text(_szoveg);
}

void StatuszWidget::kezel(event ev) {
}

void StatuszWidget::set_szoveg(std::string sz) {
    _szoveg = sz;
}