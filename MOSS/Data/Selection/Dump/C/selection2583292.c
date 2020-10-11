#include<stdio.h>

int main()
{
  int i,mini,a[100],n,temp,j,num=0;
  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    scanf("%d",&a[i]);
  }
  for (i = 0; i < n; i++) {
    mini = i;
    for (j = i; j < n; j++) {
      if(a[mini] > a[j])
        mini = j;
    }
    if(mini != i){
      num++;
      temp = a[i];
      a[i] = a[mini];
      a[mini] = temp;
    }  
   }
  for (i = 0; i < n-1; i++)
  printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",num);
  return 0;
}
    
    
