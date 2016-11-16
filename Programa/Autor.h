class Autor
{
public:
    Autor();
    Autor(int Id, string Nombre, int ClaveMateria);
    int getId();
    string getNombre();
    int getClave();
    void setId(int Id);
    void setNombre(string Nombre);
    void setClave(int ClaveMateria);
    void muestra();

private:
    int Id, ClaveMateria;
    string Nombre;
};

Autor :: Autor()
{
    Id = 0;
    Nombre = "AUTOR SIN NOMBRE";
    ClaveMateria = 0;
}

Autor :: Autor(int Id, string Nombre, int ClaveMateria)
{
    this -> Id = Id;
    this -> Nombre = Nombre;
    this -> ClaveMateria = ClaveMateria;
}

int Autor :: getId()
{
    return Id;
}

string Autor :: getNombre()
{
    return Nombre;
}

int Autor :: getClave()
{
    return ClaveMateria;
}

void Autor :: setId(int Id)
{
    this -> Id = Id;
}

void Autor :: setNombre(string Nombre)
{
    this -> Nombre = Nombre;
}

void Autor :: setClave(int ClaveMateria)
{
    this -> ClaveMateria = ClaveMateria;
}

void Autor :: muestra()
{
    cout << "El nombre del autor es: " << Nombre << endl;
    cout << "La clave de la materia es: " << ClaveMateria << endl;
    cout << "El ID del autor es: " << Id << endl;
}
