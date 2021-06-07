#include<stdio.h>

int S[100001],n;
int BinarySearch(int);

int main(){
  
  int q,i,count=0;
  int T[50000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);
  
  for(i=0;i<q;i++) count += BinarySearch(T[i]);
  
  printf("%d\n",count);

  return 0;

}

int BinarySearch(int key){

  int left=0,right,mid;
  right=n;
  while(left < right){
    mid=(left + right)/2;
    if(S[mid] == key) return 1;
    else if(S[mid] < key) left = mid + 1;
    else if(S[mid] > key) right = mid;
  }
  return 0;
}
