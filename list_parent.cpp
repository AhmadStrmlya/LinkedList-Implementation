#include "list_parent.h"
#include <stdlib.h>

void createList(List_parent &L) {
    /** Ahmad 1301170012 **/
    first(L) = NULL;
}

infotype_parent CreateDataP(List_parent L) {
    /** Ahmad 1301170012 **/
    infotype_parent x;
    bool Duplicate;
    cout<<"ID merupakan integer dari 100 - 499"<<endl;
    cout<<"New ID: ";
    cin>>x.ID;
    if (first(L) != NULL) {
        Duplicate = DuplicateP(L, x);
        while((Duplicate == true) || (x.ID < 100 || x.ID >499)) {
            system("CLS");
            if(Duplicate == true) {
                cout<<"ID sudah terpakai"<<endl;
            }
            cout<<"ID merupakan integer dari 100 - 499"<<endl;
            cout<<"ID   : ";
            cin>>x.ID;
            Duplicate = DuplicateP(L, x);
        }
    }
    cout<<"Nama : ";
    cin>>x.nama;
    x.deposito = 0;
    return x;
}

bool DuplicateP(List_parent &L,infotype_parent P) {
    /** Ahmad 1301170012 **/
    address_parent Q = first(L);
    do {
        if(P.ID == info(Q).ID) {
            return true;
        }
        Q=next(Q);
    } while(Q!=first(L));
    return false;
}

address_parent alokasi(infotype_parent x) {
    /** Ahmad 1301170012 **/
    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void insertFirst(List_parent &L, address_parent P) {
    /** Ahmad 1301170012 **/
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P) {
    /** Ahmad 1301170012 **/
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertLast(List_parent &L, address_parent P) {
    /** Ahmad 1301170012 **/
    address_parent Q = first(L);
    while(next(Q)!=first(L)) {
        Q = next(Q);
    }
    next(Q) = P;
    next(P) = first(L);
}

void insertP(List_parent &L, address_parent F) {
    /** Ahmad 1301170012 **/
    if (first(L) == NULL) {
        insertFirst(L,F);
    } else if (info(first(L)).ID >= info(F).ID) {
        insertFirst(L,F);
    } else {
        address_parent P = first(L);
        do {
            P = next(P);
        } while(P != first(L) && info(F).ID >= info(P).ID);
        if (P == first(L)) {
            insertLast(L,F);
        } else {
            address_parent Q = first(L);
            while(next(Q)!=P) {
                Q=next(Q);
            }
            insertAfter(L, Q, F);
        }
    }
}

void deleteFirst(List_parent &L) {
    /** Ahmad 1301170012 **/
    address_parent P = first(L);
    if(P!=NULL) {
        if(next(P)!=P) {
            while(next(P) != first(L)) {
                P = next(P);
            }
            next(P) = next(first(L));
            P = first(L);
            first(L) = next(first(L));
            next(P) = NULL;
        } else {
            first(L) = NULL;
            next(P) = NULL;
        }
        delete P;
    }
}

void deleteLast(List_parent &L, address_parent P) {
    /** Ahmad 1301170012 **/
    address_parent Q = first(L);
    while(next(Q)!=P) {
        Q = next(Q);
    }
    next(Q) = first(L);
    next(P) = NULL;
    delete P;
}

void deleteAfter(List_parent &L, address_parent P) {
    /** Ahmad 1301170012 **/
    address_parent Prec = first(L);
    while(next(Prec) != P) {
        Prec = next(Prec);
    }
    next(Prec) = next(P);
    next(P) = NULL;
    delete P;
}

void deleteP(List_parent &L, address_parent P) {
    /** Ahmad 1301170012 **/
    while(first(child(P))!=NULL) {
        deleteFirst(child(P));
    }
    if (P == first(L)) {
        deleteFirst(L);
    } else if(next(P) == first(L)) {
        deleteLast(L, P);
    } else {
        deleteAfter(L,P);
    }
}

void printAll(List_parent L, List_child F) {
    /** Naufal 1301174314 **/
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<"ID       : "<<info(P).ID<<endl;
            cout<<"Nama     : "<<info(P).nama<<endl;
            cout<<"Deposito : "<<info(P).deposito<<endl;
            printInfo(child(P));
            cout<<endl;
            P = next(P);
        } while(P!=first(L));
    } else if(first(F) != NULL){
        printInfo(F);
    }
   }


void printP(List_parent L) {
    /** Print only parent **/
    /** Ahmad 1301170012 **/
    address_parent P = first(L);
    if(first(L) != NULL) {
        do {
            cout<<"ID       : "<<info(P).ID<<endl;
            cout<<"Nama     : "<<info(P).nama<<endl;
            cout<<"Deposito : "<<info(P).deposito<<endl<<endl;
            P = next(P);
        } while(P != first(L));
    }
}

void printOneP(address_parent P) {
    /** Print sebuah parent yang ditunjuk **/
    /** Ahmad 1301170012 **/
    if(P!=NULL) {
        cout<<"ID       : "<<info(P).ID<<endl;
        cout<<"Nama     : "<<info(P).nama<<endl;
        cout<<"Deposito : "<<info(P).deposito<<endl;
        printInfo(child(P));
    }
}

address_parent findElm(List_parent L, int x) {
    /** Ahmad 1301170012 **/
    address_parent P = first(L);
    do {
        if(info(P).ID == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
