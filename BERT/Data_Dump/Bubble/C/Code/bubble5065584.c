#include<stdio.h>

int main()
{
  int n;
  int a[100];
  int i,j,flag,temp,k=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  flag=1;
  while(flag==1){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
        temp=a[j-1];
        a[j-1]=a[j];
        a[j]=temp;
        flag=1;
        k++;
      }
    }
  }
  for(j=0;j<n;j++){
    printf("%d",a[j]);
    if(j<n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",k);

  return 0;
}



