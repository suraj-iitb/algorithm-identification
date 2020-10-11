#include <stdio.h>

int main(){
  int n,i,j,aaa[100],t,min=1000,count=0,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&aaa[i]);
  }

  for(i=0;i<n;i++){
    for(j=i;j<n;j++){
      if(aaa[j]<min){
	min=aaa[j];
	k=j;
      }
    }
    if(k!=i){
      t=aaa[k];
      aaa[k]=aaa[i];
      aaa[i]=t;
      count++;
    }
    min=1000;
  }

  for(i=0;i<n-1;i++){
    printf("%d ",aaa[i]);
  }
  printf("%d\n",aaa[n-1]);
  printf("%d\n",count);

  return 0;
}

