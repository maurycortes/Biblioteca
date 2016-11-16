#include "fecha.h"
class LibroTexto
{
public:
    LibroTexto();
    FechaCorto getfecha();
    string gettitulo();
    string getisbn();
    void settitulo(string titulo);
    void setisbn(string isbn);
    void setfecha(FechaCorto fechaPublicacion);
    int getlistaAutores(int iNum);
    bool agregaAutor(int ID);
    int getCantAut();
    void muestra();
    bool Existe(string titulo);

private:
    string titulo, isbn;
    FechaCorto fechaPublicacion;
    int iCantAutores;
    int iListaAutores[10];
};
LibroTexto::LibroTexto()
{
    titulo = "SIN TITULO";
    isbn = "SIN ISBN";
    FechaCorto F1;
    fechaPublicacion = F1;
    iCantAutores = 0;
    for (int iA = 0; iA < 10; iA++)
    {
        iListaAutores[iA] = 0;
    }
}
FechaCorto LibroTexto::getfecha()
{
    return fechaPublicacion;
}
string LibroTexto::gettitulo()
{
    return titulo;
}
string LibroTexto::getisbn()
{
    return isbn;
}
void LibroTexto::settitulo(string titulo)
{
    this -> titulo = titulo;
}
void LibroTexto::setisbn(string isbn)
{
    this -> isbn = isbn;
}
void LibroTexto::setfecha(FechaCorto(fechaPublicacion))
{
    this -> fechaPublicacion = fechaPublicacion;
}
int LibroTexto::getlistaAutores(int iNum)
{
    return iListaAutores[iNum];
}
bool LibroTexto::agregaAutor(int ID)
{
    bool bValue = true;

    for (int iA = 0 ; iA < iCantAutores; iA++)
    {
        if (iListaAutores[iA] == ID)
        {
            return false;
        }
    }
    if (iCantAutores >= 10)
    {
        return false;
    }
    if (bValue)
    {
        iListaAutores[iCantAutores] = ID;
        iCantAutores++;
        return true;
    }
    return false;
}
int LibroTexto::getCantAut()
{
    return iCantAutores;
}

void LibroTexto::muestra()
{
    cout<< endl << "El titulo del libro es: "<<titulo<<endl;
    cout<<"El ISBN del libro es: "<< isbn <<endl;
    for (int iA = 0; iA < iCantAutores; iA++)
    {
        cout << "El ID del Autor " << iA+1 << " es: ";
        cout<<iListaAutores[iA]<<endl;
    }
    cout << "La fecha de publicacion es: ";
    fechaPublicacion.muestra();
}

bool LibroTexto::Existe(string titulo)
{
    if(titulo == "SIN TITULO")
        return false;
    else
        return true;
}
