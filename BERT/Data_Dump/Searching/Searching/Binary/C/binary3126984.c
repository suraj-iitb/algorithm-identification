#include<stdio.h>
int binarySearch(int A[],int ,int);
int main(){
  int a,b,A[100000],B[100000],count=0,c;
  scanf("%d",&a);
  for(int i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&b);
  for(int i=0;i<b;i++){
    scanf("%d",&B[i]);
  }
  for(int i=0;i<b;i++){
    c=binarySearch(A,B[i],a);
    if(c==1)count++;
  }
  printf("%d\n",count);
   return 0;
}
int binarySearch(int A[],int x,int g){
  int right,left,mid,key;
  left = 0;
  right = g;
  key=x;
      while(left < right){
        mid = (left + right)/2;
        if (A[mid] == key)return mid=1;
        else if( key < A[mid])right = mid;
        else left = mid + 1;
      }
    return mid=0;
}

