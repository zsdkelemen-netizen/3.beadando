#ifndef PALYAWIDGET_HPP
#define PALYAWIDGET_HPP

#include "Widget.hpp"
#include <vector>
#include <functional>

class PalyaWidget : public Widget {
    std::vector<std::vector<int>> _tabla;
    std::function<void(int)> _kattintas_callback;
public:
    PalyaWidget(int x, int y, int sz, int m, std::function<void(int)> cb);

    void rajzol() const override;
    void kezel(genv::event ev) override;

    void set_mezo(int oszlop, int sor, int ertek);
};

#endif