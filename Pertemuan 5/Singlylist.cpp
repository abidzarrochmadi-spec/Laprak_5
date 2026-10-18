#include "Singlylist.h"
#include <iostream>
bool ListEmpty(List L) {
    return L.first == Nil;
}
void CreateList(List& L) {
    L.first = Nil;
}
address alokasi(infotype X) {
    return new ElmList{X, Nil};
}
void dealokasi(address& P) {
    delete P;
    P = Nil;
}
address findElm(List L, infotype X) {
    address P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}
bool fFindElm(List L, address P) {
    for (address Q = L.first; Q != Nil; Q = Q->next) {
        if (Q == P) return true;
    }
    return false;
}
address findBefore(List L, address P) {
    if (P == Nil || P == L.first) return Nil;
    address Q = L.first;
    while (Q != Nil && Q->next != P) {
        Q = Q->next;
    }
    return Q;
}
void insertFirst(List& L, address P) {
    if (P == Nil) return;
    P->next = L.first;
    L.first = P;
}
void insertAfter(List& L, address P, address Prec) {
    if (P == Nil || !fFindElm(L, Prec)) return;
    P->next = Prec->next;
    Prec->next = P;
}
void insertLast(List& L, address P) {
    if (P == Nil) return;
    P->next = Nil;
    if (ListEmpty(L)) {
        L.first = P;
        return;
    }
    address Q = L.first;
    while (Q->next != Nil) Q = Q->next;
    Q->next = P;
}
void delFirst(List& L, address& P) {
    P = Nil;
    if (ListEmpty(L)) return;
    P = L.first;
    L.first = P->next;
    P->next = Nil;
}
void delLast(List& L, address& P) {
    P = Nil;
    if (ListEmpty(L)) return;
    if (L.first->next == Nil) {
        delFirst(L, P);
        return;
    }
    address Q = L.first;
    while (Q->next->next != Nil) Q = Q->next;
    P = Q->next;
    Q->next = Nil;
}
void delAfter(List& L, address& P, address Prec) {
    P = Nil;
    if (!fFindElm(L, Prec)) return;
    P = Prec->next;
    if (P != Nil) {
        Prec->next = P->next;
        P->next = Nil;
    }
}
void delP(List& L, infotype X) {
    address target = findElm(L, X);
    if (target == Nil) return;
    address P = Nil;
    if (target == L.first) {
        delFirst(L, P);
    } else {
        delAfter(L, P, findBefore(L, target));
    }
    dealokasi(P);
}
void printInfo(List L) {
    if (ListEmpty(L)) {
        std::cout << "(kosong)\n";
        return;
    }
    for (address P = L.first; P != Nil; P = P->next) {
        std::cout << P->info;
        if (P->next != Nil) std::cout << ' ';
    }
    std::cout << '\n';
}
int nbList(List L) {
    int jumlah = 0;
    for (address P = L.first; P != Nil; P = P->next) {
        ++jumlah;
    }
    return jumlah;
}
long long totalInfo(List L) {
    long long total = 0;
    for (address P = L.first; P != Nil; P = P->next) {
        total += P->info;
    }
    return total;
}
bool updateInfo(List& L, infotype lama, infotype baru) {
    address P = findElm(L, lama);
    if (P == Nil) return false;
    P->info = baru;
    return true;
}
void delAll(List& L) {
    address P = Nil;
    while (!ListEmpty(L)) {
        delFirst(L, P);
        dealokasi(P);
    }
}
void invertList(List& L) {
    address sebelum = Nil;
    address sekarang = L.first;
    while (sekarang != Nil) {
        address sesudah = sekarang->next;
        sekarang->next = sebelum;
        sebelum = sekarang;
        sekarang = sesudah;
    }
    L.first = sebelum;
}
// L2 harus kosong; hasilnya memakai node milik L1.
void copyList(List L1, List& L2) {
    L2.first = L1.first;
}
// Salinan mandiri: setiap node dibuat ulang.
List fCopyList(List L) {
    List hasil;
    CreateList(hasil);
    address tail = Nil;
    try {
        for (address P = L.first; P != Nil; P = P->next) {
            address baru = alokasi(P->info);
            if (tail == Nil) hasil.first = baru;
            else tail->next = baru;
            tail = baru;
        }
    } catch (...) {
        delAll(hasil);
        throw;
    }
    return hasil;
}