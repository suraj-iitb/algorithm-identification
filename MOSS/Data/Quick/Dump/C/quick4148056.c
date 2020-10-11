#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000
#define INF 1000000000

typedef struct card{
    char simbol;
    int nmber;
}Card;

int nm;
Card A[N];
Card B[N];
Card L[N / 2 + 2];
Card R[N / 2 + 2];

/*void Babblesort(){
  int j, flag=1;
  Card temp;
  
  while(flag == 1){
    flag = 0;
    for(j = nm-1; j > 0; j--){
      if(A[j].nmber < A[j-1].nmber){
        temp = A[j];
        A[j]= A[j-1];
        A[j-1]= temp;

        flag = 1;
      }
    }
  }
  return ;
}*/

void merge(Card *A,int n, int l, int m, int r){
    int i, j, k;
    int n1 = m - l;
    int n2 = r - m;

    for(i = 0; i < n1; i++)L[i] = A[l + i];
    for(i = 0; i < n2; i++)R[i] = A[m + i];

    L[n1].nmber = R[n2].nmber = INF;
    i = j = 0;
    for(k = l; k < r; k++){
        if(L[i].nmber <= R[j].nmber){
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
        }
    }
}

void merges(Card *A, int n, int l, int r){
    int m;
    int i;
    if(l + 1 < r){
        m = (l+r) / 2;
        merges(A, n, l, m);
        merges(A, n, m, r);
        merge(A, n, l, m, r);
    }
}

int partition(int p, int r){
    int i, j, x;
    Card temp;
  x = B[r].nmber;
  i = p - 1;
  for(j = p; j <= r-1; j++){ 
    if(B[j].nmber <= x){
      i++;
        temp = B[i];
        B[i] = B[j];
        B[j] = temp;
    }
  }
    temp = B[i+1];
    B[i+1] = B[r];
    B[r] = temp;
    
  
  return i+1;
}

void quickSort(int p, int r){
    int q;
    if(p < r){
        q = partition(p, r);
        quickSort(p, q-1);
        quickSort(q+1, r);
    }
    return;
}

int compare(Card *A, Card *B){
    int i;
    for(i = 0; i < nm; i++){
        if(A[i].simbol != B[i].simbol || A[i].nmber != B[i].nmber) return 0;
    }
    return 1;
}

int main(){
    int i, j, n;

    scanf("%d", &nm);

    for(i = 0; i < nm; i++){
        scanf("%s %d", &A[i].simbol, &A[i].nmber);
        B[i].nmber = A[i].nmber;
        B[i].simbol = A[i].simbol;
    }

    quickSort(0, nm-1);
    merges(A, nm, 0, nm);
    

    if(compare(A, B) == 1) printf("Stable\n");
    else printf("Not stable\n");

    for(i = 0; i < nm; i++){
        printf("%c ", B[i].simbol);
        printf("%d\n", B[i].nmber);
    }

    return  0;
}
