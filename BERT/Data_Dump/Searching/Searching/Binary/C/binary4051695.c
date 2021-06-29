#include<stdio.h>
#include<stdlib.h>

int main(){
  int arr[100000],input[50000],i,n,q,l,r,m,count=0;

  scanf("%d",&n);
  if(n>100000) exit(2);
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  scanf("%d",&q);
  if(q>50000) exit(2);
  for(i=0;i<q;i++){
    scanf("%d",&input[i]);
    l=0;
    r=n;
    while(l<r){
      m=(l+r)/2;
      if(arr[m]==input[i]){
	count++;
	  break;
      }else if(arr[m]<input[i]) l=m+1;
      else r=m;
    }
  }
  printf("%d\n",count);
  return 0;
}

