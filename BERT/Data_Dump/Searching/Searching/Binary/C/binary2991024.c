#include<stdio.h>

int S[1000000],n;
int binarySearch(int);


int binarySearch(int key){
  int l=0;
  int r=n;
  int mid;
  while(l<r){
    mid=(l+r)/2;
    if(key==S[mid])return 1;
    if(key>S[mid])l=mid+1;
    else if(key<S[mid])r=mid;
  }
  return 0;
}


int main(){
  int a,q,T[1000000],sum=0;


  scanf("%d",&n);
  for(a=0;a<n;a++){
    scanf("%d",&S[a]);
  }



  scanf("%d",&q);
  
  for(a=0;a<q;a++){
    scanf("%d",&T[a]);
    if(binarySearch(T[a]))sum++;
  }
  
  printf("%d\n",sum);


  return 0;
  
}

  

