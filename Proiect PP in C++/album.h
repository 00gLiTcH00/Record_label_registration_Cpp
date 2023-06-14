#include <iostream>
#include <string>
#include "muzician.h"
#include "instrument.h"
using namespace std;




class album : public muzician, public instrument
{
protected:
    string nume_album;
    string copyright;
    string cod_album;
    string data;
    string format;
public:
    album(); 
    album(string,string,string,string,string,string,string,string,string,string,string,string);
    string &getNumeAlbum();
    string &getCopyright();
    string &getCodAlbum();
    string &getData();
    string &getFormat();
    friend istream& operator >>(istream &, album &);
    friend ostream& operator <<(ostream &, const album &);
    bool operator <(const album &) const;
};

album::album()
{
    this->nume_album = "gol";
    this->copyright = "gol";
    this->cod_album = "gol";
    this->data = "gol";
    this->format = "gol";
    
}
album::album(string nume_album, string copyright, string cod_album, string data, string format, string nume_si_prenume, string cnp, string adresa, string telefon, string nume_instrument, string nr_identificare, string cheie_muzicala) : muzician(nume_si_prenume,cnp,adresa,telefon), instrument(nume_instrument,nr_identificare,cheie_muzicala)
{
    this->nume_album = nume_album;
    this->copyright = copyright;
    this->cod_album = cod_album;
    this->data = data;
    this->format = format;
}
string &album::getNumeAlbum()
{
    return nume_album;
}
string &album::getCopyright()
{
  return copyright;
}
string &album::getCodAlbum()
{
  return cod_album;
}
string &album::getData()
{
  return data;
}
string &album::getFormat()
{
  return format;
}

istream& operator >>(istream &is, album &a)
{   
    SetColor(13);
    cout << "Introduceti numele albumului: ";
    char aux1[100];
    is.getline(aux1, 100);
    a.getNumeAlbum() = aux1;
    
    SetColor(10);
    cout << "Introduceti drepturile de autor: ";
    char aux2[100];
    is.getline(aux2, 100);
    a.getCopyright() = aux2;

    SetColor(13);
    cout << "Introduceti codul albumului: ";
    char aux3[100];
    is.getline(aux3, 100);
    a.getCodAlbum() = aux3;
    
    SetColor(10);
    cout << "Introduceti data inregitrarii albumului: ";
    char aux4[100];
    is.getline(aux4, 100);
    a.getData() = aux4;

    SetColor(13); 
    cout << "Introduceti formatul albumului: ";
    char aux5[100];
    is.getline(aux5, 100);
    a.getFormat() = aux5;
    
    SetColor(10);
    cout << "Introduceti numele muzicianului care a inregistrat albumul: ";
    char aux6[100];
    is.getline(aux6, 100);
    a.getNumeMuzician() = aux6;
    
    SetColor(13);
    cout << "Introduceti cnp-ul muzicianului: ";
    char aux7[100];
    is.getline(aux7, 100);
    a.getCnp() = aux7;
    
    SetColor(10);
    cout << "Introduceti adresa locuintei muzicianului: ";
    char aux8[100];
    is.getline(aux8, 100);
    a.getAdresa() = aux8;
    
    SetColor(13);
    cout << "Introduceti numarul de telefon al muzicianului: ";
    char aux9[100];
    is.getline(aux9, 100);
    a.getTelefon() = aux9;
     
    SetColor(10);
    cout << "Introduceti numele instrumentului: ";
    char aux10[100];
    is.getline(aux10, 100);
    a.getNumeInstrument() = aux10;

    SetColor(13);
    cout << "Introduceti numarul de indentificare al instrumentului: ";
    char aux11[100];
    is.getline(aux11, 100);
    a.getNrIdentificare() = aux11;
       
    SetColor(10);
    cout << "Introduceti cheia muzicala a instrumentului: ";
    char aux12[100];
    is.getline(aux12, 100);
    a.getCheieMuzicala() = aux12;
  
    return is;
}

bool album::operator <(const album &a) const
{
    return this->nume_album < a.nume_album;
}

ostream& operator <<(ostream &os, const album &a)
{
    SetColor(15);
    os<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    SetColor(4);
    os<<"\t\tNUME ALBUM | COPYRIGHT | COD ALBUM | DATA | FORMAT \n";
    os << "\t\t"<<a.nume_album << "|" << a.copyright << "|" << a.cod_album << "|" << a.data << "|" << a.format << endl;
    os<<endl;
    SetColor(5);
    os<<"\t\tNUME SI PRENUME | CNP | ADRESA | TELEFON | COD ALBUM | INSTRUMENT \n";
    os << "\t\t"<<a.nume_si_prenume << "|" << a.cnp << "|" << a.adresa << "|" << a.telefon << "|" << a.cod_album << "|" << a.nume_instrument << endl;
    os<<endl;
    SetColor(3);
    os<<"\t\tNUME INSTRUMENT | NUMAR IDENTIFICARE | CHEIE MUZICALA \n";
    os <<"\t\t"<< a.nume_instrument << "|" << a.nr_identificare << "|" << a.cheie_muzicala << endl;
    SetColor(15);
    os<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    return os;
}


