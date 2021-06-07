#include<stdio.h>
#define N 100000
#define Q 50000
int binarySearch(int,int,int*);

int main(){
  int n,q,i,c = 0;
  int S[N],T[Q];
  
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
    c += binarySearch(n,T[i],S);
  }
  printf("%d\n",c);
  
  return 0;
}

int binarySearch(int n,int key,int a[]){
  int left = 0,right = n,mid;
  
  while(left < right){
    mid = (left + right)/2;
    if(a[mid] == key){
      return 1;
    }
    else if(key < a[mid]){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
  return 0;
}
