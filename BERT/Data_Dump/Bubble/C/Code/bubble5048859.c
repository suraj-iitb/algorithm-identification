#include <stdio.h>

int main(){
  int i,j,n,cnt=0,flag;
  int a[100],tmp;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  i=0;
  flag=1;
  while(flag==1){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	flag=1;
	cnt++;
      }
    }
    i++;
  }

  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}
	
      
    
  

  

