#include "list_relasi.h"

void createList(List_relasi &L) {
    /** Naufal 1301174314 **/
    first(L) = NULL;
}

address_relasi alokasi(address_child C, int x) {
    /** Naufal 1301174314 **/
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    isi(P) = x;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    /** Naufal 1301174314 **/
    next(P) = first(L);
    first(L) = P;
}

void deleteFirst(List_relasi &L) {
    /** Ahmad 1301170012 **/
    address_relasi P = first(L);
    if(next(P) == NULL) {
        first(L) = NULL;
    } else {
        first(L) = next(P);
    }
    info(P) = NULL;
    next(P) = NULL;
    delete P;
}

void deleteLast(List_relasi &L, address_relasi F) {
    /** Ahmad 1301170012 **/
    address_relasi P = first(L);
    while (next(P)!=F) {
        P = next(P);
    }
    next(P) = NULL;
    info(F) = NULL;
    next(F) = NULL;
    delete F;
}

void deleteAfter(List_relasi &L, address_relasi F) {
    /** Ahmad 1301170012 **/
    address_relasi P = first(L);
    while (next(P)!=F) {
        P = next(P);
    }
    next(P) = next(F);
    info(F) = NULL;
    next(F) = NULL;
    delete F;
}

void deleteRtoC(List_relasi &L, address_child C) {
    /** Delete suatu relasi yang terhubung dengan address C **/
    /** Ahmad 1301170012 **/
    address_relasi P = findElm(L,C);
    if (P != NULL) {
        if (P == first(L)) {
            deleteFirst(L);
        } else if (next(P) == NULL) {
            deleteLast(L,P);
        } else {
            deleteAfter(L,P);
        }
    }
}

void printInfo(List_relasi L) {
    /** Naufal 1301174314 **/
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<"->"<<"Perusahaan "<<info(info(P)).nama<<"("<<info(info(P)).ID<<")"<<"["<<isi(P)<<"]"<<endl;
        P = next(P);
    }
}

address_relasi findElm(List_relasi L, address_child C) {
    /** Naufal 1301174314 **/
    address_relasi P = first(L);
    while(P != NULL) {
        if(info(P)== C) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
