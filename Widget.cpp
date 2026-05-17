#include "Widget.hpp"

Widget::Widget(int x, int y, int sz, int m) : _x(x), _y(y), _sz(sz), _m(m) {}

bool Widget::felette(int mx, int my) const {
    return mx >= _x && mx <= _x + _sz && my >= _y && my <= _y + _m;
}