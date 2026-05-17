#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class Widget {
protected:
    int _x, _y, _sz, _m;
public:
    Widget(int x, int y, int sz, int m);
    virtual ~Widget() {}

    virtual void rajzol() const = 0;
    virtual void kezel(genv::event ev) = 0;

    virtual bool felette(int mx, int my) const;
};

#endif