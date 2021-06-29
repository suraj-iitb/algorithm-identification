#include<stdio.h>
#define MAX_N 100000
#define MAX_Q 50000
int binarySearch(int [],int ,int );
int main(){
  
  int n,s[MAX_N],q,t[MAX_Q],c=0;
  int i;
  
  // input 
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);

  // Search
  for(i=0;i<q;i++){
    c += binarySearch(s,t[i],n);
  }
  printf("%d\n",c);
  
  
  return 0;
}

int binarySearch(int *s,int key,int n) {
  
  int i=0,left=0,right=n,mid;
  
  while(left < right){
    mid = (left + right)/2;
    if(s[mid] == key) {
      return 1;
    } else if( key < s[mid]) {
      right = mid; 
    }else {
      left = mid + 1;
    }

  }
  return 0;
}
