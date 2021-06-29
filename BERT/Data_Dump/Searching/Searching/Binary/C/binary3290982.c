#include<stdio.h>
int binarysearch(int *,int,int);

int main(){
  int n,q,i,key,result=0;
  int s[100000+1];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&key);
    if(binarysearch(s,n,key)!=0) result++;
  }
  printf("%d\n",result);
  return 0;
}

int binarysearch(int s[],int n,int key){
  int left=0;
  int right=n;
  int mid;

  while(left<right){
    mid=(left+right)/2;
    if(key==s[mid]){
      return 1;
    }//keyをみつけたとき真を返す

    if(key<s[mid]){
      right=mid;
    }//keyがmidよりちいさいときみつけたい値は前にあるので、rightをmidとする
    
    if(key>s[mid]){
      left=mid+1;
    }
  }
  return 0;
}
		   

