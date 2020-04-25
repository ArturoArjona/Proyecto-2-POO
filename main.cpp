#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Pelicula.h"
#include "Funcion.h"

using namespace std;

int main()
{
      Actor act[20];
      Funcion fun[20];
      Pelicula peli[20];
      ifstream actEnt;
      actEnt.open("actores.txt");
      int cont=0;
      int i;
      string n;
      while (actEnt >> i)
      {
        getline(actEnt,n);
        act[cont].setId(i);
        act[cont].setNombre(n);
        cont++;
      }
      actEnt.close();

      ifstream peliEnt;
      peliEnt.open("peliculas.txt");
      int cnt=0;
      int num, ani, dura, cant;
      string gen, titu;
      while (peliEnt >> num >> ani >> dura >> gen >> cant)
      {
        int found=-1;
        for(int x=0; x<cant; x++)
        {
          peliEnt >> i;
          for(int c=0; c<20;c++)
          {
            if(i==act[c].getId())
            {
              found=c;
            }
          }
          Actor a2=act[found];
          peli[cnt].agregarActor(a2);

        }
        getline(peliEnt, titu);
        peli[cnt].setNumPeli(num);
        peli[cnt].setAnio(ani);
        peli[cnt].setDuracion(dura);
        peli[cnt].setGenero(gen);
        peli[cnt].setTitulo(titu);
        cnt++;
      }
      peliEnt.close();

      int f;
      cout << "Cuantas funciones desea agregar?" << endl;
      cin >> f;
      for(int y=0; y<f; y++)
      {
        string cve;
        int sal, nump, h, m;
        cout << "Cual es la clave de la funcion " << y+1 << "?" << endl;
        cin >> cve;
        fun[y].setCveFuncion(cve);
        int fi=-1;
        while (fi==-1)
        {
          cout << "Cual es numero de la pelicula?" << endl;
          cin >> nump;
          for (int comp=0; comp < cnt; comp++)
          {
            if (nump==peli[comp].getNumPeli())
            {
              fun[y].setNumPeli(nump);
              fi=comp;
            }
          }
          if (fi==-1)
          {
            cout << "Este numero de pelicula no existe." << endl;
          }
        }
        cout << "Cual es la sala de la funcion?" << endl;
        cin >> sal;
        fun[y].setSala(sal);
        bool hor=false;
        do
        {
          cout << "Cual es la hora de la funcion?(Escribir las horas y minutos separados por un espacio)" << endl;
          cin >> h >> m;
          if(h>=0 && h <24 && m>=0 && m < 60)
          {
            Hora h1(h,m);
            fun[y].setHora(h1);
            hor=true;
          }
          else
          {
            cout << "La hora introducida no es valida." << endl;
          }
        } while(hor==false);
      }



      int menu=0;
      do
      {
        cout << endl;
        cout << "Seleccione la opcion que desea realizar:" << endl;
        cout << "1: Consultar la lista de actores." << endl;
        cout << "2: Consultar la lista de peliculas." << endl;
        cout << "3: Consultar la lista de funciones." << endl;
        cout << "4: Consultar funciones por hora." << endl;
        cout << "5: Consultar funciones por clave." << endl;
        cout << "6: Consultar peliculas por actor." << endl;
        cout << "7: Terminar." << endl;
        cin >> menu;

        if(menu==1)
        {
          cout << setw(10)<< "ID"<< setw(30) <<"Nombre" << endl;
          for(int print=0; print < cont; print++)
          {
            cout << setw(10)<< act[print].getId();
            cout << setw(30)<< act[print].getNombre();
            cout << endl;
          }
        }
        else if(menu==2)
        {
          cout << setw(40)<< "Titulo"<< setw(10)<<"Anio"<< setw(15)<<"Duracion"<< setw(15)<<"Genero"<< setw(25)<<"Actores"<<endl;
          for(int print=0; print < cnt; print++)
          {
            cout << setw(40)<< peli[print].getTitulo();
            cout << setw(10)<< peli[print].getAnio();
            cout << setw(15)<< peli[print].getDuracion();
            cout << setw(15)<< peli[print].getGenero();
            for(int z=0; z< peli[print].getCantActores(); z++)
            {
              Actor a1=peli[print].getListaActores(z);
              cout << setw(25)<< a1.getNombre();
            }
            cout << endl;
          }
        }
        else if(menu==3)
        {
          cout << setw(10)<<"Clave"<< setw(40)<<"Titulo"<< setw(10)<<"Sala"<< setw(10)<<"Hora"<<endl;
          for(int print=0; print < f; print++)
          {
            cout << setw(10)<< fun[print].getCveFuncion();
            bool a=false;
            int comp=0;
            while(a==false)
            {
              if(fun[print].getNumPeli()==peli[comp].getNumPeli())
              {
                cout << setw(40)<< peli[comp].getTitulo();
                a=true;
              }
              comp++;
            }
            cout << setw(10)<< fun[print].getSala();
            Hora ho=fun[print].getHora();
            cout<< setw(10);
            ho.muestra();
            cout << endl;
          }
        }
        else if(menu==4)
        {
          bool hor=false;
          int h, m;
          do
          {
            cout << "Cual es la hora que desea revisar?(Escribir las horas y minutos separados por un espacio)" << endl;
            cin >> h >> m;
            if(h>=0 && h <24 && m>=0 && m < 60)
            {
              hor=true;
            }
            else
            {
              cout << "La hora introducida no es valida." << endl;
            }
          } while(hor==false);
          cout << setw(40)<< "Titulo"<< setw(10)<<"Sala"<<endl;
          Hora hcom;
          Hora h1(h,m);
          bool hayFun=false;
          for(int z=0; z< f; z++)
          {
            hcom=fun[z].getHora();
            if(h1.getHh()==hcom.getHh() && h1.getMm()==hcom.getMm())
            {
              bool a=false;
              int comp=0;
              while(a==false)
              {
                if(fun[z].getNumPeli()==peli[comp].getNumPeli())
                {
                  cout << setw(40)<< peli[comp].getTitulo();
                  a=true;
                  hayFun=true;
                }
                comp++;
              }
              cout << setw(10)<< fun[z].getSala() << endl;
            }
          }
          if(hayFun==false)
          {
            cout<<"No hay funciones que empiecen a esa hora." << endl;
          }
        }
        else if(menu==5)
        {
          bool cv=false;
          string cve;
          int pos;
          do
          {
            cout << "Cual es clave que desea revisar?" << endl;
            cin >> cve;
            for(int x=0; x<f; x++)
            {
              if(cve==fun[x].getCveFuncion())
              {
                pos=x;
                cv=true;
              }
            }
            if(cv==false)
            {
              cout << "La clave introducida no es valida." << endl;
            }
          }while(cv==false);
          cout << setw(10)<< "Sala"<< setw(40)<<"Titulo"<< setw(10)<<"Hora"<< setw(15)<<"Duracion"<< setw(15)<<"Genero"<< setw(25)<<"Actores"<<endl;

          cout << setw(10)<< fun[pos].getSala();
          int posPeli;
          for(int x=0; x<cnt; x++)
          {
            if(fun[pos].getNumPeli()==peli[x].getNumPeli())
            {
              posPeli=x;
            }
          }
          cout << setw(40)<< peli[posPeli].getTitulo() ;
          Hora ho=fun[pos].getHora();
          ho.muestra();
          cout << setw(15)<< peli[posPeli].getDuracion();
          cout << setw(15)<< peli[posPeli].getGenero();
          for(int z=0; z< peli[posPeli].getCantActores(); z++)
          {
            Actor a1=peli[posPeli].getListaActores(z);
            cout << setw(25)<< a1.getNombre();
          }
        }
        else if (menu==6)
        {
          bool ireal=false;
          do
          {
            cout << "Cual es el ID del actor que deseas buscar?"<< endl;
            cin >>i;
            for(int x=0; x<cont; x++)
            {
              if(i==act[x].getId())
              {
                ireal=true;
              }
            }
            if(ireal==false)
            {
              cout << "El ID no es valido."<< endl;
            }
          }while(ireal==false);
          cout << setw(40)<<"Titulo"<< setw(10)<<"Anio"<<endl;
          bool peliEnc=false;
          for(int z=0; z<cnt; z++)
          {
            for(int y=0; y< peli[z].getCantActores(); y++)
            {
              Actor a1=peli[z].getListaActores(y);
              if(a1.getId()==i)
              {
                cout << setw(40)<< peli[z].getTitulo();
                cout << setw(10)<< peli[z].getAnio() <<endl;
                peliEnc=true;
              }
            }
          }
          if(peliEnc==false)
          {
            cout<<"No se encontro ninguna pelicula con este actor."<< endl;
          }
        }
        else if (menu==7)
        {
          cout << "Hasta luego" << endl;
        }
        else
        {
          cout << "Esta opcion no existe." << endl;
        }
      } while (menu != 7);

      return 0;
}
