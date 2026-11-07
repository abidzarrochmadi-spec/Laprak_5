
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil nullptr

typedef int infotype;

struct ElmtList {
    infotype info;
    ElmtList* next;
};

typedef ElmtList* address;

struct List {
    address first;
};

inline void CreateList(List &L) {
    L.first = Nil;
}

inline bool ListEmpty(List L) {
    return L.first == Nil;
}

inline address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = Nil;
    return P;
}

inline void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

inline void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

inline void insertLast(List &L, address P) {
    if (ListEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

inline void insertAfter(List &L, address P, address Prec) {
    if (Prec != Nil && P != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

inline void printInfo(List L) {
    address P = L.first;

    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << " -> ";
        }
        P = P->next;
    }

    cout << endl;
}

inline address findElm(List L, infotype x) {
    address P = L.first;

    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }

    return Nil;
}

inline int nbList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != Nil) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

inline int totalInfo(List L) {
    int total = 0;
    address P = L.first;

    while (P != Nil) {
        total += P->info;
        P = P->next;
    }

    return total;
}

inline bool fFindElm(List L, address P) {
    address Q = L.first;

    while (Q != Nil) {
        if (Q == P) {
            return true;
        }
        Q = Q->next;
    }

    return false;
}

inline address findBefore(List L, address P) {
    if (P == Nil || L.first == Nil || P == L.first) {
        return Nil;
    }

    address Q = L.first;

    while (Q->next != Nil) {
        if (Q->next == P) {
            return Q;
        }
        Q = Q->next;
    }

    return Nil;
}

inline void updateInfo(List &L, infotype oldInfo, infotype newInfo) {
    address P = findElm(L, oldInfo);

    if (P != Nil) {
        P->info = newInfo;
    }
}

inline void delFirst(List &L, address &P) {
    if (!ListEmpty(L)) {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

inline void delLast(List &L, address &P) {
    if (ListEmpty(L)) {
        P = Nil;
        return;
    }

    if (L.first->next == Nil) {
        P = L.first;
        L.first = Nil;
        P->next = Nil;
        return;
    }

    address Q = L.first;

    while (Q->next->next != Nil) {
        Q = Q->next;
    }

    P = Q->next;
    Q->next = Nil;
}

inline void delAfter(List &L, address &P, address Prec) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
}

inline void delP(List &L, infotype x) {
    address P = findElm(L, x);

    if (P == Nil) {
        return;
    }

    if (P == L.first) {
        L.first = P->next;
        dealokasi(P);
        return;
    }

    address Prec = findBefore(L, P);

    if (Prec != Nil) {
        Prec->next = P->next;
        dealokasi(P);
    }
}

inline void invertList(List &L) {
    address Prev = Nil;
    address Curr = L.first;
    address Next = Nil;

    while (Curr != Nil) {
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }

    L.first = Prev;
}

inline List fCopyList(List L) {
    List hasil;
    CreateList(hasil);

    address P = L.first;

    while (P != Nil) {
        insertLast(hasil, alokasi(P->info));
        P = P->next;
    }

    return hasil;
}

inline void copyList(List L1, List &L2) {
    L2.first = L1.first;
}

inline void delAll(List &L) {
    address P;

    while (!ListEmpty(L)) {
        delFirst(L, P);
        dealokasi(P);
    }
}

#endif
