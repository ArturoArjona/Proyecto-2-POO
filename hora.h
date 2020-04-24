#include <iostream>

using namespace std;

class Hora
{
  public:
  Hora();
  Hora(int h, int m);
  void setHh(int h) {hh=(h >= 0 && h<24 ? h : 0);};
  int getHh() {return hh;};
  void setMm (int m) {mm=(m >= 0 && m<60 ? m : 0);};
  int getMm() {return mm;};
  void muestra();
  private:
  int hh, mm;
};
