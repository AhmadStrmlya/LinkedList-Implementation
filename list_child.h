#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct perusahaan{
    int ID;
    string nama;
    float rating;
};

typedef perusahaan infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child{
    address_child first;
    address_child last;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_child &L);
infotype_child CreateDataC(List_child L);
bool DuplicateC(List_child &L, infotype_child P);

void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(List_child &L, address_child Prec, address_child P);
void insertC(List_child &L, address_child P);

void deleteFirst(List_child &L);
void deleteLast(List_child &L);
void deleteAfter(List_child &L, address_child Prec, address_child P);

/** PERLU MODIFIKASI */
address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElm(List_child L, int x);
void printInfo(List_child L);


#endif // LIST_CHILD_H_INCLUDED
