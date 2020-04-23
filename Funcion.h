#include <iostream>
#include "Hora.h"

using namespace std;

class Funcion
{
  public:
  Funcion();
  Funcion(string, int, Hora, int);
  void setCveFuncion (string c) {cveFuncion=c;};
  string getCveFuncion() {return cveFuncion;};
  void setNumPeli(int n) {numPeli=(n >0 ? n :0);};
  int getNumPeli() {return numPeli;};
  void setHora(Hora h) {hora=h;};
  Hora getHora() {return hora;};
  void setSala(int s) {sala=(s >0 ? s :0);};
  int getSala() {return sala;};
  void muestra();
  private:
  Hora hora;
  int numPeli, sala;
  string cveFuncion;
};
