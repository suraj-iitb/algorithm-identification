#include<stdio.h>
#define N 1000000
int binarySearch(int key,int [1000000]);
int n;
int s[N],t[N];
int main(){
  int q,i,x;
  int num=0;
  scanf("%d", &n);
  for(i = 0; i <n; i++){
    scanf("%d" , &s[i]);
  }
 scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d" , &t[i]);
  }

  for(i = 0; i < q; i++){
    
    x = binarySearch(t[i],s);
  
    if(x != -1) num++;
  }
  printf("%d\n", num);
  return 0;
}

int binarySearch(int key, int A[n]){
  int left=0;
  int right = n;
  int mid;
  while(left < right){
    mid = (left + right) / 2;
    if(A[mid] == key)return mid;
    else if(key < A[mid])right = mid;
    else left = mid + 1;
  }
  return -1;
}
    
