#include <stdio.h>
int main()
{
  int i,n,j; 
  int flag,temp;
  int cnt=0;

  scanf("%d",&n);

  int a[n];  

  for(i=0;i<n;i++){

    scanf("%d",&a[i]);
    
  }

  flag=1;
  i=0;

  while(flag==1){

    flag=0;

    for(j=n-1;j>=i+1;j--){

      if(a[j]<a[j-1]){

	temp=a[j-1];
	a[j-1]=a[j];
	a[j]=temp;

	flag=1;

	cnt++;

      }

    }

    i++;

  }

  for(i=0;i<n-1;i++){

    printf("%d ",a[i]);

  }

  printf("%d",a[i]);

  printf("\n%d", cnt);
  printf("\n");

  return 0;
}

