#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

// other -----------------------------------------------------------------------------------------------------------------
void proces_de_modificare(album &a, string inlocuibil, string modificare)
{
    if(inlocuibil.compare("NUME_ALBUM") == 0)
    {
        a.getNumeAlbum() = modificare;
    }
    if(inlocuibil.compare("COPYRIGHT") == 0)
    {
        a.getCopyright() = modificare;
    }
    if(inlocuibil.compare("COD_ALBUM") == 0)
    {
        a.getCodAlbum() = modificare;
    }
    if(inlocuibil.compare("DATA") == 0)
    {
        a.getData() = modificare;
    }
    if(inlocuibil.compare("FORMAT") == 0)
    {
        a.getNumeAlbum() = modificare;
    }
    if(inlocuibil.compare("NUME_MUZICIAN") == 0)
    {
        a.getNumeMuzician() = modificare;
    }
    if(inlocuibil.compare("CNP") == 0)
    {
        a.getCnp() = modificare;
    }
    if(inlocuibil.compare("ADRESA") == 0)
    {
        a.getAdresa() = modificare;
    }
    if(inlocuibil.compare("NR_TELEFON") == 0)
    {
        a.getTelefon() = modificare;
    }
    if(inlocuibil.compare("NUME_INSTRUMENT") == 0)
    {
        a.getNumeInstrument() = modificare;
    }
    if(inlocuibil.compare("NR_INSTRUMENT") == 0)
    {
        a.getNrIdentificare() = modificare;
    }
    if(inlocuibil.compare("CHEIE_MUZICALA") == 0)
    {
        a.getCheieMuzicala() = modificare;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void afisare_albume(album &el)
{
    SetColor(15);
    cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    SetColor(4);
    cout<<"\t\tNUME ALBUM | COPYRIGHT | COD ALBUM | DATA | FORMAT \n";
    cout<< "\t\t"<<el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
    SetColor(15);
    cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void afisare_muzicieni(album &el)
{
    SetColor(15);
    cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\tNUME SI PRENUME | CNP | ADRESA | TELEFON | COD ALBUM | INSTRUMENT \n";
    cout<< "\t\t"<<el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
    SetColor(15);
    cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void afisare_instrumente(album &el)
{
    SetColor(15);
    cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    SetColor(4);
    cout<<"\t\tNUME INSTRUMENT | NUMAR IDENTIFICARE | CHEIE MUZICALA \n";
    cout<< "\t\t"<<el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << "|" << endl;
    SetColor(15);
    cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

// general -----------------------------------------------------------------------------------------------------------------
void creare_resetare_mic()
{
    fstream file_album,file_muzician,file_instrument;
    int cate_albume;
    vector<album>A;
    cout << "Cate input-uri avem?: "; cin >> cate_albume;
    cin.ignore();
    int i=0;
    while(i < cate_albume)
    {
        cout <<"Album "<<i+1<<":"<<endl;
        album a;
        cin>>a;
        A.push_back(a);
        cout << endl;
        i++;
    }
    file_album.open("album.txt",ios::out);
    file_muzician.open("muzician.txt",ios::out);
    file_instrument.open("instrument.txt",ios::out);
    if(file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        for(auto &el:A)
        {
            file_album<<el.getNumeAlbum()<<"|"<<el.getCopyright()<<"|"<<el.getCodAlbum()<<"|"<<el.getData()<<"|"<<el.getFormat()<<endl;
            file_muzician<<el.getNumeMuzician()<<"|"<<el.getCnp()<<"|"<<el.getAdresa()<<"|"<<el.getTelefon()<<"|"<<el.getCodAlbum()<<"|"<<el.getNumeInstrument()<<endl;
            file_instrument<<el.getNumeInstrument()<<"|"<<el.getNrIdentificare()<<"|"<<el.getCheieMuzicala()<<endl;
        }
        file_album.close();
        file_muzician.close();
        file_instrument.close();
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void creare_resetare_mare()
{
    fstream file_input,file_album,file_muzician,file_instrument;
    file_input.open("input.txt", ios::in);
    file_album.open("album.txt",ios::out);
    file_muzician.open("muzician.txt",ios::out);
    file_instrument.open("instrument.txt",ios::out);
    if(file_input.is_open() && file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        string line;
        while(getline(file_input,line))
        {
            vector<string>informatii;
            album a;
            stringstream sstream(line);
            string informatie;
            while(getline(sstream,informatie,'|')) 
            {
                informatii.push_back(informatie);
            }
            file_album << informatii[0] << "|" << informatii[1] << "|" << informatii[2] << "|" << informatii[3] << "|" << informatii[4] << endl;
            file_muzician << informatii[8] << "|" << informatii[9] << "|" << informatii[10] << "|" << informatii[11] << "|" << informatii[2] << "|" << informatii[5] << endl;
            file_instrument << informatii[5] << "|" << informatii[6] << "|" << informatii[7] << endl;
        }
        file_input.close();
        file_album.close();
        file_muzician.close();
        file_instrument.close();
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void afisare_generala()
{
    fstream file_album,file_muzician,file_instrument;
    file_album.open("album.txt",ios::in);
    file_muzician.open("muzician.txt",ios::in);
    file_instrument.open("instrument.txt",ios::in);
    set<album>ALBUME;
    if(file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        string line_album, line_muzician, line_instrument;
        while(getline(file_album,line_album) && getline(file_muzician,line_muzician) && getline(file_instrument,line_instrument))
        {
            
            vector<string>informatii;
            stringstream sstream_album(line_album);
            stringstream sstream_muzician(line_muzician);
            stringstream sstream_instrument(line_instrument);
            string line_a,line_m,line_i;
            while(getline(sstream_album,line_a,'|'))
            {
                informatii.push_back(line_a);
            }
            while (getline(sstream_instrument,line_i,'|'))
            {
                informatii.push_back(line_i);
            }
            while (getline(sstream_muzician,line_m,'|'))
            {
                informatii.push_back(line_m);
            }
            int k=0;
            while(k < 2)
            {
                informatii.pop_back();
                k++;
            }
            album a(informatii[0],informatii[1],informatii[2],informatii[3],informatii[4],informatii[8],informatii[9],informatii[10],informatii[11],informatii[5],informatii[6],informatii[7]);
            ALBUME.insert(a);
        }
        for(auto &el : ALBUME)
        {
            cout << el;
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void append_general_mic()
{
    fstream file_album,file_muzician,file_instrument;
    int cate_albume;
    vector<album>A;
    cout << "Cate input-uri avem?: "; cin >> cate_albume;
    cin.ignore();
    int i=0;
    while(i < cate_albume)
    {
        cout <<"Album "<<i+1<<":"<<endl;
        album a;
        cin>>a;
        A.push_back(a);
        cout << endl;
        i++;
    }
    file_album.open("album.txt",ios::app);
    file_muzician.open("muzician.txt",ios::app);
    file_instrument.open("instrument.txt",ios::app);
    if(file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        for(auto &el:A)
        {
            file_album<<el.getNumeAlbum()<<"|"<<el.getCopyright()<<"|"<<el.getCodAlbum()<<"|"<<el.getData()<<"|"<<el.getFormat()<<endl;
            file_muzician<<el.getNumeMuzician()<<"|"<<el.getCnp()<<"|"<<el.getAdresa()<<"|"<<el.getTelefon()<<"|"<<el.getCodAlbum()<<"|"<<el.getNumeInstrument()<<endl;
            file_instrument<<el.getNumeInstrument()<<"|"<<el.getNrIdentificare()<<"|"<<el.getCheieMuzicala()<<endl;
        }
        file_album.close();
        file_muzician.close();
        file_instrument.close();
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void append_general_mare()
{
    fstream file_input,file_album,file_muzician,file_instrument;
    file_input.open("input.txt", ios::in);
    file_album.open("album.txt",ios::app);
    file_muzician.open("muzician.txt",ios::app);
    file_instrument.open("instrument.txt",ios::app);
    if(file_input.is_open() && file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        string line;
        while(getline(file_input,line))
        {
            vector<string>informatii;
            album a;
            stringstream sstream(line);
            string informatie;
            while(getline(sstream,informatie,'|'))
            {
                informatii.push_back(informatie);
            }
            file_album << informatii[0] << "|" << informatii[1] << "|" << informatii[2] << "|" << informatii[3] << "|" << informatii[4] << endl;
            file_muzician << informatii[8] << "|" << informatii[9] << "|" << informatii[10] << "|" << informatii[11] << "|" << informatii[2] << "|" << informatii[5] << endl;
            file_instrument << informatii[5] << "|" << informatii[6] << "|" << informatii[7] << endl;
        }
        file_input.close();
        file_album.close();
        file_muzician.close();
        file_instrument.close();
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cautare_generala()
{
    fstream file_input,file_album,file_muzician,file_instrument;
    file_album.open("album.txt",ios::in);
    file_muzician.open("muzician.txt",ios::in);
    file_instrument.open("instrument.txt",ios::in);
    set<album>ALBUME;
    if(file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        string line_album, line_muzician, line_instrument;
        while(getline(file_album,line_album) && getline(file_muzician,line_muzician) && getline(file_instrument,line_instrument))
        {
            vector<string>informatii;
            stringstream sstream_album(line_album);
            stringstream sstream_muzician(line_muzician);
            stringstream sstream_instrument(line_instrument);
            string line_a,line_m,line_i;
            while(getline(sstream_album,line_a,'|'))
            {
                informatii.push_back(line_a);
            }
            while (getline(sstream_instrument,line_i,'|'))
            {
                informatii.push_back(line_i);
            }
            while (getline(sstream_muzician,line_m,'|'))
            {
                informatii.push_back(line_m);
            }
            int k=0;
            while(k < 2)
            {
                informatii.pop_back();
                k++;
            }
            album a(informatii[0],informatii[1],informatii[2],informatii[3],informatii[4],informatii[8],informatii[9],informatii[10],informatii[11],informatii[5],informatii[6],informatii[7]);
            ALBUME.insert(a);
        }
        file_album.close();
        file_muzician.close();
        file_instrument.close();
        string input,in1,in2;
        cout << "Introduceti comanda: ";
        cin.ignore();
        getline(cin,input);
        stringstream sstream_input(input);
        string line_input;
        vector<string>input_aux;
        while(getline(sstream_input,line_input,':'))
        {
            input_aux.push_back(line_input);
        }
        in1 = input_aux[0];
        in2 = input_aux[1];
        for(auto el : ALBUME)
        {
            if(in1.compare("NUME_ALBUM") == 0 && !el.getNumeAlbum().find(in2))
            {
                cout << el;
            }
            else
            {
                if(in1.compare("COPYRIGHT") == 0 && !el.getCopyright().find(in2))
                {
                    cout << el;
                }
                else
                {
                    if(in1.compare("COD_ALBUM") == 0 && !el.getCodAlbum().find(in2))
                    {
                        cout << el;
                    }
                    else
                    {
                        if(in1.compare("DATA") == 0 && !el.getData().find(in2))
                        {
                            cout << el;
                        }
                        else
                        {
                            if(in1.compare("FORMAT") == 0 && !el.getFormat().find(in2))
                            {
                                cout << el;
                            }
                            else
                            {
                                if(in1.compare("NUME_MUZICIAN") == 0 && !el.getNumeMuzician().find(in2))
                                {
                                    cout << el;
                                }
                                else
                                {
                                    if(in1.compare("CNP") == 0 && !el.getCnp().find(in2))
                                    {
                                        cout << el;
                                    }
                                    else
                                    {
                                        if(in1.compare("ADRESA") == 0 && !el.getAdresa().find(in2))
                                        {
                                            cout << el;
                                        }
                                        else
                                        {
                                            if(in1.compare("NR_TELEFON") == 0 && !el.getTelefon().find(in2))
                                            {
                                                cout << el;
                                            }
                                            else
                                            {
                                                if(in1.compare("NUME_INSTRUMENT") == 0 && !el.getNumeInstrument().find(in2))
                                                {
                                                    cout << el;
                                                }
                                                else
                                                {
                                                    if(in1.compare("NR_INSTRUMENT") == 0 && !el.getNrIdentificare().find(in2))
                                                    {
                                                        cout << el;
                                                    }
                                                    else
                                                    {
                                                        if(in1.compare("CHEIE_MUZICALA") == 0 && !el.getCheieMuzicala().find(in2))
                                                        {
                                                            cout << el;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void stergere_generala()
{
    fstream file_input,file_album,file_muzician,file_instrument;
    file_album.open("album.txt",ios::in);
    file_muzician.open("muzician.txt",ios::in);
    file_instrument.open("instrument.txt",ios::in);
    set<album>ALBUME;
    if(file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        char rezultat;
        string input,in1,in2;
        string line_album, line_muzician, line_instrument;
        while(getline(file_album,line_album) && getline(file_muzician,line_muzician) && getline(file_instrument,line_instrument))
        {
            vector<string>informatii;
            stringstream sstream_album(line_album);
            stringstream sstream_muzician(line_muzician);
            stringstream sstream_instrument(line_instrument);
            string line_a,line_m,line_i;
            while(getline(sstream_album,line_a,'|'))
            {
                informatii.push_back(line_a);
            }
            while (getline(sstream_instrument,line_i,'|'))
            {
                informatii.push_back(line_i);
            }
            while (getline(sstream_muzician,line_m,'|'))
            {
                informatii.push_back(line_m);
            }
            int k=0;
            while(k < 2)
            {
                informatii.pop_back();
                k++;
            }
            album a(informatii[0],informatii[1],informatii[2],informatii[3],informatii[4],informatii[8],informatii[9],informatii[10],informatii[11],informatii[5],informatii[6],informatii[7]);
            ALBUME.insert(a);
        }
        file_album.close();
        file_muzician.close();
        file_instrument.close();
        do
        {
            cout << "Introduceti comanda: ";
            cin.ignore();
            getline(cin,input);
            stringstream sstream_input(input);
            string line_input;
            vector<string>input_aux;
            while(getline(sstream_input,line_input,':'))
            {
                input_aux.push_back(line_input);
            }
            in1 = input_aux[0];
            in2 = input_aux[1];
            for(auto el : ALBUME)
            {
                if(in1.compare("NUME_ALBUM") == 0 && !el.getNumeAlbum().find(in2))
                {
                    cout << el;
                }
                else
                {
                    if(in1.compare("COPYRIGHT") == 0 && !el.getCopyright().find(in2))
                    {
                        cout << el;
                    }
                    else
                    {
                        if(in1.compare("COD_ALBUM") == 0 && !el.getCodAlbum().find(in2))
                        {
                            cout << el;
                        }
                        else
                        {
                            if(in1.compare("DATA") == 0 && !el.getData().find(in2))
                            {
                                cout << el;
                            }
                            else
                            {
                                if(in1.compare("FORMAT") == 0 && !el.getFormat().find(in2))
                                {
                                    cout << el;
                                }
                                else
                                {
                                    if(in1.compare("NUME_MUZICIAN") == 0 && !el.getNumeMuzician().find(in2))
                                    {
                                        cout << el;
                                    }
                                    else
                                    {
                                        if(in1.compare("CNP") == 0 && !el.getCnp().find(in2))
                                        {
                                            cout << el;
                                        }
                                        else
                                        {
                                            if(in1.compare("ADRESA") == 0 && !el.getAdresa().find(in2))
                                            {
                                                cout << el;
                                            }
                                            else
                                            {
                                                if(in1.compare("NR_TELEFON") == 0 && !el.getTelefon().find(in2))
                                                {
                                                    cout << el;
                                                }
                                                else
                                                {
                                                    if(in1.compare("NUME_INSTRUMENT") == 0 && !el.getNumeInstrument().find(in2))
                                                    {
                                                        cout << el;
                                                    }
                                                    else
                                                    {
                                                        if(in1.compare("NR_INSTRUMENT") == 0 && !el.getNrIdentificare().find(in2))
                                                        {
                                                            cout << el;
                                                        }
                                                        else
                                                        {
                                                            if(in1.compare("CHEIE_MUZICALA") == 0 && !el.getCheieMuzicala().find(in2))
                                                            {
                                                                cout << el;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << "Acesta este rezultatul cautat?(y/n): ";
            cin >> rezultat;
        } while(rezultat == 'n');
        file_album.open("album.txt",ios::out);
        file_muzician.open("muzician.txt",ios::out);
        file_instrument.open("instrument.txt",ios::out);
        for(auto el : ALBUME)
        {
            if(in1.compare("NUME_ALBUM") == 0 && el.getNumeAlbum().find(in2))
            {
                file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
            }
            else
            {
                if(in1.compare("COPYRIGHT") == 0 && el.getCopyright().find(in2))
                {
                    file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                    file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                    file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                }
                else
                {
                    if(in1.compare("COD_ALBUM") == 0 && el.getCodAlbum().find(in2))
                    {
                        file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                        file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                        file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                    }
                    else
                    {
                        if(in1.compare("DATA") == 0 && el.getData().find(in2))
                        {
                            file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                            file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                            file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                        }
                        else
                        {
                            if(in1.compare("FORMAT") == 0 && el.getFormat().find(in2))
                            {
                                file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                                file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                                file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                            }
                            else
                            {
                                if(in1.compare("NUME_MUZICIAN") == 0 && el.getNumeMuzician().find(in2))
                                {
                                    file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                                    file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                                    file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                                }
                                else
                                {
                                    if(in1.compare("CNP") == 0 && el.getCnp().find(in2))
                                    {
                                        file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                                        file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                                        file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                                    }
                                    else
                                    {
                                        if(in1.compare("ADRESA") == 0 && el.getAdresa().find(in2))
                                        {
                                            file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                                            file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                                            file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                                        }
                                        else
                                        {
                                            if(in1.compare("NR_TELEFON") == 0 && el.getTelefon().find(in2))
                                            {
                                                file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                                                file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                                                file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                                            }
                                            else
                                            {
                                                if(in1.compare("NUME_INSTRUMENT") == 0 && el.getNumeInstrument().find(in2))
                                                {
                                                    file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                                                    file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                                                    file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                                                }
                                                else
                                                {
                                                    if(in1.compare("NR_INSTRUMENT") == 0 && el.getNrIdentificare().find(in2))
                                                    {
                                                        file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                                                        file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                                                        file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                                                    }
                                                    else
                                                    {
                                                        if(in1.compare("CHEIE_MUZICALA") == 0 && el.getCheieMuzicala().find(in2))
                                                        {
                                                            file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
                                                            file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
                                                            file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }  
        file_album.close();
        file_muzician.close();
        file_instrument.close();    
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void modificare_generala()
{
    fstream file_input,file_album,file_muzician,file_instrument;
    file_album.open("album.txt",ios::in);
    file_muzician.open("muzician.txt",ios::in);
    file_instrument.open("instrument.txt",ios::in);
    set<album>ALBUME;
    if(file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        char rezultat;
        string input,in1,in2;
        string line_album, line_muzician, line_instrument;
        while(getline(file_album,line_album) && getline(file_muzician,line_muzician) && getline(file_instrument,line_instrument))
        {
            vector<string>informatii;
            stringstream sstream_album(line_album);
            stringstream sstream_muzician(line_muzician);
            stringstream sstream_instrument(line_instrument);
            string line_a,line_m,line_i;
            while(getline(sstream_album,line_a,'|'))
            {
                informatii.push_back(line_a);
            }
            while (getline(sstream_instrument,line_i,'|'))
            {
                informatii.push_back(line_i);
            }
            while (getline(sstream_muzician,line_m,'|'))
            {
                informatii.push_back(line_m);
            }
            int k=0;
            while(k < 2)
            {
                informatii.pop_back();
                k++;
            }
            album a(informatii[0],informatii[1],informatii[2],informatii[3],informatii[4],informatii[8],informatii[9],informatii[10],informatii[11],informatii[5],informatii[6],informatii[7]);
            ALBUME.insert(a);
        }
        file_album.close();
        file_muzician.close();
        file_instrument.close();
        do
        {
            cout << "Introduceti comanda: ";
            cin.ignore();
            getline(cin,input);
            stringstream sstream_input(input);
            string line_input;
            vector<string>input_aux;
            while(getline(sstream_input,line_input,':'))
            {
                input_aux.push_back(line_input);
            }
            in1 = input_aux[0];
            in2 = input_aux[1];
            for(auto el : ALBUME)
            {
                if(in1.compare("NUME_ALBUM") == 0 && !el.getNumeAlbum().find(in2))
                {
                    cout << el;
                }
                else
                {
                    if(in1.compare("COPYRIGHT") == 0 && !el.getCopyright().find(in2))
                    {
                        cout << el;
                    }
                    else
                    {
                        if(in1.compare("COD_ALBUM") == 0 && !el.getCodAlbum().find(in2))
                        {
                            cout << el;
                        }
                        else
                        {
                            if(in1.compare("DATA") == 0 && !el.getData().find(in2))
                            {
                                cout << el;
                            }
                            else
                            {
                                if(in1.compare("FORMAT") == 0 && !el.getFormat().find(in2))
                                {
                                    cout << el;
                                }
                                else
                                {
                                    if(in1.compare("NUME_MUZICIAN") == 0 && !el.getNumeMuzician().find(in2))
                                    {
                                        cout << el;
                                    }
                                    else
                                    {
                                        if(in1.compare("CNP") == 0 && !el.getCnp().find(in2))
                                        {
                                            cout << el;
                                        }
                                        else
                                        {
                                            if(in1.compare("ADRESA") == 0 && !el.getAdresa().find(in2))
                                            {
                                                cout << el;
                                            }
                                            else
                                            {
                                                if(in1.compare("NR_TELEFON") == 0 && !el.getTelefon().find(in2))
                                                {
                                                    cout << el;
                                                }
                                                else
                                                {
                                                    if(in1.compare("NUME_INSTRUMENT") == 0 && !el.getNumeInstrument().find(in2))
                                                    {
                                                        cout << el;
                                                    }
                                                    else
                                                    {
                                                        if(in1.compare("NR_INSTRUMENT") == 0 && !el.getNrIdentificare().find(in2))
                                                        {
                                                            cout << el;
                                                        }
                                                        else
                                                        {
                                                            if(in1.compare("CHEIE_MUZICALA") == 0 && !el.getCheieMuzicala().find(in2))
                                                            {
                                                                cout << el;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << "Acesta este rezultatul cautat?(y/n): ";
            cin >> rezultat;
        } while(rezultat == 'n');
        string inlocuibil, modificare;
        cout << "Ce inlocuim?: ";
        cin.ignore();
        getline(cin,inlocuibil);
        cout << "Cu ce inlocuim optiunea aleasa?: ";
        getline(cin,modificare);
        file_album.open("album.txt",ios::out);
        file_muzician.open("muzician.txt",ios::out);
        file_instrument.open("instrument.txt",ios::out);
        for(auto el : ALBUME)
        {
            if(in1.compare("NUME_ALBUM") == 0 && !el.getNumeAlbum().find(in2))
            {
                proces_de_modificare(el,inlocuibil,modificare);
            }
            else
            {
                if(in1.compare("COPYRIGHT") == 0 && !el.getCopyright().find(in2))
                {
                    proces_de_modificare(el,inlocuibil,modificare);
                }
                else
                {
                    if(in1.compare("COD_ALBUM") == 0 && !el.getCodAlbum().find(in2))
                    {
                        proces_de_modificare(el,inlocuibil,modificare);
                    }
                    else
                    {
                        if(in1.compare("DATA") == 0 && !el.getData().find(in2))
                        {
                            proces_de_modificare(el,inlocuibil,modificare);
                        }
                        else
                        {
                            if(in1.compare("FORMAT") == 0 && !el.getFormat().find(in2))
                            {
                                proces_de_modificare(el,inlocuibil,modificare);
                            }
                            else
                            {
                                if(in1.compare("NUME_MUZICIAN") == 0 && !el.getNumeMuzician().find(in2))
                                {
                                    proces_de_modificare(el,inlocuibil,modificare);
                                }
                                else
                                {
                                    if(in1.compare("CNP") == 0 && !el.getCnp().find(in2))
                                    {
                                        proces_de_modificare(el,inlocuibil,modificare);
                                    }
                                    else
                                    {
                                        if(in1.compare("ADRESA") == 0 && !el.getAdresa().find(in2))
                                        {
                                            proces_de_modificare(el,inlocuibil,modificare);
                                        }
                                        else
                                        {
                                            if(in1.compare("NR_TELEFON") == 0 && !el.getTelefon().find(in2))
                                            {
                                                proces_de_modificare(el,inlocuibil,modificare);
                                            }
                                            else
                                            {
                                                if(in1.compare("NUME_INSTRUMENT") == 0 && !el.getNumeInstrument().find(in2))
                                                {
                                                    proces_de_modificare(el,inlocuibil,modificare);
                                                }
                                                else
                                                {
                                                    if(in1.compare("NR_INSTRUMENT") == 0 && !el.getNrIdentificare().find(in2))
                                                    {
                                                        proces_de_modificare(el,inlocuibil,modificare);
                                                    }
                                                    else
                                                    {
                                                        if(in1.compare("CHEIE_MUZICALA") == 0 && !el.getCheieMuzicala().find(in2))
                                                        {
                                                            proces_de_modificare(el,inlocuibil,modificare);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            file_album << el.getNumeAlbum() << "|" << el.getCopyright() << "|" << el.getCodAlbum() << "|" << el.getData() << "|" << el.getFormat() << endl;
            file_muzician << el.getNumeMuzician() << "|" << el.getCnp() << "|" << el.getAdresa() << "|" << el.getTelefon() << "|" << el.getCodAlbum() << "|" << el.getNumeInstrument() << endl;
            file_instrument << el.getNumeInstrument() << "|" << el.getNrIdentificare() << "|" << el.getCheieMuzicala() << endl;
        }
        file_album.close();
        file_muzician.close();
        file_instrument.close();
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}

// albume solo -----------------------------------------------------------------------------------------------------------------
void afisare_albume_solo()
{
    fstream file_album;
    file_album.open("album.txt",ios::in);
  
    if(file_album.is_open())
    {
        string line_album;
        while(getline(file_album,line_album))
        {
            
            vector<string>informatii;
            stringstream sstream_album(line_album);
            string line_a;
            while(getline(sstream_album,line_a,'|'))
            {
                informatii.push_back(line_a);
            }
            SetColor(15);
            cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            SetColor(4);
            cout<<"\t\tNUME ALBUM | COPYRIGHT | COD ALBUM | DATA | FORMAT \n"; 
            cout<<"\t\t";
            for(auto &el : informatii)
            {
                SetColor(4);
                cout<<el<<"|";
            }
            SetColor(15);
            cout<<"\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cautare_albume_solo()
{
    fstream file_input,file_album,file_muzician,file_instrument;
    file_album.open("album.txt",ios::in);
    file_muzician.open("muzician.txt",ios::in);
    file_instrument.open("instrument.txt",ios::in);
    set<album>ALBUME;
    if(file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        string line_album, line_muzician, line_instrument;
        while(getline(file_album,line_album) && getline(file_muzician,line_muzician) && getline(file_instrument,line_instrument))
        {
            vector<string>informatii;
            stringstream sstream_album(line_album);
            stringstream sstream_muzician(line_muzician);
            stringstream sstream_instrument(line_instrument);
            string line_a,line_m,line_i;
            while(getline(sstream_album,line_a,'|'))
            {
                informatii.push_back(line_a);
            }
            while (getline(sstream_instrument,line_i,'|'))
            {
                informatii.push_back(line_i);
            }
            while (getline(sstream_muzician,line_m,'|'))
            {
                informatii.push_back(line_m);
            }
            int k=0;
            while(k < 2)
            {
                informatii.pop_back();
                k++;
            }
            album a(informatii[0],informatii[1],informatii[2],informatii[3],informatii[4],informatii[8],informatii[9],informatii[10],informatii[11],informatii[5],informatii[6],informatii[7]);
            ALBUME.insert(a);
        }
        file_album.close();
        file_muzician.close();
        file_instrument.close();
        string input,in1,in2;
        cout << "Introduceti comanda: ";
        cin.ignore();
        getline(cin,input);
        stringstream sstream_input(input);
        string line_input;
        vector<string>input_aux;
        while(getline(sstream_input,line_input,':'))
        {
            input_aux.push_back(line_input);
        }
        in1 = input_aux[0];
        in2 = input_aux[1];
        for(auto el : ALBUME)
        {
            if(in1.compare("NUME_ALBUM") == 0 && !el.getNumeAlbum().find(in2))
            {
                afisare_albume(el);
            }
            else
            {
                if(in1.compare("COPYRIGHT") == 0 && !el.getCopyright().find(in2))
                {
                    afisare_albume(el);
                }
                else
                {
                    if(in1.compare("COD_ALBUM") == 0 && !el.getCodAlbum().find(in2))
                    {
                        afisare_albume(el);
                    }
                    else
                    {
                        if(in1.compare("DATA") == 0 && !el.getData().find(in2))
                        {
                            afisare_albume(el);
                        }
                        else
                        {
                            if(in1.compare("FORMAT") == 0 && !el.getFormat().find(in2))
                            {
                                afisare_albume(el);
                            }
                            else
                            {
                                if(in1.compare("NUME_MUZICIAN") == 0 && !el.getNumeMuzician().find(in2))
                                {
                                    afisare_albume(el);
                                }
                                else
                                {
                                    if(in1.compare("CNP") == 0 && !el.getCnp().find(in2))
                                    {
                                        afisare_albume(el);
                                    }
                                    else
                                    {
                                        if(in1.compare("ADRESA") == 0 && !el.getAdresa().find(in2))
                                        {
                                            afisare_albume(el);
                                        }
                                        else
                                        {
                                            if(in1.compare("NR_TELEFON") == 0 && !el.getTelefon().find(in2))
                                            {
                                                afisare_albume(el);
                                            }
                                            else
                                            {
                                                if(in1.compare("NUME_INSTRUMENT") == 0 && !el.getNumeInstrument().find(in2))
                                                {
                                                    afisare_albume(el);
                                                }
                                                else
                                                {
                                                    if(in1.compare("NR_INSTRUMENT") == 0 && !el.getNrIdentificare().find(in2))
                                                    {
                                                        afisare_albume(el);
                                                    }
                                                    else
                                                    {
                                                        if(in1.compare("CHEIE_MUZICALA") == 0 && !el.getCheieMuzicala().find(in2))
                                                        {
                                                            afisare_albume(el);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}

// muzicieni solo -----------------------------------------------------------------------------------------------------------------
void afisare_muzicieni_solo()
{
    fstream file_muzician;
    file_muzician.open("muzician.txt",ios::in);
  
    if(file_muzician.is_open())
    {
        string line_muzician;
        while(getline(file_muzician,line_muzician))
        {
            
            vector<string>informatii;
            stringstream sstream_muzician(line_muzician);
            string line_m;
            while(getline(sstream_muzician,line_m,'|'))
            {
                informatii.push_back(line_m);
            }
            SetColor(15);
            cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            SetColor(4);
            cout<<"\t\tNUME SI PRENUME | CNP | ADRESA | TELEFON | COD ALBUM | INSTRUMENT \n"; 
            cout<<"\t\t";
            for(auto &el : informatii)
            {
                SetColor(4);
                cout<<el<<"|";
            }
            SetColor(15);
            cout<<"\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cautare_muzicieni_solo()
{
    fstream file_input,file_album,file_muzician,file_instrument;
    file_album.open("album.txt",ios::in);
    file_muzician.open("muzician.txt",ios::in);
    file_instrument.open("instrument.txt",ios::in);
    set<album>ALBUME;
    if(file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        string line_album, line_muzician, line_instrument;
        while(getline(file_album,line_album) && getline(file_muzician,line_muzician) && getline(file_instrument,line_instrument))
        {
            vector<string>informatii;
            stringstream sstream_album(line_album);
            stringstream sstream_muzician(line_muzician);
            stringstream sstream_instrument(line_instrument);
            string line_a,line_m,line_i;
            while(getline(sstream_album,line_a,'|'))
            {
                informatii.push_back(line_a);
            }
            while (getline(sstream_instrument,line_i,'|'))
            {
                informatii.push_back(line_i);
            }
            while (getline(sstream_muzician,line_m,'|'))
            {
                informatii.push_back(line_m);
            }
            int k=0;
            while(k < 2)
            {
                informatii.pop_back();
                k++;
            }
            album a(informatii[0],informatii[1],informatii[2],informatii[3],informatii[4],informatii[8],informatii[9],informatii[10],informatii[11],informatii[5],informatii[6],informatii[7]);
            ALBUME.insert(a);
        }
        file_album.close();
        file_muzician.close();
        file_instrument.close();
        string input,in1,in2;
        cout << "Introduceti comanda: ";
        cin.ignore();
        getline(cin,input);
        stringstream sstream_input(input);
        string line_input;
        vector<string>input_aux;
        while(getline(sstream_input,line_input,':'))
        {
            input_aux.push_back(line_input);
        }
        in1 = input_aux[0];
        in2 = input_aux[1];
        for(auto el : ALBUME)
        {
            if(in1.compare("NUME_ALBUM") == 0 && !el.getNumeAlbum().find(in2))
            {
                afisare_muzicieni(el);
            }
            else
            {
                if(in1.compare("COPYRIGHT") == 0 && !el.getCopyright().find(in2))
                {
                    afisare_muzicieni(el);
                }
                else
                {
                    if(in1.compare("COD_ALBUM") == 0 && !el.getCodAlbum().find(in2))
                    {
                        afisare_muzicieni(el);
                    }
                    else
                    {
                        if(in1.compare("DATA") == 0 && !el.getData().find(in2))
                        {
                            afisare_muzicieni(el);
                        }
                        else
                        {
                            if(in1.compare("FORMAT") == 0 && !el.getFormat().find(in2))
                            {
                                afisare_muzicieni(el);
                            }
                            else
                            {
                                if(in1.compare("NUME_MUZICIAN") == 0 && !el.getNumeMuzician().find(in2))
                                {
                                    afisare_muzicieni(el);
                                }
                                else
                                {
                                    if(in1.compare("CNP") == 0 && !el.getCnp().find(in2))
                                    {
                                        afisare_muzicieni(el);
                                    }
                                    else
                                    {
                                        if(in1.compare("ADRESA") == 0 && !el.getAdresa().find(in2))
                                        {
                                            afisare_muzicieni(el);
                                        }
                                        else
                                        {
                                            if(in1.compare("NR_TELEFON") == 0 && !el.getTelefon().find(in2))
                                            {
                                                afisare_muzicieni(el);
                                            }
                                            else
                                            {
                                                if(in1.compare("NUME_INSTRUMENT") == 0 && !el.getNumeInstrument().find(in2))
                                                {
                                                    afisare_muzicieni(el);
                                                }
                                                else
                                                {
                                                    if(in1.compare("NR_INSTRUMENT") == 0 && !el.getNrIdentificare().find(in2))
                                                    {
                                                        afisare_muzicieni(el);
                                                    }
                                                    else
                                                    {
                                                        if(in1.compare("CHEIE_MUZICALA") == 0 && !el.getCheieMuzicala().find(in2))
                                                        {
                                                            afisare_muzicieni(el);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}

// instrumente solo -----------------------------------------------------------------------------------------------------------------
void afisare_instrumente_solo()
{
    fstream file_instrument;
    file_instrument.open("instrument.txt",ios::in);
  
    if(file_instrument.is_open())
    {
        string line_instrument;
        while(getline(file_instrument,line_instrument))
        {
            
            vector<string>informatii;
            stringstream sstream_instrument(line_instrument);
            string line_i;
            while(getline(sstream_instrument,line_i,'|'))
            {
                informatii.push_back(line_i);
            }
            SetColor(15);
            cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            SetColor(4);
            cout<<"\t\tNUME INSTRUMENT | NUMAR IDENTIFICARE | CHEIE MUZICALA \n"; 
            cout<<"\t\t";
            for(auto &el : informatii)
            {
                SetColor(4);
                cout<<el<<"|";
            }
            SetColor(15);
            cout<<"\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    }
}

void cautare_instrumente_solo()
{
    fstream file_input,file_album,file_muzician,file_instrument;
    file_album.open("album.txt",ios::in);
    file_muzician.open("muzician.txt",ios::in);
    file_instrument.open("instrument.txt",ios::in);
    set<album>ALBUME;
    if(file_album.is_open() && file_muzician.is_open() && file_instrument.is_open())
    {
        string line_album, line_muzician, line_instrument;
        while(getline(file_album,line_album) && getline(file_muzician,line_muzician) && getline(file_instrument,line_instrument))
        {
            vector<string>informatii;
            stringstream sstream_album(line_album);
            stringstream sstream_muzician(line_muzician);
            stringstream sstream_instrument(line_instrument);
            string line_a,line_m,line_i;
            while(getline(sstream_album,line_a,'|'))
            {
                informatii.push_back(line_a);
            }
            while (getline(sstream_instrument,line_i,'|'))
            {
                informatii.push_back(line_i);
            }
            while (getline(sstream_muzician,line_m,'|'))
            {
                informatii.push_back(line_m);
            }
            int k=0;
            while(k < 2)
            {
                informatii.pop_back();
                k++;
            }
            album a(informatii[0],informatii[1],informatii[2],informatii[3],informatii[4],informatii[8],informatii[9],informatii[10],informatii[11],informatii[5],informatii[6],informatii[7]);
            ALBUME.insert(a);
        }
        file_album.close();
        file_muzician.close();
        file_instrument.close();
        string input,in1,in2;
        cout << "Introduceti comanda: ";
        cin.ignore();
        getline(cin,input);
        stringstream sstream_input(input);
        string line_input;
        vector<string>input_aux;
        while(getline(sstream_input,line_input,':'))
        {
            input_aux.push_back(line_input);
        }
        in1 = input_aux[0];
        in2 = input_aux[1];
        for(auto el : ALBUME)
        {
            if(in1.compare("NUME_ALBUM") == 0 && !el.getNumeAlbum().find(in2))
            {
                afisare_instrumente(el);
            }
            else
            {
                if(in1.compare("COPYRIGHT") == 0 && !el.getCopyright().find(in2))
                {
                    afisare_instrumente(el);
                }
                else
                {
                    if(in1.compare("COD_ALBUM") == 0 && !el.getCodAlbum().find(in2))
                    {
                        afisare_instrumente(el);
                    }
                    else
                    {
                        if(in1.compare("DATA") == 0 && !el.getData().find(in2))
                        {
                            afisare_instrumente(el);
                        }
                        else
                        {
                            if(in1.compare("FORMAT") == 0 && !el.getFormat().find(in2))
                            {
                                afisare_instrumente(el);
                            }
                            else
                            {
                                if(in1.compare("NUME_MUZICIAN") == 0 && !el.getNumeMuzician().find(in2))
                                {
                                    afisare_instrumente(el);
                                }
                                else
                                {
                                    if(in1.compare("CNP") == 0 && !el.getCnp().find(in2))
                                    {
                                        afisare_instrumente(el);
                                    }
                                    else
                                    {
                                        if(in1.compare("ADRESA") == 0 && !el.getAdresa().find(in2))
                                        {
                                            afisare_instrumente(el);
                                        }
                                        else
                                        {
                                            if(in1.compare("NR_TELEFON") == 0 && !el.getTelefon().find(in2))
                                            {
                                                afisare_instrumente(el);
                                            }
                                            else
                                            {
                                                if(in1.compare("NUME_INSTRUMENT") == 0 && !el.getNumeInstrument().find(in2))
                                                {
                                                    afisare_instrumente(el);
                                                }
                                                else
                                                {
                                                    if(in1.compare("NR_INSTRUMENT") == 0 && !el.getNrIdentificare().find(in2))
                                                    {
                                                        afisare_instrumente(el);
                                                    }
                                                    else
                                                    {
                                                        if(in1.compare("CHEIE_MUZICALA") == 0 && !el.getCheieMuzicala().find(in2))
                                                        {
                                                            afisare_instrumente(el);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else 
    {
        cout<<"Fisierele nu s-au putut deschide sau nu exista!";
    }
}