#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <string.h>
#include <strings.h>
#include "Librotxt.h"
#include "Autor.h"
#include "subject.h"

int convInt(string sClave)
{
    int d = 0;
    for(int iA = 0; iA < sClave.length(); iA++)
        d = d*10+sClave[iA] - '0';
    return d;
}

bool ExisteAutor(int ID, Autor arrAutor[], int iContAutor)
{
    for(int i=0; i<iContAutor; i++)
    {
        if(arrAutor[i].getId() == ID)
            return true;
    }
    return false;
}

int main()
{
    LibroTexto arrLibros[30];
    Materia arrMateria[5];
    Autor arrAutor[15];
    FechaCorto fFecha;
    FechaCorto FFF;

    ifstream ArchivoMaterias;
    string sNombreMat, sNombreAutor, sTituloLibro, sISBN, TITU, TITULO, TituloHecho;
    int iCont = 0, iClave = 0, iError, iMenu, iIDAutor, iMes, iAnio, iNumLibro, iClaveMatAut, ID=0, iCantAut=0, iContLibro=0, iContAutor=0, aaa, mmm, iAA, iAUTOR, IIDD, iCO=0, iCLAVEEE;

    //Obtiene los datos del archivo de materias y los pone en las variables de clave y nombre de las materias
    ArchivoMaterias.open("Materias.txt");
            while(!ArchivoMaterias.eof())
                  {
                      ArchivoMaterias >> iClave;
                      arrMateria[iCont].setClave(iClave);
                      ArchivoMaterias.ignore();
                      getline(ArchivoMaterias, sNombreMat);
                      arrMateria[iCont].setNombre(sNombreMat);
                      iCont++;
                  }
    ArchivoMaterias.close();

    do{
        do{
        //Pide la accion que el usuario quiere realizar
        iError=0;
        cout << endl << "Elige la opcion que quieres accesar " << endl << endl;
        cout << "1. Dar de alta un autor " << endl;
        cout << "2. Dar de alta un libro " << endl;
        cout << "3. Listado de materias " << endl;
        cout << "4. Listado de autores " << endl;
        cout << "5. Listado de libros " << endl;
        cout << "6. Consulta de libros por materia " << endl;
        cout << "7. Consulta de libros por autor " << endl;
        cout << "8. Consulta de libros por anio de publicacion " << endl;
        cout << "9. Terminar " << endl;
        cin >> iMenu;
        if(iMenu<1 or iMenu >9)
        {
            cout << endl << "Elige bien la opcion que quieres " << endl << endl;
            iError=1;
        }
        }while(iError==1);

        //Dependiendo de lo que el usuario eligió, se mandan a llamar las funciones
        switch(iMenu)
        {
        case 1:
            do{
            cout << "La clave de la materia es: " << endl;
            cin >> iClaveMatAut;
            }while(iClaveMatAut!=arrMateria[0].getClave() and iClaveMatAut!=arrMateria[1].getClave() and iClaveMatAut!=arrMateria[2].getClave() and iClaveMatAut!=arrMateria[3].getClave() and iClaveMatAut!=arrMateria[4].getClave());
            cout << "El ID del autor es: " << endl;
            cin >> iIDAutor;
            cout << "El nombre del autor es: " << endl;
            cin.ignore();
            getline(cin, sNombreAutor);
            //Son de la clase autor
            arrAutor[iContAutor].setNombre(sNombreAutor);
            arrAutor[iContAutor].setId(iIDAutor);
            arrAutor[iContAutor].setClave(iClaveMatAut);
            iContAutor++;
            break;

        case 2:
            do{
            cout <<"Cual es la cantidad de autores del libro? " << endl;
            cin >> iCantAut;
            if(iCantAut > iContAutor)
                cout << "No hay suficientes autores dados de alta" << endl << endl;
            }while(iCantAut > iContAutor);
            do{
                        cout << "El ID del autor es: " << endl;
                        cin >> ID;
                        if(ExisteAutor(ID, arrAutor, iContAutor))
                        {
                            arrLibros[iContLibro].agregaAutor(ID);
                            iCantAut--;
                        }
            }while(iCantAut>0);
            cin.ignore();
            cout << "El titulo del libro es: " << endl;
            getline(cin, sTituloLibro);
            cout << "El ISBN del libro es: " << endl;
            getline(cin, sISBN);
            do{
            cout << "La fecha de publicacion(mm/aaaa) es: " << endl;
            cin >> iMes >> iAnio;
            }while(iMes<1 or iMes>12);
            cout << endl << "Autor dado de alta" << endl << endl;
            //Son de la clase fechacorto
            fFecha.setmm(iMes);
            fFecha.setaa(iAnio);
            //Son de la clase librotexto
            arrLibros[iContLibro].settitulo(sTituloLibro);
            arrLibros[iContLibro].setisbn(sISBN);
            arrLibros[iContLibro].setfecha(fFecha);
            iContLibro++;
            break;

        case 3:
            cout<< endl << "MATERIAS" << endl << endl;
            for(int i=0; i<5; i++)
            {
                cout << endl << "Materia " << i+1 << " " << endl;
                arrMateria[i].muestra();
            }
            break;

        case 4:
            cout << endl << "AUTORES" << endl << endl;
            for(int i=0; i<iContAutor; i++)
            {
                cout << endl << "Autor " << i+1 << " " << endl;
                arrAutor[i].muestra();
            }
            break;

        case 5:
            cout << endl << "LIBROS" << endl << endl;
            for(int i=0; i<iContLibro; i++)
            {
                if(arrLibros[i].Existe(sTituloLibro))
                    arrLibros[i].muestra();
            }
            break;

        case 6:
            do{
            cout << "La clave de la materia es: " << endl;
            cin >> iCLAVEEE;
            }while(iCLAVEEE!=arrMateria[0].getClave() and iCLAVEEE!=arrMateria[1].getClave() and iCLAVEEE!=arrMateria[2].getClave() and iCLAVEEE!=arrMateria[3].getClave() and iCLAVEEE!=arrMateria[4].getClave());
            cout << endl << "Los libros de esta materia son: " << endl;
                 for(int j=0; j<iContLibro; j++)
                 {
                     for(int k=0; k<iContAutor; k++)
                     {
                          if(arrAutor[k].getClave()==iCLAVEEE)
                          {
                              for(int l=0; l<10; l++)
                              {
                                   if((arrAutor[k].getId())==(arrLibros[j].getlistaAutores(l)))
                                   {
                                        TITULO = arrLibros[j].gettitulo();
                                        if(TITULO!=TituloHecho)
                                        {
                                             TituloHecho=TITULO;
                                             cout << endl << "- " << TITULO << endl << endl;
                                        }
                                   }
                              }
                          }
                     }
                 }

            break;

        case 7:
            iNumLibro=0;
            cin.ignore();
            do{
            cout << "El ID del autor es: " << endl;
            cin >> iAUTOR;
            }while(!ExisteAutor(iAUTOR, arrAutor, iContAutor));
            cout << endl << "Estos son los libros de el autor: " << endl << endl;
            for(int i=0; i<iContLibro; i++)
            {
                for(int k=0; k<iContAutor; k++)
                {
                    if(iAUTOR==arrLibros[i].getlistaAutores(k))
                    {
                         TITULO = arrLibros[i].gettitulo();
                         cout << endl << "Libro " << iNumLibro+1 << ": " << TITULO << endl << endl;
                         iNumLibro++;
                    }
                }
            }
            break;

        case 8:
            cout << "Que anio de libros quieres que te muestre? " << endl;
            cin >> iAA;
            cout << endl << "En este anio se publicaron: " << endl << endl;
            for(int i=0; i<iContLibro; i++)
            {
                FFF=arrLibros[i].getfecha();
                aaa=FFF.getaa();
                mmm=FFF.getmm();
                if(iAA==aaa)
                {
                    TITU = arrLibros[i].gettitulo();
                    cout << endl << "'" << TITU << "'" <<", publicado en el mes: " << mmm << endl;
                }
            }
            break;

        case 9:
            break;
        }

    }while(iMenu != 9);
    return 0;
}
