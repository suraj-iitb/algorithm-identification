#include<stdio.h>

int N,s[100000];

int binarySearch(int key){
  int left=0;
  int right=N;
  int mid;

  while(left<right){
    mid=(left+right)/2;
    if(key==s[mid])return 1;
    if(key>s[mid])left=mid+1;
    else if(key<s[mid])right=mid;
  }
  return 0;
}

int main(){

  int i,key,N2,c=0;
  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&N2);

  for(i=0;i<N2;i++){
    scanf("%d",&key);
    if(binarySearch(key))c++;

  }

  printf("%d\n",c);


  return 0;
}
