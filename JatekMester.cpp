#include "JatekMester.hpp"
#include "PalyaWidget.hpp"
#include "StatuszWidget.hpp"
#include "graphics.hpp"

using namespace genv;

JatekMester::JatekMester() : _kovetkezo_jatekos(1), _allapot(0) {
    for (int o = 0; o < 7; ++o) {
        for (int s = 0; s < 6; ++s) {
            _tabla[o][s] = 0;
        }
    }

    _statusz = new StatuszWidget(0, 0, 700, 100);

    _palya = new PalyaWidget(0, 100, 700, 600, [this](int oszlop) {
        this->lepes_probal(oszlop);
    });

    _widgetek.push_back(_statusz);
    _widgetek.push_back(_palya);

    allapot_frissites();
}

JatekMester::~JatekMester() {
    for (Widget* w : _widgetek) {
        delete w;
    }
}

void JatekMester::lepes_probal(int oszlop) {
    if (_allapot != 0) return;

    for (int s = 5; s >= 0; --s) {
        if (_tabla[oszlop][s] == 0) {
            _tabla[oszlop][s] = _kovetkezo_jatekos;
            _palya->set_mezo(oszlop, s, _kovetkezo_jatekos);

            if (ellenoriz_nyeres(oszlop, s)) {
                _allapot = _kovetkezo_jatekos;
            } else if (ellenoriz_tele()) {
                _allapot = 3;
            } else {
                _kovetkezo_jatekos = (_kovetkezo_jatekos == 1) ? 2 : 1;
            }

            allapot_frissites();
            break;
        }
    }
}

bool JatekMester::ellenoriz_nyeres(int o, int s) {
    int jatekos = _tabla[o][s];
    int dx[] = {1, 0, 1, 1};
    int dy[] = {0, 1, 1, -1};

    for (int dir = 0; dir < 4; ++dir) {
        int szamlalo = 1;

        for (int lepes = 1; lepes <= 3; ++lepes) {
            int nx = o + dx[dir] * lepes;
            int ny = s + dy[dir] * lepes;
            if (nx >= 0 && nx < 7 && ny >= 0 && ny < 6 && _tabla[nx][ny] == jatekos) szamlalo++;
            else break;
        }

        for (int lepes = 1; lepes <= 3; ++lepes) {
            int nx = o - dx[dir] * lepes;
            int ny = s - dy[dir] * lepes;
            if (nx >= 0 && nx < 7 && ny >= 0 && ny < 6 && _tabla[nx][ny] == jatekos) szamlalo++;
            else break;
        }

        if (szamlalo >= 4) return true;
    }
    return false;
}

bool JatekMester::ellenoriz_tele() {
    for (int o = 0; o < 7; ++o) {
        if (_tabla[o][0] == 0) return false;
    }
    return true;
}

void JatekMester::allapot_frissites() {
    if (_allapot == 1) _statusz->set_szoveg("Piros Nyert!");
    else if (_allapot == 2) _statusz->set_szoveg("Sarga Nyert!");
    else if (_allapot == 3) _statusz->set_szoveg("Dontetlen!");
    else if (_kovetkezo_jatekos == 1) _statusz->set_szoveg("Kovetkezik: Piros");
    else _statusz->set_szoveg("Kovetkezik: Sarga");
}

void JatekMester::run() {
    gout.open(700, 700);
    gin.timer(20);
    event ev;

    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_timer) {
            gout << move_to(0, 0) << color(0, 0, 0) << box(700, 700);
            for (Widget* w : _widgetek) {
                w->rajzol();
            }
            gout << refresh;
        }
        for (Widget* w : _widgetek) {
            w->kezel(ev);
        }
    }
}