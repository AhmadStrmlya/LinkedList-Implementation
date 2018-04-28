#include "aplikasi.h"

void deleteC(List_parent &F, List_child &L, address_child P) {
    /** Naufal 1301174314 **/
    if(first(L)!=NULL) {
        address_parent K = first(F);
        do {
            deleteRtoC(child(K), P);
            K = next(K);
        } while(K != first(F));
        if(P == first(L)) {
            deleteFirst(L);
            cout<< "first";
        } else if(P == last(L)) {
            deleteLast(L);
            cout<< "last";
        } else {
            cout<< "after";
            address_child prec = prev(P);
            deleteAfter(L,prec,P);
        }
    }
}

void insertR(List_relasi &L, address_parent Q, address_relasi P) {
    /** Naufal 1301174314 **/
    insertFirst(child(Q),P);
}

bool CheckConnection(address_parent P, address_child C) {
    /** Check apakah address P dengan C mempunyai relasi **/
    /** Naufal 1301174314 **/
    address_relasi Q = findElm(child(P), C);
    if(Q == NULL) {
        return false;
    }
    return true;
}

void beli(address_parent P, address_child C) {
    /** Beli saham, connect jika belum terconnect. jika sudah maka hanya akan
        menambah jumlah saham ke address P **/
    /** Ahmad 1301170012 **/
    if (P != NULL && C != NULL) {
        int x;
        cout<<"Nasabah memiliki Deposito: Rp."<<info(P).deposito<<endl;
        cout<<"Jumlah Investasi: ";
        cin>>x;
        if(x<=info(P).deposito) {
            bool check = CheckConnection(P,C);
            if (check == false) {
                address_relasi R = alokasi(C,x);
                insertR(child(P), P, R);
            } else {
                address_relasi Q = findElm(child(P),C);
                isi(Q) = isi(Q) + x;
            }
            info(P).deposito = info(P).deposito - x;
        } else {
            cout<<"Deposito tidak mencukupi"<<endl;
        }
    }
}

void HitungNasabah(List_parent L) {
    /** Menghitung jumlah nasabah dan investor(nasabah yang sudah beli saham) **/
    /** Ahmad 1301170012 **/
    if(first(L) != NULL) {
        address_parent P = first(L);
        int i=0;
        int k=0;
        do {
            if(first(child(P)) != NULL) {
                i++;
            }
            k++;
            P = next(P);
        } while(P != first(L));
        cout<<"Nasabah  : "<<k<<endl;
        cout<<"Investor : "<<i<<endl;
    }
}

void HitungPerusahaan(List_child L, List_parent F) {
    /** menghitung jumlah perusahaan dan perusahaan yg memiliki investor **/
    /** Naufal 1301174314 **/
    address_child C = first(L);
    bool check;
    int i = 0;
    int k = 0;
    while(C != NULL) {
        address_parent P = first(F);
        check = false;
        i++;
        if(first(F) != NULL) {
            do {
                check = CheckConnection(P,C);
                P = next(P);
            } while(P != first(F) && check != true);
        }
        if (check == true) {
            k++;
        }
        C = next(C);
    }
    cout<<"Perusahaan : "<<i<<endl;
    cout<<"Perusahaan yang mendapat modal : "<<k<<endl;
}

void printOneC(address_child P, List_parent L) {
    /** Print suatu child yang ditunjuk oleh P **/
    /** Naufal 1301174314 **/
    if(P != NULL) {
        address_parent Q = first(L);
        cout<<"Perusahaan "<<info(P).nama<<endl;
        do {
            bool check = false;
            check = CheckConnection(Q,P);
            if(check == true) {
                cout<<"->"<<info(Q).nama<<endl;
            }
            Q=next(Q);
        } while(Q != first(L));
    }

}

void nasabahterbaik(List_parent L) {
    /** mencari nasabah dengan investasi terbesar **/
    /** Ahmad 1301170012 **/
    int a = 0;
    int b;
    address_parent P = first(L);
    address_parent B = first(L);
    do {
        b = 0;
        address_relasi Q = first(child(P));
        while(Q != NULL) {
            b = b + isi(Q);
            Q = next(Q);
        }
        if (b > a) {
            a = b;
            B = P;
        }
        P=next(P);
    } while(P != first(L));
    cout<<info(B).nama;
}

void perusahaanterfavorit(List_parent L, List_child F) {
    /** mencari perusahaan dengan investor terbanyak **/
    /** Ahmad 1301170012 **/
    int a = 0;
    int b;
    bool check;
    address_child C = first(F);
    address_child B = first(F);
    int i = 0;
    while(C != NULL) {

        b = 0;
        address_parent P = first(L);
        do {
            check = CheckConnection(P,C);
            if(check == true) {
                b++;
            }
            P = next(P);
        } while(P != first(L));
        if (b > a) {
            a = b;
            B = C;
        }
        C = next(C);
    }
    cout<<"Perusahaan "<<info(B).nama;
}

void disconnect(address_parent P, address_child C) {
    /** aka jual saham, menghapus hubungan P dengan C **/
    /** Ahmad 1301170012 **/
    if(P != NULL && C != NULL) {
        address_relasi Q = findElm(child(P),C);
        if(Q != NULL) {
            info(P).deposito = info(P).deposito + isi(Q);
            deleteRtoC(child(P),C);
        } else {
            cout<<"Nasabah belum investasi ke Perusahaan";
        }
    } else {
        cout<<"Nasabah atau perusahaan tidak ditemukan";
    }
}

void DataDummy(List_child &LC, List_parent &LP) {
    /** Naufal 1301174314 **/
    /** Menambah data untuk mempermudah men-debug **/
    address_child C;
    address_parent P;
    address_relasi R;
    infotype_parent n;
    infotype_child p;

    /** insert parent */
    n.ID = 213;
    n.deposito = 30000;
    n.nama = "asep";
    P = alokasi(n);
    insertP(LP, P);
    n.ID = 240;
    n.deposito = 45000;
    n.nama = "abep";
    P = alokasi(n);
    insertP(LP, P);
    n.ID = 330;
    n.deposito = 20000;
    n.nama = "apae";
    P = alokasi(n);
    insertP(LP, P);
    n.ID = 459;
    n.deposito = 50000;
    n.nama = "atral";
    P = alokasi(n);
    insertP(LP, P);

    /** insert child */
    p.ID = 501;
    p.nama = "Betra";
    p.rating = 4.5;
    C = alokasi(p);
    insertC(LC,C);
    p.ID = 502;
    p.nama = "Bartlo";
    p.rating = 4.6;
    C = alokasi(p);
    insertC(LC,C);
    p.ID = 503;
    p.nama = "Sambal";
    p.rating = 3.2;
    C = alokasi(p);
    insertC(LC,C);
    p.ID = 504;
    p.nama = "Goesrek";
    p.rating = 4.0;
    C = alokasi(p);
    insertC(LC,C);

    /** RELASIKAN PARENT DENGAN CHILD **/
    P = findElm(LP, 213);
    C = findElm(LC, 501);
    R = alokasi(C,8000);
    insertR(child(P), P, R);
    C = findElm(LC, 504);
    R = alokasi(C,2000);
    insertR(child(P), P, R);

    P = findElm(LP, 240);
    C = findElm(LC, 502);
    R = alokasi(C,15000);
    insertR(child(P), P, R);

    P = findElm(LP, 330);
    C = findElm(LC, 502);
    R = alokasi(C,5500);
    insertR(child(P), P, R);

}
