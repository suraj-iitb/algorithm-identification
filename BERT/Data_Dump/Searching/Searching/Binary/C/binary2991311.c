#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int*, int, int);

int main(){
  int i,j,n,q,c=0;
  int *S,*T;

  scanf("%d",&n);
  S=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  T=(int *)malloc(q*sizeof(int));
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    c+=BinarySearch(S,T[i],n);
  }

  printf("%d\n",c);
 
  return 0;

}

int BinarySearch(int *x,int key,int n){
  int mid,max,min=0;

  max=n;

  while(min<max){
    mid=(min+max)/2;
    if(key==x[mid]){
      return 1;
    }
    if(key>x[mid]){
      min=mid+1;
    }
    else if(key<x[mid]){
      max=mid;
    }
  }

  return 0;
}
      

