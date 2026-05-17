#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include <vector>

class Widget;
class PalyaWidget;
class StatuszWidget;

class JatekMester {
    std::vector<Widget*> _widgetek;
    PalyaWidget* _palya;
    StatuszWidget* _statusz;

    int _tabla[7][6];
    int _kovetkezo_jatekos;
    int _allapot;

    bool ellenoriz_nyeres(int o, int s);
    bool ellenoriz_tele();
    void lepes_probal(int oszlop);
    void allapot_frissites();

public:
    JatekMester();
    ~JatekMester();
    void run();
};

#endif