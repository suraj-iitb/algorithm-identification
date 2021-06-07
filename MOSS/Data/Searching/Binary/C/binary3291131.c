#include<stdio.h>
#define N 1000000
#define TRUE 1
#define FALSE 0

int a[N],n,key;

int search(){
  int left=0,right=n,mid;
  
  while(left<right){
    mid=(left+right)/2;
    if(a[mid]==key) return TRUE;
    if(a[mid]>key) right=mid;
    else left=mid+1;
  }
  return FALSE;
}

int main(){
  int q,i,sum=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(search()==TRUE) sum++;
  }

  printf("%d\n",sum);

  return 0;
}

