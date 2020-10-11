#include <stdio.h>
int n,i,j,flag=1,a[100],b,c=0;
int main () {

  scanf("%d",&n);
  for (i=0;i<n;i++)
     scanf("%d",&a[i]);

     
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1])
      {
        b=a[j];
        a[j]=a[j-1];
        a[j-1]=b;
	flag=1;
	c++;
      }
    }
  }
 
  for (i=0;i<n;i++){
     printf("%d",a[i]);
     if (i<n-1)
       printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}

