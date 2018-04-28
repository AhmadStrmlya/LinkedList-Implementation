#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_child.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info
#define isi(P) P->isi

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child info;
    int isi;
};

struct List_relasi{
    address_relasi first;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void deleteFirst(List_relasi &L);
void deleteLast(List_relasi &L, address_relasi F);
void deleteAfter(List_relasi &L, address_relasi F);
void deleteRtoC(List_relasi &L, address_child P);

/** PERLU MODIFIKASI */
address_relasi alokasi( address_child C, int x);
address_relasi findElm(List_relasi L, address_child C);
void printInfo(List_relasi L);


#endif // LIST_RELASI_H_INCLUDED
