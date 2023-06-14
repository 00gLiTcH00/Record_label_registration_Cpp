#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include "instructiuni.h"
#include "album.h"
#include "functions.h"
using namespace std;

int main()
{
    int alegere;
    do
    {
        instructiuni();
        cin >> alegere;
        switch(alegere)
        {
            case 0:
                SetColor(2);
                cout << "================================= Programul s-a inchis =================================\n";
                break;
//------------------------------------------------------------------------------------------------------------------
            case 1:
                instructiuni_case1();
                cin >> alegere;
                switch(alegere)
                {
                    case 0:
                        SetColor(2);
                        cout << "================================= Programul s-a inchis =================================\n";
                        break;
                    case 1:
                        instructiuni_case_secundar();
                        cin >> alegere;
                        switch(alegere)
                        {
                            case 0:
                                SetColor(2);
                                cout << "================================= Programul s-a inchis =================================\n";
                                break;
                            case 1:
                                creare_resetare_mic();
                                break;
                            case 2:
                                creare_resetare_mare();
                                break;
                            default:
                                SetColor(5);
                                cout << "!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n";
                                break;
                        }
                        break;
                    case 2:
                        afisare_generala();
                        break;
                    case 3:
                        instructiuni_case_secundar();
                        cin >> alegere;
                        switch(alegere)
                        {
                            case 0:
                            SetColor(2);
                                cout << "================================= Programul s-a inchis =================================\n";
                                break;
                            case 1:
                                append_general_mic();
                                break;
                            case 2:
                                append_general_mare();
                                break;
                             default:
                                SetColor(5);
                                cout << "!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n";
                                break;
                        }
                        break;
                    case 4:
                        cautare_generala();
                        break;
                    case 5:
                        stergere_generala();
                        break;
                    case 6:
                        modificare_generala();
                        break;
                    default:
                        SetColor(5);
                        cout << "!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n";
                        break;
                }
                break;
//------------------------------------------------------------------------------------------------------------------
            case 2:
                instructiuni_case2();
                cin >> alegere;
                switch(alegere)
                {
                    case 0:
                    SetColor(2);
                        cout << "================================= Programul s-a inchis =================================\n";
                        break;
                    case 1:
                        afisare_muzicieni_solo();
                        break;
                    case 2:
                        cautare_muzicieni_solo();
                        break;
                    default:
                    SetColor(5);
                        cout << "!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n";
                        break;
                }
                break;
//------------------------------------------------------------------------------------------------------------------
            case 3:
                instructiuni_case3();
                cin >> alegere;
                switch(alegere)
                {
                    case 0:
                    SetColor(2);
                        cout << "================================= Programul s-a inchis =================================\n";
                        break;
                    case 1:
                        afisare_albume_solo();
                        break;
                    case 2:
                        cautare_albume_solo();
                        break;
                    default:
                    SetColor(5);
                        cout << "!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n";
                        break;
                }
                break;
//------------------------------------------------------------------------------------------------------------------
            case 4:
                instructiuni_case4();
                cin >> alegere;
                switch(alegere)
                {
                    case 0:
                    SetColor(2);
                        cout << "================================= Programul s-a inchis =================================\n";
                        break;
                    case 1:
                        afisare_instrumente_solo();
                        break;
                    case 2:
                        cautare_instrumente_solo();
                        break;
                    default:
                    SetColor(5);
                        cout << "!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n";
                        break;
                }
                break;
//------------------------------------------------------------------------------------------------------------------


            default:
                SetColor(5);
                cout << "!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n";
                break;

//------------------------------------------------------------------------------------------------------------------
        }

    }while(alegere != 0);
    system("pause");
}