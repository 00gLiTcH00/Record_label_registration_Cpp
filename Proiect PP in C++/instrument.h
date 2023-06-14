#include <iostream>
#include <string>
using namespace std;

class instrument
{
protected:
    string nume_instrument;
    string nr_identificare;
    string cheie_muzicala;
public:
    instrument();
    instrument(string,string,string);
    string &getNumeInstrument();
    string &getNrIdentificare();
    string &getCheieMuzicala();
};
instrument::instrument()
{
    this->nume_instrument = "gol";
    this->nr_identificare="gol";
    this->cheie_muzicala="gol";
}
instrument::instrument(string nume_instrument,string nr_identificare,string cheie_muzicala)
{
    this->nume_instrument = nume_instrument;
    this->nr_identificare=nr_identificare;
    this->cheie_muzicala=cheie_muzicala;
}
string &instrument::getNumeInstrument()
{
    return nume_instrument;
}
string &instrument::getCheieMuzicala()
{
  return cheie_muzicala;
}
string &instrument::getNrIdentificare()
{
  return nr_identificare;
}