#include<stdio.h>
#include<stdlib.h>

int main(){
  int arr[10000],input[500],i,j,n,q,count=0;
  scanf("%d",&n);
  if(n>10000) exit(2);
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  scanf("%d",&q);
  if(q>500) exit(2);
  for(i=0;i<q;i++){
    scanf("%d",&input[i]);
    for(j=0;j<n;j++){
      if(arr[j] == input[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

