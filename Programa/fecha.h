
class FechaCorto
{
public:
    FechaCorto();
    FechaCorto(int mm, int aa);
    int getmm();
    int getaa();
    void setmm(int mm);
    void setaa(int aa);
    void muestra();

private:
    int mm;
    int aa;
};

FechaCorto :: FechaCorto()
{
    mm = 0;
    aa = 0;
}

FechaCorto :: FechaCorto(int mm, int aa)
{
    this -> mm = mm;
    this -> aa = aa;
}

int FechaCorto :: getmm()
{
    return mm;
}

int FechaCorto :: getaa()
{
    return aa;
}

void FechaCorto :: setaa(int aa)
{
    this -> aa = aa;
}

void FechaCorto :: setmm(int mm)
{
    this -> mm = mm;
}

void FechaCorto::muestra()
{
    if(mm<10)
        cout << "0" << mm << "/" << aa << endl;
    else
        cout << mm << "/" << aa << endl;
}
