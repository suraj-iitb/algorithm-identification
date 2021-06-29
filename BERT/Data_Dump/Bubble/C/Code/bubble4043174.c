#include <stdio.h>
int main()
{
  int s;
  int a[100]={0};
  int i,j,x=0,y=0;

  
  scanf("%d",&s);
  for(i=1;i<=s;i++){
    scanf("%d",&a[i]);
  }
  

  for(i=1;i<=s-1;i++){
    for(j=1;j<=s-i;j++){
      if(a[j]>a[j+1]){
	x=a[j];
	a[j]=a[j+1];
	a[j+1]=x;
	y++;
      }
    }
  }

  
  for(i=1;i<=s;i++){
    if(i!=s)printf("%d ",a[i]);
        if(i==s)printf("%d\n",a[i]);
    }
    printf("%d\n",y);
    
      
  return 0;
}

