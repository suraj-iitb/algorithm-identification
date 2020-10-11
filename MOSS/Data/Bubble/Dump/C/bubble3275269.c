#include <stdio.h>

int main()
{
  int n,i,j,num[100],tmp,cnt=0;
  int flag=1;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  while(flag){
    flag=0;
  for(j=n-1;j>=1;j--)
    {
      if(num[j]<num[j-1])
	{
	  tmp=num[j];
	  num[j]=num[j-1];
	  num[j-1]=tmp;
	  cnt++;
	  flag=1;
	}
    }
  }
  for(i=0;i<n;i++){
    if(i==0) printf("%d",num[i]);
    else printf(" %d",num[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
 

  return 0;
}

