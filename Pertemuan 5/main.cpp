#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);
    cout << boolalpha;
    cout << "List kosong (awal): " << ListEmpty(L) << '\n';
    int data[] = {2, 0, 8, 12, 9};
    for (int x : data) insertFirst(L, alokasi(x));
    cout << "List kosong (setelah insert): " << ListEmpty(L) << '\n';
    cout << "\nLATIHAN UTAMA\nData list: ";
    printInfo(L);
    address P = findElm(L, 15);
    if (P != Nil) cout << P->info << "ditemukan dalam list\n";
    else cout << "15 tidak ditemukan\n";
    cout << "Jumlah node: " << nbList(L) << '\n';
    cout << "Total info: " << totalInfo(L) << '\n';
    cout << "\nPENCARIAN LAIN\n";
    cout << boolalpha;
    cout << "Alamat P ada: " << fFindElm(L, P) << '\n';
    address Prec = findBefore(L, P);

    if (Prec != Nil) {
        cout << "Nilai sebelum 8: " << Prec->info << '\n';
    }
    cout << "20 ditemukan: "
              << (findElm(L, 20) != Nil) << '\n';
    cout << "\nUPDATE\n";
    updateInfo(L, 8, 80);
    printInfo(L);
    updateInfo(L, 80, 8);
    cout << "\nPENAMBAHAN\n";
    insertFirst(L, alokasi(7));
    insertLast(L, alokasi(4));
    insertAfter(L, alokasi(6), findElm(L, 8));
    printInfo(L);
    cout << "\nPENGHAPUSAN\n";
    P = Nil;
    delFirst(L, P);
    dealokasi(P);
    delLast(L, P);
    dealokasi(P);
    delAfter(L, P, findElm(L, 8));
    dealokasi(P);
    delP(L, 0);
    printInfo(L);
    cout << "\nPEMBALIKAN\n";
    invertList(L);
    printInfo(L);
    cout << "\nSALINAN MANDIRI\n";
    List salinan = fCopyList(L);
    updateInfo(salinan, 8, 88);
    cout << "Asli: ";
    printInfo(L);
    cout << "Salinan: ";
    printInfo(salinan);
    delAll(salinan);
    cout << "\nSALINAN BERBAGI NODE\n";
    List alias;
    CreateList(alias);
    copyList(L, alias);
    cout << "Node pertama sama: "
              << (L.first == alias.first) << '\n';
    updateInfo(alias, 8, 80);
    cout << "Asli ikut berubah: ";
    printInfo(L);
    updateInfo(alias, 80, 8);
    CreateList(alias); // Lepas alias; node tetap milik L.
    cout << "\nHAPUS SEMUA\n";
    delAll(L);
    printInfo(L);
    cout << "List kosong (akhir): " << ListEmpty(L) << '\n';
    return 0;
}