#include <stdio.h>

#define MAX 100000
#define INFTY 100000000

typedef struct{
  char suit;
  int num;
}Card;

void quicksort(Card *,int,int);
int partition(Card *,int,int);
void merge(Card *,int,int,int);
void mergesort(Card *,int,int);
void swap(Card *,Card *);

Card L[MAX/2 + 2],R[MAX/2 + 2];

int main(){
  Card c1[MAX],c2[MAX];
  int i,n,v;
  char P[20];
  int stable = 1;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",P,&v);
    c2[i].suit = c1[i].suit = P[0];
    c2[i].num = c1[i].num = v;
  }
  
  mergesort(c1,0,n);
  quicksort(c2,0,n-1);

  for(i=0;i<n;i++){
    if(c1[i].suit != c2[i].suit)stable = 0;
  }
  
  if(stable == 1)printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",c2[i].suit,c2[i].num);
  }

 
          
  return 0;
}


void merge(Card A[],int left,int mid,int right){
  int n1=0;
  int n2=0;
  int i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<=n1;i++)L[i]=A[left + i];
  for(i=0;i<=n2;i++)R[i]=A[mid + i];

  L[n1].num =INFTY;
  R[n2].num =INFTY;

  i=j=0;
  for(k=left;k<right;k++){
    
    if(L[i].num <= R[j].num){
      A[k]=L[i++];
    }

    else {
      A[k]=R[j++];
    }
  }
}

void mergesort(Card A[],int left,int right){
  int mid=0;

  if(left + 1 < right){
    mid = (left + right) / 2;

    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}


void swap(Card *in,Card *out){
  Card temp;

  temp = *in;
  *in = *out;
  *out = temp;
}

int partition(Card A[],int p,int r){
  Card x;
  int i=0;
  int j;
   
  x = A[r];
  i = p-1;

  for(j=p;j<r;j++){
    if(A[j].num <= x.num){
      i = i+1;
      swap(&A[i],&A[j]);

    }
  }
  swap(&A[i+1],&A[r]);
  
  return i+1;
}

void quicksort(Card A[],int p,int r){
  int q;

  if(p<r){
    q = partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

