#include <stdio.h>
int main()
{
  int n,i,flag,tmp,count=0;
  int buf[101];
  scanf("%d",&n);
  for(i=0;i<n;i++){
	  scanf("%d",&buf[i]);
  }
  flag=1;
  while(flag){
	  flag=0;
	  for(i=n-1;i>0;i--){
		  if(buf[i]<buf[i-1]){
			  tmp=buf[i];
			  buf[i]=buf[i-1];
			  buf[i-1]=tmp;
			  flag=1;
			  count++;
		  }
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
