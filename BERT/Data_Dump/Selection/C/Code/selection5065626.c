#include<stdio.h>

int main()
{
  int i,j,n,temp,k=0;
  int a[100];
  int minj;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<=n-1;i++){
    minj=i;
    k++;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[minj]){
        minj=j;
      }
    }
    temp=a[minj];
    a[minj]=a[i];
    a[i]=temp;
    if(minj==i)k--;
  }

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",k);
 return 0;
}

