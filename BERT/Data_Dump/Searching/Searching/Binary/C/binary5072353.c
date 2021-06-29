#include<stdio.h>
int BS(int);
int n,q,cnt=0;
int S[1000000],T[50000];
int main(){
  int i,j,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(j=0;j<q;j++){
    k=BS(j);
  }
  printf("%d\n",cnt);

  return 0;
}
int BS(int j){
  int first=0,last=n,mid,key;
  key=T[j];
  while(first<last){
    mid=(first+last)/2;
    if(S[mid]==key){
      cnt++;
      return 0;
    }
    else if(key<S[mid]){
      last=mid;
    }
    else first=mid+1;
  }
  return 0;
}
