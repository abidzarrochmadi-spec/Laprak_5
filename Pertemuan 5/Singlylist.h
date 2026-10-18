#ifndef SINGLYLIST_H
#define SINGLYLIST_H
using infotype = int;
struct ElmList {
    infotype info;
    ElmList* next;
};
using address = ElmList*;
constexpr address Nil = nullptr;
struct List {
    address first;
};
bool ListEmpty(List L);
void CreateList(List& L);
address alokasi(infotype X);
void dealokasi(address& P);
address findElm(List L, infotype X);
bool fFindElm(List L, address P);
address findBefore(List L, address P);
void insertFirst(List& L, address P);
void insertAfter(List& L, address P, address Prec);
void insertLast(List& L, address P);
void delFirst(List& L, address& P);
void delLast(List& L, address& P);
void delAfter(List& L, address& P, address Prec);
void delP(List& L, infotype X);
void printInfo(List L);
int nbList(List L);
long long totalInfo(List L);
bool updateInfo(List& L, infotype lama, infotype baru);
void delAll(List& L);
void invertList(List& L);
void copyList(List L1, List& L2);
List fCopyList(List L);

#endif