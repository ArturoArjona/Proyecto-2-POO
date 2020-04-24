#include <iostream>
#include "Hora.h"

using namespace std;

Hora::Hora()
{
  hh=0;
  mm=0;
}

Hora::Hora(int h, int m)
{
  hh=(h >= 0 && h<24 ? h : 0);
  mm=(m >= 0 && h<60 ? m : 0);
}

void Hora::muestra()
{
  cout << hh << ":"<< mm << endl; 
}
