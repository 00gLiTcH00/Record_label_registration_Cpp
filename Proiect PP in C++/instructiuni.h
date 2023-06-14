#include <iostream>
using namespace std;



void SetColor(int ForgC);


void instructiuni()
{

  
  //titlu
 SetColor(10);
 
	cout << "\t\t****************************************************" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t*              ";
	SetColor(14);
	cout << "FIRMA DE INREGISTRARI";
	SetColor(10);
	cout <<"               *" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t****************************************************" << endl;
	cout << endl;
	


  //optiuni
  SetColor(12);
  cout << "\t\t+--------------------------------------------------+" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Instructiuni generale  (1)";SetColor(12); cout << "                |" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Baza de date a muzicienilor  (2)";SetColor(12); cout << "          |" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Baza de data a albumelor  (3)";SetColor(12); cout << "             |" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Baza de date a instrumentelor  (4)";SetColor(12); cout << "        |" << endl; 
  cout << "\t\t| "; SetColor(13); cout << "\t Iesire  (0)";SetColor(12); cout << "                               |" << endl;
  cout << "\t\t+--------------------------------------------------+" << endl;


  //alegere
	SetColor(11);
	cout << "\n\t\tIntroduceti cifra corespunzatoare instructiunii dorite: ";
    
	
    
}
void instructiuni_case1()
{
  
cout<<endl;
 SetColor(10);
	cout << "\t\t****************************************************" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t*              ";
	SetColor(14);
	cout << "INSTRUCTIUNI GENERALE";
	SetColor(10);
	cout <<"               *" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t****************************************************" << endl;
	cout << endl;

  
  SetColor(12);
  cout << "\t\t+--------------------------------------------------+" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Creare / Resetare a bazei de date  (1)";SetColor(12); cout << "    |" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Afisare generala a datelor  (2)";SetColor(12); cout << "           |" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Adaugare de date  (3)";SetColor(12); cout << "                     |" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Cautare generala a datelor  (4)";SetColor(12); cout << "           |" << endl; 
  cout << "\t\t| "; SetColor(13); cout << "\t Stergere generala a datelor  (5)";SetColor(12); cout << "          |" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Modificare de date  (6)";SetColor(12); cout << "                   |" << endl;
  cout << "\t\t| "; SetColor(13); cout << "\t Iesire  (0)";SetColor(12); cout << "                               |" << endl;
  cout << "\t\t+--------------------------------------------------+" << endl;

  SetColor(11);
	cout << "\n\t\tIntroduceti cifra corespunzatoare instructiunii dorite: ";
    
	
    
}
void instructiuni_case2()
{


  
cout<<endl;
 SetColor(10);
	cout << "\t\t****************************************************" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t*           ";
	SetColor(14);
	cout << "BAZA DE DATE A MUZICIENILOR";
	SetColor(10);
	cout <<"            *" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t****************************************************" << endl;
	cout << endl;

SetColor(12);
    cout << "\t\t+--------------------------------------------------+" << endl;
	cout << "\t\t| "; SetColor(13); cout << "\t\t Afisare  (1)";SetColor(12); cout << "                      |" << endl;
	cout << "\t\t| "; SetColor(13); cout << "\t\t Cautare  (2)";SetColor(12); cout << "                      |" << endl;
    cout << "\t\t| "; SetColor(13); cout << "\t\t Iesire  (0)";SetColor(12); cout << "                       |" << endl;
    cout << "\t\t+--------------------------------------------------+" << endl;
  
    

 SetColor(11);
	cout << "\n\t\tIntroduceti cifra corespunzatoare instructiunii dorite: ";
    
	
 
   
}
void instructiuni_case3()
{

  
cout<<endl;
 SetColor(10);
	cout << "\t\t****************************************************" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t*             ";
	SetColor(14);
	cout << "BAZA DE DATE A ALBUMELOR";
	SetColor(10);
	cout <<"             *" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t****************************************************" << endl;
	cout << endl;

 SetColor(12);
     cout << "\t\t+--------------------------------------------------+" << endl;
	 cout << "\t\t| "; SetColor(13); cout << "\t\t Afisare  (1)";SetColor(12); cout << "                      |" << endl;
	 cout << "\t\t| "; SetColor(13); cout << "\t\t Cautare  (2)";SetColor(12); cout << "                      |" << endl;
     cout << "\t\t| "; SetColor(13); cout << "\t\t Iesire  (0)";SetColor(12); cout << "                       |" << endl;
     cout << "\t\t+--------------------------------------------------+" << endl;
  
  SetColor(11);
	cout << "\n\t\tIntroduceti cifra corespunzatoare instructiunii dorite: ";
    
	
    
}
void instructiuni_case4()
{
  
  cout<<endl;
 SetColor(10);
	cout << "\t\t****************************************************" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t*          ";
	SetColor(14);
	cout << "BAZA DE DATE A INSTRUMENTELOR";
	SetColor(10);
	cout <<"           *" << endl;
	cout << "\t\t*                                                  *" << endl;
	cout << "\t\t****************************************************" << endl;
	cout << endl;
  
     SetColor(12);
     cout << "\t\t+--------------------------------------------------+" << endl;
	 cout << "\t\t| "; SetColor(13); cout << "\t\t Afisare  (1)";SetColor(12); cout << "                      |" << endl;
	 cout << "\t\t| "; SetColor(13); cout << "\t\t Cautare  (2)";SetColor(12); cout << "                      |" << endl;
     cout << "\t\t| "; SetColor(13); cout << "\t\t Iesire  (0)";SetColor(12); cout << "                       |" << endl;
     cout << "\t\t+--------------------------------------------------+" << endl;
 
    
	SetColor(11);
	cout << "\n\t\tIntroduceti cifra corespunzatoare instructiunii dorite: ";
    
	
   
    
}
void instructiuni_case_secundar()
{
    cout<<endl;
	 SetColor(12);
     cout << "\t\t+-----------------------------------------------+" << endl;
     cout << "\t\t| "; SetColor(13); cout << "\t\t Input mic  (1)";SetColor(12); cout << "                 |" << endl;
	 cout << "\t\t| "; SetColor(13); cout << "\t\t Input mare  (2)";SetColor(12); cout << "                |" << endl;
	 cout << "\t\t| "; SetColor(13); cout << "\t\t Iesire  (0)";SetColor(12); cout << "                    |" << endl;
     cout << "\t\t+-----------------------------------------------+" << endl;


    SetColor(11);
     cout << "\n\t\tIntroduceti cifra corespunzatoare instructiunii dorite: ";
}

void SetColor(int ForgC) 
{ 
    WORD wColor; 

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
     CONSOLE_SCREEN_BUFFER_INFO csbi; 

         
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) 
    { 
       
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F); 
      SetConsoleTextAttribute(hStdOut, wColor); 
    } 
    return; 
}
