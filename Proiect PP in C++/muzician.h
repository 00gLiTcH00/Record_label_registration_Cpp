#include <iostream>
#include <string>
using namespace std;

class muzician
{ 
protected:
    string nume_si_prenume;
    string cnp;
    string adresa;
    string telefon;
public:
    muzician();
    muzician(string,string,string,string);
    string &getNumeMuzician();
    string &getCnp();
    string &getAdresa();
    string &getTelefon();
};
muzician::muzician()
{
    this->nume_si_prenume = "gol";
    this->cnp="gol";
    this->adresa="gol";
    this->telefon="gol";
}
muzician::muzician(string nume_si_prenume,string cnp,string adresa,string telefon)
{
    this->nume_si_prenume = nume_si_prenume;
    this->cnp = cnp;
    this->adresa = adresa;
    this->telefon = telefon;
}
string &muzician::getNumeMuzician()
{
    return nume_si_prenume;
}
string &muzician::getCnp()
{
    return cnp;
}
string &muzician::getAdresa()
{
  return adresa;
}
string &muzician::getTelefon()
{
  return telefon;
}
