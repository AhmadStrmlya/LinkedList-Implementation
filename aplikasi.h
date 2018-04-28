#ifndef APLIKASI_H_INCLUDED
#define APLIKASI_H_INCLUDED

#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

void deleteC(List_parent &F, List_child &L, address_child P);
void insertR(List_relasi &L, address_parent Q, address_relasi P);
bool CheckConnection(address_parent P, address_child C);
void beli(address_parent P, address_child C);
void HitungNasabah(List_parent L);
void HitungPerusahaan(List_child L, List_parent F);
void nasabahterbaik(List_parent L);
void perusahaanterfavorit(List_parent L, List_child F);
void printOneC(address_child P, List_parent L);
void DataDummy(List_child &LC, List_parent &LP);
void disconnect(address_parent P, address_child C);

#endif // APLIKASI_H_INCLUDED
