#include<stdio.h>
#define N 1000002
#define TRUE 1
#define FALSE 0

int search(int *a, int n, int key){
  int left=0,right=n,mid;

  while(left<right){
    mid=(left+right)/2;
    if(a[mid]==key) return TRUE;
    else if(a[mid]>key) right=mid;
    else left=mid+1;
  }
  return FALSE;
}

int main(){
  int q,i,sum=0,a[N],n,key;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(search(a,n,key)==TRUE) sum++;
  }

  printf("%d\n",sum);

  return 0;
}
