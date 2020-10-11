#include<stdio.h>
 
typedef struct{
    char c;
    int d;
}Card;
 
void setCard(Card *card, char a, int b){
    card->c = a;
    card->d = b;
    return;
}
 
void swapCard(Card *a1, Card *a2){
    Card temp;
    setCard(&temp, a1->c, a1->d);
    setCard(a1, a2->c, a2->d);
    setCard(a2, temp.c, temp.d);
    return;
}
 
int partition(Card A[], int p, int r){
    int x = A[r-1].d;
    int i = p-1, j;
    for( j = p; j < r-1; j++ ){
        if( A[j].d <= x ){
            i++;
            swapCard(&A[i], &A[j]);
        }
    }
    swapCard(&A[i+1], &A[r-1]);
    return i+1;
}
 
void quick(Card A[], int p, int r){
    if( p < r ){
        int q = partition(A, p, r);
        quick(A, p, q);
        quick(A, q+1, r);
    }
    return;
}
 
int main(){
    int n, i, j, isStable = 1;
    char t;
    Card card[100000], iCard[100000];
    scanf("%d", &n);
    scanf("%c", &t);
    for( i = 0; i < n; i++ ){
        scanf("%c %d", &card[i].c, &card[i].d);
        setCard(&iCard[i], card[i].c, card[i].d);
        scanf("%c", &t);
    }
    quick(card, 0, n);
    int bv = -1;
    for( i = 0; i < n; i++ ){
        if( card[i].d != bv ){ j = 0; }
        bv = card[i].d;
        for( ; j < n; j++ ){
            if( card[i].d == iCard[j].d ){
                if( card[i].c == iCard[j].c ){
                    j++;
                    break;
                }else{
                    isStable = 0;
                    break;
                }
            }
        }
    }
    printf("%s\n", (isStable?"Stable":"Not stable"));
    for( i = 0; i < n; i++ ){
      printf("%c %d\n", card[i].c, card[i].d);
    }
    return 0;
}
