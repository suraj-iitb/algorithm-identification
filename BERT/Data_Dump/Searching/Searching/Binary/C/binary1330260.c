#include<stdio.h>
int binarySearch(int[],int,int);

main(){
  int i,n,q;
  int res=0;
  int S[100000];
  int T[50000];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }



  for(i=0;i<q;i++){
    if(binarySearch(S,T[i],n)==0) res++;
  }

  printf("%d\n",res);



  return 0;
}

int binarySearch(int S[],int key,int n){
  int left=0;
  int right=n;
  int mid;

  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key) return 0;
    else if(key<S[mid]) right=mid;
    else left=mid+1;
  }
  return 1;
}
