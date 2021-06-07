#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define N 100000

int bs(int *,int,int);


int main(){
  int i,n,key,q,S[N];
  int cnt=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %d",&S[i]);
  }

  scanf(" %d",&q);

  for(i=0;i<q;i++){
    scanf(" %d",&key);
    if(bs(S,n,key)==1){
      cnt++;
    }
  }
  printf("%d\n",cnt);

  return 0;
}

int bs(int *S,int n,int key){
  int left,right,mid;
    left = 0;
    right = n;
    while(left < right){

        mid = (left + right) / 2;
        if (S[mid] == key){
          return 1;
          }
        else if (key < S[mid]){
            right = mid;
          }
        else {
            left = mid + 1;
          }
    }
return 0;
}

