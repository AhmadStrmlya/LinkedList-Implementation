#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include "list_relasi.h"

#include <iostream>
using namespace std;


#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child

struct nasabah{
    int ID;
    string nama;
    int deposito;
};

typedef nasabah infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    List_relasi child;
    address_parent next;
};

struct List_parent {
    address_parent first;
};


/** TIDAK PERLU MODIFIKASI */
void createList(List_parent &L);
infotype_parent CreateDataP(List_parent L);
bool DuplicateP(List_parent &L,infotype_parent P);

void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void insertP(List_parent &L, address_parent P);

void deleteFirst(List_parent &L);
void deleteLast(List_parent &L, address_parent P);
void deleteAfter(List_parent &L, address_parent P);
void deleteP(List_parent &L, address_parent P);


/** PERLU MODIFIKASI */
address_parent alokasi(infotype_parent x);
void dealokasi(address_parent &P);
address_parent findElm(List_parent L, int x);
void printAll(List_parent L, List_child F);
void printP(List_parent L);
void printOneP(address_parent P);


#endif // LIST_PARENT_H_INCLUDED
