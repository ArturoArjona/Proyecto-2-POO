#include <iostream>
#include "Actor.h"

using namespace std;

Actor::Actor()
{
  id=0;
  nombre="John Doe";
}

Actor::Actor(int i, string n)
{
  id=(i>0 ? i:0);
  nombre=n;
}

Actor::muestra()
{
  cout << "El actor con id " << id << " se llama "<< nombre << endl; 
}
