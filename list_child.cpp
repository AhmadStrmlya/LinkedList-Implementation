#include "list_child.h"
#include "stdlib.h"

void createList(List_child &L) {
    /** Naufal 1301174314 **/
    first(L) = NULL;
    last(L) = NULL;
}

infotype_child CreateDataC(List_child L){
    /** Naufal 1301174314 **/
    infotype_child x;
    bool Duplicate;
    cout<<"ID merupakan integer dari 500 - 999"<<endl;
    cout<<"ID    : ";
    cin>>x.ID;
    Duplicate = DuplicateC(L, x);
    while((Duplicate == true) || (x.ID > 1000 || x.ID <499)){
        system("CLS");
        if(Duplicate == true){
            cout<<"ID sudah terpakai"<<endl;
        }
        cout<<"ID merupakan integer dari 500 - 999"<<endl;
        cout<<"ID    : ";
        cin>>x.ID;
        Duplicate = DuplicateC(L, x);
    }
    cout<<"Nama  : ";
    cin>>x.nama;
    cout<<"Range rating 0 - 5";
    cout<<endl<<"rating: ";
    cin>>x.rating;
    while(x.rating >5){
        cout<<"range rating 0 - 5"<<endl;
        cout<<"rating: ";
        cin>>x.rating;
    }
    return x;
}

bool DuplicateC(List_child &L, infotype_child P){
    /** Naufal 1301174314 **/
    address_child Q = first(L);
    while(Q != NULL){
        if(P.ID == info(Q).ID){
            return true;
        }
        Q=next(Q);
    }
    return false;
}

address_child alokasi(infotype_child x) {
    /** Naufal 1301174314 **/
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    /** Naufal 1301174314 **/
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P){
    /** Naufal 1301174314 **/
    prev(P) = last(L);
    next(last(L)) = P;
    last(L) = P;
}

void insertAfter(List_child &L, address_child Prec, address_child P){
    /** Naufal 1301174314 **/
    if(Prec == last(L)){
        insertLast(L,P);
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
        prev(next(P)) = P;
        prev(P) = Prec;
    }
}

void insertC(List_child &L, address_child P){
    /** Naufal 1301174314 **/
    if (first(L) == NULL){
        insertFirst(L, P);
    } else {
        address_child Q = first(L);
        address_child S = last(L);
        if(info(P).rating >= info(Q).rating){
            insertFirst(L,P);
        }
        else if(info(P).rating <= info(S).rating){
            insertLast(L,P);
        } else {
            Q = next(Q);
            while(info(P).rating <= info(Q).rating){
                Q = next(Q);
            }
            insertAfter(L,prev(Q),P);
        }
    }
}

void deleteFirst(List_child &L){
    /** Naufal 1301174314 **/
    address_child P = first(L);
    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        first(L) = next(first(L));
        prev(first(L)) = NULL;
    }
    prev(P) = NULL;
    next(P) = NULL;
    delete P;
}

void deleteLast(List_child &L){
    /** Naufal 1301174314 **/
    address_child P = last(L);
    last(L) = prev(P);
    next(last(L)) = NULL;
    prev(P) = NULL;
    delete P;
}

void deleteAfter(List_child &L, address_child Prec, address_child P){
    /** Naufal 1301174314 **/
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
    delete P;
}

void printInfo(List_child L) {
    /** Naufal 1301174314 **/
    address_child P = first(L);
    cout<<"|{Rating}| {ID } | <=- Nama Perusahaan -=>"<<endl;
    while(P !=NULL) {
        cout<<fixed; /** Untuk 2 angka di belakang koma **/
        cout.precision(2); /** Untuk 2 angka dibelakang koma **/
        cout<<"| {"<<info(P).rating<<"} | {"<<info(P).ID<<"} | Perusahaan "<<info(P).nama<<endl;
        P = next(P);
    }
}

address_child findElm(List_child L, int x) {
    /** Naufal 1301174314 **/
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).ID==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
