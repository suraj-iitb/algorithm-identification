#include<stdio.h>

int main()
{
  int i,n,num=0,a[100],temp,flag;
  scanf("%d",&n);
  for (i = 0; i < n; i++) 
    scanf("%d",&a[i]);
  flag = 1;
  while(flag == 1) {
  flag=0;
  for (i =n-2; i >=0;i--) {
    if(a[i]>a[i+1]){
      temp = a[i+1];
      a[i+1] = a[i];
      a[i] = temp;
      num++;
      flag = 1;
    }
  }
  }
  for(i = 0; i<n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",num);
  return 0;
}
