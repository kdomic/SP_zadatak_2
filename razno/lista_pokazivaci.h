#include<iostream>

using namespace std;

struct tdata{
  int sifra;
  char naziv[50], vrsta[50];
  char datum[12], rok[12];
};

struct tlist{
  tdata data;
  tlist *next;
};

typedef tlist* ele;

bool IsEmptyS(tlist *list){
  if(list->next==NULL)
    return true;
  else
    return false;
}

tdata TopS(tlist *list){
  tdata data;
  data.sifra=0;
  strcpy(data.naziv,"ERROR: Lista je prazna");
  if(IsEmptyS(list)) return data;
  tlist *last = list->next;
  return last->data;
}

int PushS(tdata x, tlist *list){
  tlist *n = new tlist;
  n->data = x;
  n->next = list->next;
  list->next = n;
  return 1;
}

int PopS(tlist *list){
  if(IsEmptyS(list)) return 0;
  tlist *last = list->next;
  list->next = last->next;
  return 1;
}

tlist* InitS(tlist *list){
  list = new tlist;
  list->next=NULL;
  return list;
}
