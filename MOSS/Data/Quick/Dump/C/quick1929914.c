#include <stdio.h>
typedef struct{
  char c;
  int num;
  int count;
} Card;

void quickSort(Card [],int,int);
int partition(Card [],int,int);

int main(){

  int i,j,n,k,l,flag=0;
  Card card[100000];
  Card card2[100000];

  scanf("%d",&n);

 for(i=0;i<n;i++){
   scanf(" %c %d",&card[i].c, &card[i].num);
   card[i].count = i;
 }

 quickSort(card,0,n-1);


 for(i=1;i<n;i++){
   if(card[i-1].num == card[i].num && card[i-1].count > card[i].count){
     flag = 1;
   }
 }
 if(flag == 1){
   printf("Not stable\n");
 }
 else{
   printf("Stable\n");
 }

 for(i=0;i<n;i++){
   printf("%c %d\n",card[i].c,card[i].num);
 }

 return 0;
}

void quickSort(Card A[],int p,int r){

  int q;

  if(p < r){
    q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

int partition(Card A[],int p,int r){

  int  i,j,x;
  Card temp;

  x = A[r].num;
  i = p-1;
  for(j=p;j<r;j++){
    if(A[j].num <= x){
      i = i+1;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;
  return i+1;
}
