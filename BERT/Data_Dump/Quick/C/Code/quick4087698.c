#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100000
#define INFTY 1000000001

typedef struct{
  char suit;
  int num;
}P;

void merge(P *,int,int,int);
void mergeSort(P *,int,int);
void quicksort(P *,int,int);
int partition(P *,int,int);

P L[N],R[N];

int main(){
  int n,i;
  int flag=1;
  P A[N],B[N];

  scanf("%d ",&n);

  for(i=0;i<n;i++){
    scanf("%c %d ",&A[i].suit,&A[i].num);
    B[i].suit=A[i].suit;
    B[i].num=A[i].num;
  }

  mergeSort(A,0,n);
  quicksort(B,0,n-1);

for(i=0;i<n;i++){
  if(A[i].suit!=B[i].suit){
    flag=0;
  }
}
if(flag==1){
  printf("Stable\n");
}
else{
  printf("Not stable\n");
}

  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].suit,B[i].num);
  }

  return 0;
}

void quicksort(P *B,int p,int r){
  int q;
   if (p < r){
     q = partition(B, p, r);

     quicksort(B, p, q-1);
     quicksort(B, q+1, r);
  }}

  int partition(P *B,int p,int r){
    int i,j;
    P x,temp;
     x = B[r];
     i = p-1;
    for (j=p;j<r;j++){
       if (B[j].num <= x.num){
         i = i+1;
         temp=B[i];
         B[i]=B[j];
         B[j]=temp;
       }

       /* A[i] と A[j] を交換*/
     }


     temp=B[i+1];
     B[i+1]=B[r];
     B[r]=temp;
     /*A[i+1] と A[r] を交換*/
     return i+1;
   }

   void merge(P *A,int left,int mid,int right){
     int n1,n2,i,j,k;
     n1=mid-left;
     n2=right-mid;

     for(i=0;i<n1;i++){
       L[i]=A[left+i];
     }
     for(i=0;i<n2;i++){
       R[i]=A[mid+i];
     }
     L[n1].num=INFTY;
     R[n2].num=INFTY;
     i=0;
     j=0;

     for(k=left;k<right;k++){
       if(L[i].num<=R[j].num){
         A[k]=L[i];
         i=i+1;
       }
       else{
         A[k]=R[j];
         j=j+1;
       }
     }
   }

   void mergeSort(P *A,int left,int right){
     int mid;
     if(left+1<right){
       mid=(left+right)/2;
       mergeSort(A,left,mid);
       mergeSort(A,mid,right);
       merge(A,left,mid,right);
     }
   }

