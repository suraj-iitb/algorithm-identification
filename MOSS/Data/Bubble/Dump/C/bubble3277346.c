#include<stdio.h>

int main()
{
  int i,sw=0,a[100],n,j,temp,flag=1;
  //enter
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
	scanf("%d",&a[i]);
      
    }

  while(flag){
    flag=0;
      for(j=n-1;j>=1;j--)
	{
	  if(a[j-1]>a[j])
	    {
	      temp=a[j];
	      a[j]=a[j-1];
	      a[j-1]=temp;
	      flag=1;
	      sw++;
	    }
       
	}
  }
    for(i=0;i<n;i++)
    {
      if(i>0)printf(" ");
      printf("%d",a[i]);
    }
    printf("\n");
  printf("%d\n",sw);

  return 0;
}



