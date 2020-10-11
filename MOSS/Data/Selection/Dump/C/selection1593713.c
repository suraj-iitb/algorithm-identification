#include <stdio.h>
int main()
{
  int n,i,j,min,tmp,count=0;
  int buf[101];
  scanf("%d",&n);
  for(i=0;i<n;i++){
	  scanf("%d",&buf[i]);
  }
  for(i=0;i<n;i++){
	  min=i;
	  for(j=i;j<n;j++){
		  if(buf[j] < buf[min]){
			  min=j;
		  }
	  }
	  if(i!=min){
		  tmp=buf[i];	
		  buf[i]=buf[min];
		  buf[min]=tmp;
		  count++;
	  }
  }
  for(i=0;i<n;i++){
	  printf("%d",buf[i]);
	  if(i==n-1) printf("\n");
	  else printf(" ");
  }  
  printf("%d\n",count);
  return 0;
}
