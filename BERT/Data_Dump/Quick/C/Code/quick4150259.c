#include <stdio.h>
#define MAX 100000
#define SETL 2000000000

typedef struct {
  char suit;
  int value;
} card;

card L[MAX/2+2],R[MAX/2+2];

void meg(card A[],int left,int mid,int right){
    int n1,n2,i,j,k;
    n1 = mid - left;
    n2 = right - mid;
    /* 配列L、Rに格納*/
    for(i=0;i<n1;i++){
        L[i] = A[left+i];
    }
    for(i=0;i<n2;i++){
        R[i] = A[mid+i];
    }
    L[n1].value = SETL; R[n2].value = SETL; i = 0; j = 0;
    for(k=left;k<right;k++){
        if(L[i].value <= R[j].value){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void megst(card A[],int left,int right){
    int mid;
    if(left+1 < right){
        mid = (left+right)/2;
        megst(A,left,mid);
        megst(A,mid,right);
        meg(A,left,mid,right);
    }
}

int Ption(card A[],int p,int r){
    int i,j;
    card x,cd;
    x = A[r]; i = p-1;
    for(j=p;j<r;j++){
        if(A[j].value <= x.value){
            i++;
            cd = A[j]; A[j] = A[i]; A[i] = cd;
        }
    }
    cd = A[r]; A[r] = A[i+1]; A[i+1] = cd;    return i+1;
}

void quicksort(card A[],int p,int r){
  int q;
  if(p<r){
    q = Ption(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

int main(){
  int n,i,v;
  card A[MAX],B[MAX];
  char S[10];
  int stable = 1;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",S,&v);
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = v;
  }
  
  megst(A,0,n);
  quicksort(B,0,n-1);

  for(i=0;i<n;i++){
    if(A[i].suit != B[i].suit) stable = 0;
  }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].suit,B[i].value);
  }

  return 0;
}

