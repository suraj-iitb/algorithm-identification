#include<stdio.h>

int Binarysearch(int);

int S[100000],T[50000],n,q;

int main(){

  int i,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%d",&S[i]);

  }

  scanf("%d",&q);

  for(i=0;i<q;i++){

    scanf("%d",&T[i]);

  }

  for(i=0;i<q;i++){

    count+=Binarysearch(T[i]);

  }

  printf("%d\n",count);

  return 0;

}

int Binarysearch(int key){

  int left=0,right=n,mid;


  while(left<right){

    mid=(left+right)/2;

    if(key==S[mid])return 1;

    if(key>S[mid]) left=mid+1;

    else if(key<S[mid]) right=mid;

  }

  return 0;
}
