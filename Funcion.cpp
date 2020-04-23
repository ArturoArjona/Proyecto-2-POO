#include <iostream>
#include "Funcion.h"

using namespace std;

Funcion::Funcion()
{
  Hora h;
  cveFuncion= "La Pelicula";
  numPeli=0;
  hora=h;
  sala=0;
}

Funcion::Funcion(string c, int n, Hora h, int s)
{
  cveFuncion=c;
  numPeli=(n >0 ? n : 0);
  hora=h;
  sala=(s >0 ? s : 0);
}

Funcion::muestra()
{
  cout << "La funcion "<< numPeli << " de " << cveFuncion << " es en la sala "
  << sala << " a las ";
  hora.muestra();
}
