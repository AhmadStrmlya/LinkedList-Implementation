#include <iostream>
#include <stdlib.h>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "aplikasi.h"

void DaReal() {
    /** Ahmad 1301170012 **/
    List_parent LP;
    List_child LC;
    createList(LP);
    createList(LC);

    address_child C;
    address_parent P;
    address_relasi R;
    infotype_parent n;
    infotype_child p;

    int x;
    int choice;

    cout<<"<=--------------------------=>"<<endl<<endl;
    cout<<"          Welcome to          "<<endl;
    cout<<"    Bursa Efek Opang Ahmad "<<endl;
    cout<<"          [B.E.O.A]"<<endl<<endl;
    cout<<"<=--------------------------=>"<<endl<<endl<<endl;
    cout<<"Dummy Data?"<<endl<<"(1 for yes, else for no)"<<endl;
    cin>>x;
    if(x == 1) {
        DataDummy(LC,LP);
    }
    system("PAUSE");
    system("CLS");

    do {
        cout<<" BEOA MENU"<<endl;
        cout<<"1. Status"<<endl;
        cout<<"2. Nasabah"<<endl;
        cout<<"3. Perusahaan"<<endl;
        if(first(LP) != NULL && first(LP) != NULL) {
            /** Hanya ditampilkan jika memiliki nasabah dan perusahaan **/
            cout<<"4. Bursa Award"<<endl;
        }
        cout<<"0. exit"<<endl;
        cout<<"input choice: ";
        cin>>choice;
        system("CLS");
        switch(choice) {
        case 1:
            /** menampilkan jumlah nasabah, investor, perusahaan, perusahaan yg memiliki investor
                dan menampilkan nasabah dengan perusahaan yang telah diinvestasikan **/
            if(first(LP) != NULL || first(LC) != NULL) {
                HitungNasabah(LP);
                HitungPerusahaan(LC,LP);
                cout<<endl;
                printAll(LP,LC);
            }
            break;
        case 2:
            cout<<"Menu"<<endl;
            cout<<"1. Tambah Nasabah"<<endl;
            if(first(LP) != NULL) {
                /** ditampilkan ketika memiliki setidaknya 1 nasabah **/
                cout<<"2. Hapus Nasabah"<<endl;
                cout<<"3. Deposit"<<endl;
                cout<<"4. Beli Saham"<<endl;
                cout<<"5. Jual Saham"<<endl;
                cout<<"6. Cek Saham"<<endl;
                cout<<"7. List Nasabah/Investor"<<endl;
            }
            cout<<"0. back"<<endl;
            cout<<"input choice: ";
            cin>>x;
            system("CLS");
            if (x == 1) {
                /** Tambah nasabah **/
                /** membuat data nasabah baru, dan dimasukan ke data **/
                n = CreateDataP(LP);
                P = alokasi(n);
                insertP(LP, P);
            } else if (x == 2 && first(LP) != NULL) {
                /** Hapus nasabah **/
                printP(LP);
                cout<<"ID Nasabah untuk dihapus ";
                cin>>x;
                P = findElm(LP,x);
                if(C != NULL) {
                    deleteP(LP,P);
                } else {
                    cout<<"ID Nasabah tidak ditemukan"<<endl;
                }
            } else if (x == 3 && first(LP) != NULL) {
                /** Deposit **/
                /** menambah deposito suatu nasabah **/
                printP(LP);
                cout<<endl<<"ID Nasabah: ";
                cin>>x;
                P = findElm(LP,x);
                if (P != NULL) {
                    cout<<"Deposito anda: "<<info(P).deposito<<endl;
                    cout<<"Deposit: ";
                    cin>>x;
                    info(P).deposito = info(P).deposito + x;
                } else {
                    cout<<"Nasabah tidak ditemukan"<<endl;
                }
            } else if (x == 4 && first(LP) != NULL) {
                /** beli saham **/
                /** aka Connect **/
                printP(LP);
                printInfo(LC);
                cout<<endl<<"ID Nasabah: ";
                cin>>x;
                P = findElm(LP,x);
                cout<<"ID Perusahaan: ";
                cin>>x;
                C = findElm(LC,x);
                beli(P,C);
            } else if (x == 5 && first(LP) != NULL) {
                /** Jual saham **/
                /** aka Disonnect **/
                printAll(LP,LC);
                cout<<"Find ID Nasabah: ";
                cin>>x;
                P = findElm(LP,x);
                cout<<"Find ID Perusahaan: ";
                cin>>x;
                C = findElm(LC,x);
                disconnect(P,C);
            } else if (x == 6 && first(LP) != NULL) {
                /** check saham **/
                /** mencari sebuah ID nasabah, lalu tampilkan perusahaan yang berkaitan **/
                printP(LP);
                cout<<endl<<"Cari ID Nasabah: ";
                cin>>x;
                P = findElm(LP,x);
                printOneP(P);
            } else if (x == 7 && first(LP) != NULL) {
                /** list nasabah/investor **/
                printP(LP);
            }
            break;
        case 3:
            cout<<"Menu"<<endl;
            cout<<"1. Tambah Perusahaan"<<endl;
            if(first(LC) != NULL) {
                /** Hanya ditampilkan ketika setidaknya memiliki 1 data perusahaan **/
                cout<<"2. Hapus Perusahaan"<<endl;
                cout<<"3. check investor"<<endl;
                cout<<"4. check connection"<<endl;
                cout<<"5. List Perusahaan"<<endl;
            }
            cout<<"0. exit"<<endl;
            cout<<"input choice: ";
            cin>>x;
            system("CLS");
            if (x == 1) {
                /** Tambah Data Perusahaan **/
                p = CreateDataC(LC);
                C = alokasi(p);
                insertC(LC, C);
            } else if (x == 2 && first(LC) != NULL) {
                /** Hapus Perusahaan **/
                printInfo(LC);
                cout<<endl<<"Input ID Perusahaan untuk dihapus: ";
                cin>>x;
                C = findElm(LC,x);
                if(C != NULL) {
                    deleteC(LP, LC, C);
                } else {
                    cout<<"ID Perusahaan tidak ditemukan"<<endl;
                }
            } else if (x == 3 && first(LC) != NULL) {
                /** check investor **/
                /** mencari ID perusahaan dan menampilkan investor yang dimiliki **/
                printInfo(LC);
                cout<<endl<<"Cari ID Perusahaan: ";
                cin>>x;
                C = findElm(LC,x);
                printOneC(C,LP);
            } else if (x == 4  && first(LC) != NULL) {
                /** mengecheck koneksi antara perusahaan dan nasabah **/
                printInfo(LC);
                cout<<"input ID Perusahaan: ";
                cin>>x;
                C = findElm(LC,x);
                cout<<endl;
                printP(LP);
                cout<<"input ID nasabah: ";
                cin>>x;
                P = findElm(LP,x);
                if(P != NULL && C != NULL) {
                    bool l;
                    l = CheckConnection(P,C);
                    cout<<endl<<endl;
                    if(l == true) {
                        cout<<"Berhubungan";
                    } else {
                        cout<<"Tidak berhubungan";
                    }
                }
                cout<<endl;
            } else if (x == 5  && first(LC) != NULL) {
                /** List Perusahaan **/
                printInfo(LC);
            }
            break;
        case 4:
            /** Menampilkan Top Investor(investor dengan investasi terbanyak)
                            Perusahaan Favorite(Perusahaan dengan jumlah investor terbanyak)**/
            cout<<"TOP Investor        : ";
            nasabahterbaik(LP);
            cout<<endl;
            cout<<"Perusahaan Favorite : ";
            perusahaanterfavorit(LP,LC);
            cout<<endl;
            break;
        }
        system("PAUSE");
        system("CLS");
    } while(choice != 0);
    cout<<endl;
    cout<<"<=--------------------------=>"<<endl<<endl;
    cout<<"         Goodbye from          "<<endl;
    cout<<"    Bursa Efek Opang Ahmad    "<<endl;
    cout<<"          [B.E.O.A]"<<endl<<endl;
    cout<<"<=--------------------------=>"<<endl<<endl<<endl;
}

int main() {
    DaReal();
    return 0;
}
