#include<iostream>
//#include"lista_polja.h"
#include"lista_pokazivaci.h"

using namespace std;

void unos(tlist *list){
  system("cls");
  tdata data;
  cout << "Unesite sifru: "; cin >> data.sifra;
  cin.ignore();
  cout << "Naziv: "; cin.getline(data.naziv,50);
  PushS(data,list);
  cout << endl << "Dodano" << endl;
  system("pause");
}

void ispis(tlist *list){
  system("cls");
  tdata data = TopS(list);
  cout << "Sifra: " << data.sifra << endl;
  cout << "Naziv: " << data.naziv << endl;
  system("pause");
}

void brisanje(tlist *list){
  system("cls");
  if(PopS(list))
    cout << "Zapis je uklonjen!" << endl;
  else
    cout << "Lista je prazna" << endl;
  system("pause");
}

void prazna(tlist *list){
  system("cls");
  if(IsEmptyS(list))
    cout << "Lista je prazna" << endl;
  else
    cout << "Lista nije prazna" << endl;
  system("pause");
}

int main(){
  
  int izbor;
  tlist *list = InitS(list);

  do{
    system("cls");
    cout << "1 - Unos(Push)" << endl;
    cout << "2 - Ispis zadnjeg(TopS)" << endl;
    cout << "3 - Brisi (PopS)" << endl;
    cout << "4 - Prazna?" << endl;
    cout << "0 - Kraj" << endl;
    cout << endl;
    cout << "Vas izbor:";
    cin >> izbor;
    
    switch(izbor){
      case 1: unos(list); break;
      case 2: ispis(list); break;
      case 3: brisanje(list); break;
      case 4: prazna(list); break;
      case 0: cout << "Kraj" << endl; break;
      default: cout << "Krivi unos" << endl; system("pause");
    }

  }while(izbor);

  system("pause");
  return 0;
}
