#include<iostream>
#include<ctime>
#include"lista_pokazivaci.h"
//#include"lista_polja.h"

using namespace std;

void unos(char *niz){
    cin.getline(niz, 50);
    if(cin.gcount()==1)
       cin.getline(niz,50);
}

int date(char *datum){
    char _datum[9]={0,0,0,0,0,0,0,0,0};
     _datum[0] = datum[4]; _datum[1] = datum[5]; 
     _datum[2] = datum[6]; _datum[3] = datum[7];
     _datum[4] = datum[2]; _datum[5] = datum[3];
     _datum[6] = datum[0]; _datum[7] = datum[1];
    return atoi(_datum);
}

double diff_date(char a[], char b[]){
  char t[5],_t[5];
  int d,m,y;
  t[0]=a[0]; t[1]=a[1]; d=atoi(t);
  t[0]=a[2]; t[1]=a[3]; m=atoi(t);
  t[0]=a[4]; t[1]=a[5]; t[2]=a[6]; t[3]=a[7]; y=atoi(t)-1900;
  struct tm t1 = {0,0,0,d,m,y};
  d=0; m=0; y=0;
  _t[0]=b[0]; _t[1]=b[1]; d=atoi(_t);
  _t[0]=b[2]; _t[1]=b[3]; m=atoi(_t);
  _t[0]=b[4]; _t[1]=b[5]; _t[2]=b[6]; _t[3]=b[7]; y=atoi(_t)-1900;
  struct tm t2 = {0,0,0,d,m,y};
  time_t start = mktime(&t1);
  time_t end = mktime(&t2);
  double difference = difftime(end, start) / (60 * 60 * 24);
  return difference;
}

bool check_date(char *datum){//DDMMYYYY
     if(strlen(datum)!=8){
        cout << endl << "Datum mora biti oblika DDMMYYY" << endl;
        cout << "npr. 01082010" << endl << endl;
        return true;                     
     }
     int d = date(datum);
     if(d<20100101 || d>20111231){
        cout << endl << "Datum mora biti unutar raspona od 01.01.2010. do 31.12.2011" << endl << endl;
        return true;                   
     }
     return false;
}

void utovar(tlist *list){
     system("cls");
     tdata data;
     cout << "Sifra: "; cin >> data.sifra;
     cout << "Naziv robe: "; unos(data.naziv);
     cout << "Vrsta robe: "; unos(data.vrsta);
     do{
        cout << "Datum proizvodnje (DDMMYYYY): "; unos(data.datum);
     }while(check_date(data.datum));
     do{
        cout << "Rok upotreba (DDMMYYYY): "; unos(data.rok);
     }while(check_date(data.rok));
     PushS(data,list);
     cout << "Zapis je dodan" << endl;
     system("pause");
}

void ispis(tdata x){
     cout << "Sifra: " << x.sifra << endl;
     cout << "Naziv roba: " << x.naziv << endl;
     cout << "Vrsta roba: " << x.vrsta << endl;
     cout << "Datum proizvodnje: "
          << x.datum[0] << x.datum[1] << "."
          << x.datum[2] << x.datum[3] << "."
          << x.datum[4] << x.datum[5] << x.datum[6] << x.datum[7] << "." << endl;
     cout << "Rok upotrebe: "
          << x.rok[0] << x.rok[1] << "."
          << x.rok[2] << x.rok[3] << "."
          << x.rok[4] << x.rok[5] << x.rok[6] << x.rok[7] << "." << endl << endl;
}

void istovar1(tlist *list){//20100923
     system("cls");
     tlist *temp = InitS(temp);
     tdata data;
     int d;
     while(!IsEmptyS(list)){
        data = TopS(list);
        d = date(data.datum);
        if(d<20100923){
           ispis(data);
           PopS(list);
           continue;
        }
        PushS(data,temp);
        PopS(list);
     }
     while(!IsEmptyS(temp)){
        data = TopS(temp);
        PushS(data,list);
        PopS(temp);
     }
     system("pause");
}

void istovar2(tlist *list){
     if(IsEmptyS(list)) return;
     tdata data = TopS(list);
     double diff;
     diff = diff_date(data.datum, data.rok);
     PopS(list);
     if(!IsEmptyS(list))
        istovar2(list);
     if(diff<14)
        ispis(data);
     else
        PushS(data,list);
     return;
}

int main(){
  
  int izbor;
  tlist *list = InitS(list);

  do{
    system("cls");
    cout << "1 - Utovar" << endl;
    cout << "2 - Prvi istovar" << endl;
    cout << "3 - Drugi istovar" << endl;
    cout << "0 - Kraj" << endl;
    cout << endl;
    cout << "Vas izbor:";
    cin >> izbor;
    switch(izbor){
      case 1: utovar(list); break;
      case 2: istovar1(list); break;
      case 3: 
           system("cls");
           istovar2(list); 
           system("pause");
           break;
      case 0: cout << "Kraj" << endl; break;
      default: cout << "Krivi unos" << endl; system("pause");
    }
  }while(izbor);
  
  system("pause");
  return 0;
}
