#include <stdio.h>
#define MAX 2000000

void countingSort(int,int);
int a[MAX],b[MAX];

int main(){
  
  int i,n,k=0;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&a[i+1]);
    if(a[i+1]>k) k=a[i+1];
  }

  countingSort(k,n);

  for(i=0;i<n;i++){
    if(i==0) printf("%d",b[i+1]);
    else printf(" %d",b[i+1]);
  }
  printf("\n");

  return 0;
}

void countingSort(int k,int n){
  int i,j,c[MAX];

  for(i=0;i<k+1;i++){
    c[i]=0;
  }

  for(j=1;j<n+1;j++){
    c[a[j]]++;
  }

  for(i=1;i<k+1;i++){
    c[i] = c[i]+c[i-1];
  }
  
  for(j=n;j>0;j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }
}
