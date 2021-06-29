#include <stdio.h>
int main()
{
  int i,j,s,minj,x,y=0;
  int a[100]={};


  scanf("%d",&s);
  for(i=0;i<s;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<s;i++){
    minj=i;
    for(j=i;j<s;j++){
      if(a[minj]>a[j]){
	minj=j;
      }
    }
    
    if(minj!=i){
      x=a[minj];
      a[minj]=a[i];
      a[i]=x;
      y++;
    }
  }

  for(i=0;i<s;i++){
    printf("%d",a[i]);
    if(i==s-1)puts("");
    else printf(" ");
  }
  printf("%d\n",y);
    
  return 0 ;
}

