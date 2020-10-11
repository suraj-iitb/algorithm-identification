#include <stdio.h>

int main(){
  int n,count=0,aaa[100],i,j,temp;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&aaa[i]);
  }

  for(i=0;i<=n;i++){
    for(j=n-1;0<j;j--){
      if(aaa[j-1]>aaa[j]){
	temp=aaa[j];
	aaa[j]=aaa[j-1];
	aaa[j-1]=temp;
	count++;
      }
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",aaa[i]);
  }
  printf("%d\n",aaa[n-1]);
  printf("%d\n",count);

  return 0;
}

