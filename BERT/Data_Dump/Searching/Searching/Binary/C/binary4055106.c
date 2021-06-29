#include<stdio.h>
int BinarySearch(int*,int,int);
int main(){
  int n,qtw,i,keytw,ans=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&qtw);
  for(i=0;i<qtw;i++){
    scanf("%d",&keytw);
    if(BinarySearch(S,n,keytw)==1)ans++;
  }
  printf("%d\n",ans);
  return 0;
}

int BinarySearch(int *S,int n,int key){
  int left=0,right=n;
  while(left<right){
    int mid=(left+right)/2;
    if(S[mid]==key)return 1;
    else if(key<S[mid])right=mid;
    else left=mid+1;
  }
  return 0;
}
      


