#include <stdio.h>
#include <string.h>

#define INFTY 2000000000

typedef struct{
  char mark;
  int num;
} Card;

int partition(Card *,int,int);
void quicksort(Card *,int,int);
void merge(Card *,int,int,int);
void mergeSort(Card *,int,int);

int main(){
  Card C[100000],B[100000],k;/*C、クイック　B、マージ*/
  int c,i,j,n,result = 0,flag = 1;
  char kaigyou,E[1];
  
  scanf("%d%c",&n,&kaigyou);
  if(n < 1 || n > 100000)return 0;
   
   for(i = 0; i < n; i++){
     scanf("%c%d%c",&C[i].mark,&C[i].num,&kaigyou);
     if(C[i].num < 0 || C[i].num > 1000000000)return 0;
     B[i] = C[i];
   }
  
   quicksort(C,0,n-1);
   mergeSort(B,0,n);
  

   /*安定かどうか判定*/
   for(i = 0;i < n; i++){
     if(strcmp(&C[i].mark,&B[i].mark)!=0){
       result = 1;
       break;
     }
   }
   /*出力*/
 if(result == 0)printf("Stable\n");
 else printf("Not stable\n");

  for(i = 0; i < n; i++){
    printf("%c %d\n",C[i].mark,C[i].num);
  }
   
   return 0;
}

int partition(Card A[],int p,int r){
  int i,j,x;
  Card y;
  i = p-1;
  x = A[r].num;
  
  for(j = p; j < r;j++){
    if(A[j].num <= x){    
      i += 1;
      y = A[j];
      A[j] = A[i];
      A[i] = y;
    }
  }
  y = A[i+1];
  A[i+1] = A[r];
  A[r] = y;

  return i+1;
}

void quicksort(Card A[],int p,int r){
  int q;
  if(p < r){
    q = partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

void merge(Card s[],int left,int mid,int right){
  int i = 0,j = 0,k,n1,n2;
  Card L[50001],R[50001];
 
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0;i < n1;i++){
    L[i] = s[left + i];
  }
  for(i = 0;i < n2;i++){
    R[i] = s[mid + i];
  }
  L[n1].num = INFTY;
  R[n2].num = INFTY;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    if(L[i].num <= R[j].num){
      s[k] = L[i];
      i += 1;
     
    }
    else{
      s[k] = R[j];
      j += 1;
    
    }
  }
}

void mergeSort(Card s[],int left,int right){
  int mid;
 
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(s,left,mid);
    mergeSort(s,mid,right);
    merge(s,left,mid,right);
  }
  
}


