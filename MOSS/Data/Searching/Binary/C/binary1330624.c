#include<stdio.h>

int S[1000000];
int T[1000000];
int Scount;
int Tcount;
int count;
int i,j;

int binarySearch(int);
int main(){


  scanf("%d",&Scount);

  for(count = 0;count < Scount;count++){
    scanf("%d",&S[count]);
  }

  scanf("%d",&Tcount);

  for(count = 0;count < Tcount;count++){
    scanf("%d",&T[count]);
  }
  count = 0;

  for(i = 0;i < Tcount;i++){
  if(binarySearch(T[i])==1)count++;
  }

  printf("%d\n",count);
  return 0;
}

int binarySearch(int key){
  int left;
  int right;
  int mid;

  left = 0;
  right = Scount;
  while(left < right){
    mid = (left+right)/2;
    if(S[mid]==key)return 1;
    else if(key < S[mid])right = mid;
    else left = mid + 1;
  }
  return 0;
}
