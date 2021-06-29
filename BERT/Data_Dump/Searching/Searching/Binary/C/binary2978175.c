#include <stdio.h>

#define MAX 100000

int binarySearch(int*,int,int);

int main(){

  int n,s[MAX],q,t[MAX],i,j,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);

  for(i=0;i<q;i++){

    if(binarySearch(&s[0],n,t[i])==1) count++;

  }

  printf("%d\n",count);

  return 0;


}

int binarySearch(int A[], int n, int key){

  int left,right,mid;

  left=0;
  right=n;

  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key) return 1;
    else if(key<A[mid]) right=mid;
    else left=mid+1;
  }

  return 0;

}
