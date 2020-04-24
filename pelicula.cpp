#include <iostream>
#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula()
{
  numPeli=0;
  titulo= "La Pelicula";
  anio=0;
  duracion=0;
  genero="N/A";
  cantActores=0;
}

Actor Pelicula::getListaActores(int l)
{
  l--;
  return listaActores[l];
}

bool Pelicula::agregarActor(Actor a)
{
  if(cantActores<10)
  {
    int found=0;
    for(int i=0; i<10; i++)
    {
      if(a.getId()==listaActores[i].getId() && 
      a.getNombre()==listaActores[i].getNombre())
      {
        found=1;
      }
    }
    if(found==0)
    {
      listaActores[cantActores].setId(a.getId());
      listaActores[cantActores].setNombre(a.getNombre());
      cantActores++;
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}
