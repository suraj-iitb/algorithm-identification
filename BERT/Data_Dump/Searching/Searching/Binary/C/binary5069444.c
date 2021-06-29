#include<stdio.h>
#define N 100000
#define Q 50000

int binarySearch(int);

int S[N];
int T[Q];
int n;

int main(){

  int count=0,i,q;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    count= count + binarySearch(T[i]);
  }

  printf("%d\n",count);

  return 0;
}

int binarySearch(int x){

  int left=0,right=n,mid;

  while(left<right){
    mid=(left + right)/2;
    if(x==S[mid])return 1;
    if(x >S[mid])left=mid+1;
    else if(x <S[mid])right =mid;
  }
  return 0;    

}

