#include<stdio.h>

typedef struct{
    int num;
    char design;
    int rank;
}Card;

int Partition(Card[],int,int);
void Quicksort(Card[],int,int);
 
int main(){
 
    int n,i,stable=1;
    Card C1[100000];
 
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf(" %c%d", &C1[i].design, &C1[i].num);
        C1[i].rank = i;
    }

    Quicksort(C1,0,n - 1);

    for(i = 0; i < n -1; i++){
        if(C1[i].num == C1[i - 1].num && C1[i-1].rank > C1[i].rank && stable == 1){
            printf("Not stable\n");
            stable = 0;
        }
    }

    if(stable) printf("Stable\n");

    for(i = 0; i < n; i++){
        printf("%c %d\n",C1[i].design,C1[i].num);
    }
    return 0;
}
 
int Partition(Card A[],int p,int r){
    int x,i,j;
    Card tmp;
    x = A[r].num;
    i = p - 1;
    for(j = p; j < r; j++){
        if(A[j].num <= x){
          i++;
          tmp = A[i];
         A[i] = A[j];
         A[j] = tmp;
        }
    }
    tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp;

    return i + 1;
}
 
void Quicksort(Card A[],int p,int r){
    int q;
    if(p < r){
        q = Partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}
