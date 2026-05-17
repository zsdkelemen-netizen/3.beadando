#ifndef STATUSZWIDGET_HPP
#define STATUSZWIDGET_HPP

#include "Widget.hpp"
#include <string>

class StatuszWidget : public Widget {
    std::string _szoveg;
public:
    StatuszWidget(int x, int y, int sz, int m);

    void rajzol() const override;
    void kezel(genv::event ev) override;

    void set_szoveg(std::string sz);
};

#endif