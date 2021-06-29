#include<stdio.h>
#include<stdlib.h>
#define N 100000
  typedef struct{
    int num;
    char mark;
    int rank;
  }card;
int Partition(card[],int,int);
void Quicksort(card[],int,int);
 
 
int main(){
 
  int n,i,flag=0;
  char a;
  card card1[N];
 
  scanf("%d%c",&n,&a);
  for(i = 0; i < n; i++){
    scanf("%c%d%c",&card1[i].mark,&card1[i].num,&a);
    card1[i].rank = i + 1;
  }
  Quicksort(card1,0,n - 1);
  for(i = 0; i < n -1; i++){
    if(card1[i].num == card1[i + 1].num && card1[i].rank > card1[i + 1].rank && flag == 0){
      printf("Not stable\n");
      flag = 1;
    }
  }
    if(flag == 0) printf("Stable\n");
  for(i = 0; i < n; i++){
    printf("%c %d\n",card1[i].mark,card1[i].num);
  }
  return 0;
}
 
int Partition(card A[],int p,int r){
 
  int x,i,j;
  card tmp;
 
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
 
void Quicksort(card A[],int p,int r){
 
  int q;
 
  if(p < r){
    q = Partition(A,p,r);
    Quicksort(A,p,q-1);
    Quicksort(A,q+1,r);
  }
}
