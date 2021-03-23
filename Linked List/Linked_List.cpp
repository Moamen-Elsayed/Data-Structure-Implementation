#include <iostream>
using namespace std;

typedef int EleType;

typedef struct node{
    EleType data;
    struct node* next;
}Node;

typedef struct node* List;

int IsEmpty(List L){
    Node *P;
    P = L;
    return P == NULL;
}

EleType GetData(Node *P){
    return P->data;
}

Node* GetNext(Node *P){
    return P->next;
}

int IsLast(List L){
    Node *P;
    P = L;
    return P->next == NULL;
}

int Construct(List *L, EleType x){
    Node* P;
    P = (Node*) malloc(sizeof(Node));
    if(IsEmpty(P)){
        cout << "ERROR\n";
        return 0;
    }else{
        P->data = x;
        P->next = NULL;
        *L = P;
        return 1;
    }
}

void Destroy(List *L){
    Node *P, *Q;
    P = *L;
    while(!IsEmpty(P)){
        Q = P->next;
        free(P);
        P = Q;
    }
}

void PrintList(List L, int choice = 0){
    node *P;
    P = L;
    if(IsEmpty(P))
        cout << "EMPTY LIST\n";
    else{
        while(!IsEmpty(P)){
            if(choice == 0)
                cout << " " << GetData(P);

            P = GetNext(P);
        }
        cout << endl;
    }
}

int InsertRear(List *L, EleType X){
    Node *P, *Q;
    P = *L;
    while(!IsLast(P)){
        P = GetNext(P);
    }
    Q = (Node*) malloc(sizeof(Node));
    if(IsEmpty(Q)){
        cout << "ERROR\n";
        return 0;
    }
    Q->data = X;
    Q->next = NULL;
    P->next = Q;
    return 1;
}

int InsertFront(List *L, EleType X){
    Node *P;
    P = (Node*) malloc(sizeof(Node));
    if(IsEmpty(P)){
        cout << "ERROR\n";
        return 0;
    }
    P->data = X;
    P->next = *L;
    *L = P;
    return 1;
}

int InsertPos(List *L, EleType X, int pos){
    Node *P, *Q;
    int i, cnt=0;
    P = *L;
    while(!IsEmpty(P)){
        cnt++;
        P = GetNext(P);
    }
    if(pos > cnt || pos < 0){
        cout << "Position is too far or -ve value, list is: " << cnt << " element only \n";
        return 0;
    }else if(pos == cnt){
        int y;
        y = InsertRear(L, X);
        return y;
    }else if(pos == 0){
        int y;
        y = InsertFront(L, X);
        return y;
    }else{
        Q = (Node*) malloc(sizeof(Node));
        if(IsEmpty(Q)){
            cout << "ERROR\n";
            return 0;
        }
        Q->data = X;
        P = *L;
        for(i=0 ; i<pos-1 ; i++)
            P = GetNext(P);
        Q->next = P->next;
        P->next = Q;
        return 1;
    }
}

int DeleteRear(List *L, EleType *X){
    Node *P, *Q;
    P = *L;
    Q = GetNext(P);
    while(Q->next != NULL){
        P = GetNext(P);
        Q = GetNext(Q);
    }
    *X = GetData(Q);
    free(Q);
    P->next = NULL;
    return 1;
}

int DeleteFront(List *L, EleType *X){
    Node *P;
    P = *L;
    *L = P->next;
    *X = P->data;
    free(P);
    return 1;
}

int DeletePos(List *L, EleType *X, int pos){
    Node *P, *Q;
    int i, cnt=0;
    P = *L;
    while(!IsEmpty(P)){
        cnt++;
        P = GetNext(P);
    }
    if(pos > cnt || pos < 0){
        cout << "Position is too far or -ve value, list is: " << cnt << " element only \n";
        return 0;
    }else if(pos == cnt){
        int y;
        y = DeleteRear(L, X);
        return y;
    }else if(pos == 0){
        int y;
        y = DeleteFront(L, X);
        return y;
    }else{
        for(i=0 ; i<pos-1 ; i++)
            P = GetNext(P);
        Q = P->next;
        *X = Q->data;
        P->next = Q->next;
        free(Q);
        return 1;
    }
}

Node* Find(List L, EleType X){
    Node* P;
    P = L;
    while(P != NULL && P->data != X)
        P = GetNext(P);
    return P;
}

int Destroy(List L){
    Node* P, *Q;
    P = L;
    while(P != NULL){
        Q = P->next;
        free(P);
        P = Q;
    }
    return 1;

}



int main() {
    List L;
    Node *P;
    int i;
    EleType X;
    Construct(&L, 5);
    PrintList(L);
    for(i=1 ; i<3 ; i++){
        InsertRear(&L, i);
        InsertPos(&L, 1, 1);
        InsertFront(&L, i);
        InsertPos(&L, i, i+1);
    }
    PrintList(L);
    InsertPos(&L, 100, 6);
    PrintList(L);
    P = Find(L, 5);
    cout << "Ele = " << GetData(P) << endl;
    DeleteFront(&L, &X);
    PrintList(L);
    DeleteRear(&L, &X);
    PrintList(L);
    Destroy(&L);



    return 0;
}
