#include <stdio.h>
typedef struct{
  char mark[2];
  int value;
  int moji;
} Card;
 
int partition(Card*, int, int);
void quickSort(Card*,int ,int);
 
 
int main(){
  Card A[100001];
   int n,i,stb = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%s %d",A[i].mark, &A[i].value);
    A[i].moji = i + 1;
  }
  
 quickSort(A, 0, n - 1);
 
  for(i = 0; i < n; i++){
     if(A[i].moji > A[i + 1].moji && A[i].value == A[i + 1].value){
      stb++;
      break;
    }
   }
   if(stb == 0) {
     printf("Stable\n");
   }
   else { 
     printf("Not stable\n");
   }  
   for(i = 0; i < n; i++) {
     printf("%s %d\n",A[i].mark, A[i].value);
   }  
   return 0;
   
   
}
void quickSort(Card *A,int p,int r){
   
  int q;
  if (p < r){
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
   
   
 
   
}
 
int partition(Card *A,int p,int r){
  int i, j, a;
  Card x;
   
  a = A[r].value;
  i = p - 1;
  for(j = p; j < r; j++){
    if(A[j].value <= a){
      i++;
      x = A[i];
      A[i] = A[j];
      A[j] = x;
    }
  }
  x = A[i + 1];
  A[i + 1] = A[r];
  A[r] = x;
   
  return i + 1;
}
