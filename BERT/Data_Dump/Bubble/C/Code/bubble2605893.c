#include <stdio.h>
int main()
{
  int n,i,j,flag,s,count=0;
  int x[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){

   scanf("%d",&x[i]);
  }
  flag=1;
  while(flag==1){
   flag=0;
    for(j=n-1;j>0;j--){
     if(x[j]<x[j-1]){
     s=x[j];
    x[j]=x[j-1];
    x[j-1]=s;
    flag=1;
    count++;
      }
     }
    }
   for(j=0;j<n-1;j++){
    printf("%d ",x[j]);
   }
   printf("%d\n",x[n-1]);
    printf("%d\n",count);

    return 0;
}
