#include <stdio.h>

int n;
int A[1000];
void print(){
  int i;
  for(i=0;i<n;i++){
    if(i!=n-1)printf("%d ",A[i]);
    else printf("%d",A[i]);
  }
  printf("\n");
}

void insertion(){
  int i;
  int v,j;
  for(i=1;i<n;i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    print();
  }
}

int main(){
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  print();
  insertion();
  return 0;
}
