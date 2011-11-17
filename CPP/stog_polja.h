#include<iostream>

using namespace std;

struct tdata{
  int sifra;
  char naziv[50], vrsta[50];
  char datum[12], rok[12];
};

struct tlist{
  tdata data[10000];
  int cursor;
};

typedef int ele;

bool IsEmptyS(tlist *list){
  if(list->cursor==0)
    return true;
  else
    return false;
}

tdata TopS(tlist *list){
  tdata data;
  data.sifra=0;
  strcpy(data.naziv,"ERROR: Lista je prazna");
  if(IsEmptyS(list)) return data;
  return list->data[list->cursor-1];
}

int PushS(tdata x, tlist *list){
  list->data[list->cursor] = x;
  list->cursor++;
  return 1;
}

int PopS(tlist *list){
  if(IsEmptyS(list)) return 0;
  list->cursor--;
  return 1;
}

tlist* InitS(tlist *list){
  list = new tlist;
  list->cursor=0;
  return list;
}
