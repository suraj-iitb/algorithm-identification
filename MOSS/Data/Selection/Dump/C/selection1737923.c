#include<stdio.h>

int main()
{

  int i,a[100],j,n,minj,sw,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%d",&a[i]);

  }


  for(i=0;i<n;i++){

    minj = i;

    for(j=i;j<n;j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }

      sw = a[i];
      a[i]= a[minj];
      a[minj] = sw;
      if(i != minj) count++;
    }

  for(i=0;i<n-1;i++){

    printf("%d ",a[i]);

  }
  printf("%d",a[n-1]);
  printf("\n");
  printf("%d\n",count);
 
  return 0;
}
