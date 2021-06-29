#include<stdio.h>
int main(){

  int flag=1;
  int n,a[100],i,j,esc,count=0;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&a[i]);

  if(n==1){
    printf("%d\n",a[0]);
    printf("0\n");
  }

  else{

    while(flag){
      flag=0;

      for(j=n-1;j>=1;j--){
	if(a[j] < a[j-1]){
	  esc=a[j-1];
	  a[j-1]=a[j];
	  a[j]=esc;
	  flag=1;
	  count++;
	}
      }
    }	
    for(i=0;i<n;i++){
      printf("%d",a[i]);
      if(i==n-1) break;
      printf(" ");
    }
    printf("\n%d\n",count);
  }
    return 0;
}
