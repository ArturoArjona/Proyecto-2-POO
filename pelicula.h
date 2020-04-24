#include <iostream>
#include "Actor.h"

using namespace std;

class Pelicula
{
  public:
  Pelicula();
  void setNumPeli(int n) {numPeli=(n >0 ? n :0);};
  int getNumPeli() {return numPeli;};
  void setTitulo(string t) {titulo=t;};
  string getTitulo() {return titulo;};
  void setAnio(int a) {anio=(a >0 ? a :0);};
  int getAnio() {return anio;};
  void setDuracion(int d) {duracion=(d >0 ? d :0);};
  int getDuracion() {return duracion;};
  void setGenero(string g) {genero=g;};
  string getGenero() {return genero;};
  Actor getListaActores(int);
  bool agregarActor(Actor);
  int getCantActores() {return cantActores;};
  private:
  int numPeli, anio, duracion, cantActores;
  string titulo, genero;
  Actor listaActores[10];
};
