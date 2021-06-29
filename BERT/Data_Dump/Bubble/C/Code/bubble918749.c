#include  <stdio.h>

int main(void)
{		
  int n,i,j,temp,x[100],count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  for (i=0;i<n;i++) {
    for (j=n-1;j>=i+1;j--) {
      if (x[j-1]>x[j]){ 
	temp=x[j];      
	x[j]=x[j-1];
	x[j-1]=temp;
	count++;
      }
    }	
  }
  for(i=0;i<n;i++){
    if(i==n-1)
      printf("%d\n",x[i]);
    else
      printf("%d ",x[i]);
  }
  printf("%d\n",count);
  return 0;
}
