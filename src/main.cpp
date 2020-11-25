#include <iostream>

using namespace std;

class Bautura{
    public:
        string brand;
        int cantitate;
        string regiune;

        void print();

        Bautura() {}
        Bautura(string, int, string);
        Bautura& operator=(const Bautura&);
};

class BAlcoolica: public Bautura {
    public:
        int volum;

        void print();

        BAlcoolica() {}
        BAlcoolica(string, int, string, int);
        BAlcoolica(const BAlcoolica&);
        BAlcoolica& operator=(const BAlcoolica&);
};

void Bautura::print(){cout << brand << ", " << cantitate << " ml, tara de provenienta: " << regiune << endl;}

Bautura::Bautura(string b, int c, string r):brand(b), cantitate(c), regiune(r) {}

Bautura& Bautura::operator=(const Bautura& rhs){
    if (this == &rhs) { //identity test
        return *this;   //item 11
    }
    brand = rhs.brand;  //item 12
    cantitate = rhs.cantitate;
    regiune = rhs.regiune;
    return *this; //item 10
}


void BAlcoolica::print(){cout << brand << ", " << volum << "% alc, " << cantitate << " ml, tara de provenienta: " << regiune << endl;}

BAlcoolica::BAlcoolica(string b, int c, string r, int vol): Bautura(b, c, r), volum(vol) {}

BAlcoolica::BAlcoolica(const BAlcoolica& rhs): Bautura(rhs), volum(rhs.volum) {}

BAlcoolica& BAlcoolica::operator=(const BAlcoolica& rhs) {
    if (this == &rhs) { //item 11
        return *this;
    }
    Bautura::operator=(rhs); //item 12
    volum = rhs.volum;
    return *this;
}


int main(){
    Bautura b1("Cola", 2500, "SUA");
    Bautura b2("Burn", 330, "SUA");
    Bautura b3("Borsec", 2000, "Romania");
    Bautura b4("Dr Pepper", 330, "SUA");

    b1.print(); b2.print(); b3.print(); b4.print(); cout << endl;

    b1 = b2 = b3; //item 10
    b1.print(); b2.print(); b3.print(); b4.print(); cout << endl;

    //cout << "b4 = b4:" << endl; //item 11
    b4 = b4; //item 11

    BAlcoolica ba1("Absolut", 1000, "Suedia", 40);
    BAlcoolica ba2;
    BAlcoolica ba3("Saniuta", 500, "Romania", 28);

    ba1.print();
    cout << endl;

    ba2 = ba1 ; //item 12
    ba2.print();
    cout << endl;
    
    ba3.print();
    ba3 = ba1; //item 12
    ba3.print();

    return 0;
}
