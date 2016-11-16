class Materia
{
public:
    Materia();
    Materia(int Clave, string Nombre);
    int getClave();
    string getNombre();
    void setClave(int Clave);
    void setNombre(string Nombre);
    void muestra();

private:
    int Clave;
    string Nombre;
};

Materia :: Materia()
{
    Clave = 0;
    Nombre = "MATERIA SIN NOMBRE";
}

Materia :: Materia(int Clave, string Nombre)
{
    this -> Clave = Clave;
    this -> Nombre = Nombre;
}

int Materia :: getClave()
{
    return Clave;
}

string Materia :: getNombre()
{
    return Nombre;
}

void Materia :: setClave(int Clave)
{
    this -> Clave = Clave;
}

void Materia :: setNombre(string Nombre)
{
    this -> Nombre = Nombre;
}

void Materia :: muestra()
{
    cout << "La clave de la materia es: " << Clave <<endl;
    cout << "El nombre de la materia es: " << Nombre <<endl;
}
