#include<stdio.h>
int binarySerch(int *,int , int );
int main(){
  int a,b,i,k=0,s[100000],key;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&key);
    k+=binarySerch(s,a,key);
  }
  printf("%d\n",k);
  return 0;
}
int binarySerch(int *s,int n,int key){
  int kai=0,left=0,right,mid;
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(s[mid]==key)return 1;
    else if(key<s[mid]){
      right = mid;
    }
    else{
      left=mid+1;
    }     
  }
  return 0;
}

