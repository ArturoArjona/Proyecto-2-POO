#include <iostream>


class Actor
{
  public
  Actor();
  Actor(int i, string n);
  void setId(int i) {id=(i>0 ? i : 0);};
  int getId() {return id;};
  void setNombre(string n) {nombre=n;};
  string getNombre() {return nombre;};
  void muestra();
  private
  int id;
  string nombre;
};
