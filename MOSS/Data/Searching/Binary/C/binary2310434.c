#include <stdio.h>
int Bsearch(int[],int,int);
int main(){
  int i,j,n,A[100000+1],sum=0,key;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  

  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%d",&key);
    if(Bsearch(A,n,key))sum++;
  }
  printf("%d\n",sum);
  return 0;
}

int Bsearch(int A[],int n,int key){
  int r=n;
  int l=0;
  int m;
  while(l<r){
    m=(l+r)/2;
    if(key==A[m])return 1;
    else if(key>A[m])l=m+1;
    else  r=m;
  }
  return 0;
}


  

 
