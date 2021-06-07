#include<stdio.h>
#define N 500000
 
int A[N],n,n1,number,count;
 
int searchNumber(int);
 
int main(){
 
  int i,j,T[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
 
  scanf("%d",&n1);

  for(i=0;i<n1;i++){
    scanf("%d",&T[i]);
    number = searchNumber(T[i]);
    if( number != -1 ){
      count++;
    }
  }
 
  printf("%d\n",count);
  return 0;
}

int searchNumber(int key){
  int left,right,mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(A[mid] == key){
      return A[mid];
    }
    else if(key < A[mid]){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
  return -1;
}
