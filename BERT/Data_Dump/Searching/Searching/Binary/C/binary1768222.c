#include<stdio.h>

#define N 100000
#define M 50000

int n,s[N],t[M];

int binarySearch(int);

int main(){

  int q,i,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);

  }
  scanf("%d",&q);

    for(i=0;i<q;i++){

      scanf("%d",&t[i]);

      if(binarySearch(t[i])==1) {count++;}

    }

     printf("%d\n",count);

  return 0;
}

int binarySearch(int key){

  int left=0,right=n,mid;

  while (left<right){

    mid=(left+right)/2;

  if(s[mid]==key) return 1;

  else if(key<s[mid])
    right=mid;

  else left=mid+1;

  }

  return 0;
}
