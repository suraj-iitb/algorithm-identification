#include<stdio.h>

int LinearSearch(int *,int);
int n,q;

int main(){
  int C[10000];
  int T[500];
  int i,j,a,c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d ",&C[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  for(j=0;j<q;j++){
    a = LinearSearch(&C[0],T[j]);
    c += a;
  }

 
  printf("%d\n",c);

  return 0;
}

int LinearSearch(int * A, int key){
  int i;

  for(i=0;i<n;i++){
    if(A[i]==key) return 1;
  }
    return 0;
}
  
