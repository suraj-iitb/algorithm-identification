#include <stdio.h>
#include <math.h>

int main()
{
  int i,n,j;

  int flag=1 , cnt=0;

  int temp;

  int minj;

  scanf("%d",&n);

  int a[n];
  
  for(i=0;i<n;i++){

    scanf("%d",&a[i]);
    
  }

  for(i=0;i<n-1;i++){

    minj=i;

    for(j=i;j<n;j++){
      
      if(a[j]<a[minj]){
	minj=j;
      }

    }

    temp=a[i];
    a[i]=a[minj];
    a[minj]=temp;

    if(i!=minj){
    cnt++;
    }

  }


  for(i=0;i<n;i++){

    if(i>0){
      printf(" ");
    }
    printf("%d",a[i]);

  }
  
  printf("\n%d\n",cnt);

  return 0;
}

