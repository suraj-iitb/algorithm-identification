#include<stdio.h>
#define N 100000
  
struct sort{
  int number;
  char name;
  int key;
};
  
 struct sort A[N];
  
int Partition(int p, int r){
  int i,j;
  struct sort x,tmp;
  x.number = A[r].number;
  i = p -1;
  for(j = p; j <= r-1; j++){
    if(A[j].number <= x.number){
      i = i + 1;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i + 1];
  A[i+1] = A[r];
  A[r] = tmp;
    
  return i + 1;
}
  
void Quicksort(int p, int r){
  int q;
  if(p < r){
    q =  Partition(p, r);
    Quicksort(p, q-1);
    Quicksort(q+1, r);
  }
}
  
  
  
  
  
main(){
  
  int i, l,n,h=0;
  char ch0,ch1,ch2;
  scanf("%d%c",&n,&ch2);
  for(i = 1; i<=n; i++){
    scanf("%c%c%d%c",&A[i].name,&ch0,&A[i].number,&ch1);
    A[i].key = i;
  }
    
  l = Partition(1, n);
  Quicksort(1,n);
  for(i = 1; i <n; i++){
    if(A[i].key > A[i+1].key && A[i].number == A[i+1].number){
      h = 1;
      break;
    }
  }
    if(h!=1){
      printf("Stable\n");
    }
    if(h == 1){
      printf("Not stable\n");
    }
    
  
  for(i = 1; i<=n; i++){
    printf("%c %d\n",A[i].name,A[i].number);
  }
  return 0;
}
