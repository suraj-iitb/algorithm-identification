#include <stdio.h>
#include<stdlib.h>
struct Node{
    long long int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* listS;
long long int count;

void insertS(long long int data){
    struct Node* newN = (struct Node*)malloc(sizeof(struct Node));
    newN->data = data;
    newN->prev = NULL;
    newN->next = NULL;
    if(listS == NULL){
        listS = newN;
        return;
    }
    listS->prev = newN;
    newN->next = listS;
    listS = newN;
}
void findX(long long int x){
    struct Node* temp = listS;
    struct Node* p;
    struct Node* n;
    while(temp != NULL){
        if(temp->data == x){
            count++;
            p = temp->prev;
            n = temp->next;
            if(p == NULL && n == NULL) {
                listS = NULL;
                break;
            }
            if(p == NULL){
                listS = temp->next;
                listS->prev = NULL;
            }else p->next = n;
            if(n!=NULL)n->prev = p;
            break;
        }
        temp = temp->next;
    }
}

int main(){
    listS = NULL;

    long long int n, q, s, t, c;
    count = 0;
    scanf("%lld", &n);
    while(n--){
        scanf("%lld", &s);
        insertS(s);
    }
    scanf("%lld", &q);
    while(q--){
        scanf("%lld", &t);
        findX(t);
    }
    printf("%lld\n", count);
    return 0;
}

