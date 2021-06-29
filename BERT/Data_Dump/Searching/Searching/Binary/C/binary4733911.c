#include<stdio.h>

int binarySearch(int *A,int key);

int cnt;
int n,q;

int main(){
  int s[100000],t[50000];
  int i,j;
  //in
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&s[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&t[i]);

  //roop
  for(j=0;j<q;j++){
    if(binarySearch(s,t[j])!=0)cnt++;
  }
  //out
  printf("%d\n",cnt);
  return 0;
}
//func
int binarySearch(int *A,int key){
  int left,right,mid;
  int hit;
  
  left = 0;
  right = n;
  while (left < right){
    hit=0;
    mid = (left + right)/2;
    if (key == A[mid]){
      hit=1;
      return 1;
    }
    if (key > A[mid])
      left = mid + 1;
    else if (key < A[mid])
      right = mid;
  }
  return 0;
}


