#include<stdio.h>

int BinarySearch(int *,int);
int n,q;

int main(){
  int C[100000];
  int T[50000];
  int i,j,a,c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d ",&C[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
     
  for(j=0;j<q;j++){
    a = BinarySearch(&C[0],T[j]);
    c+=a;
  }
 
  printf("%d\n",c);

  return 0;
}
 

int BinarySearch(int * A, int key){
  int left,right,mid; 
 
  left=0;
  right=n;

  while(left<right){
    mid=(left+right)/2;
    if(key==A[mid]) return 1;
    if(key>A[mid]) left=mid+1;
    else  right=mid;
  }
  return 0;
}
  
