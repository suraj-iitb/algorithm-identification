#include<stdio.h>
int main()
{
  int data[100],a,i,j,tmp,min,c=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
      scanf("%d",&data[i]);
  }
  for(i=0;i<a-1;i++){
      min=i;
      for(j=i;j<a;j++){
        if(data[j]<data[min])
        min=j;
      }
      tmp=data[i];
      data[i]=data[min];
      data[min]=tmp;
      if(data[i]!=data[min]) c++;
    }
       
 
  for(i=0;i<a;i++){
      printf("%d",data[i]);
      if(i!=a-1) printf(" ");
    }
  printf("\n");
  printf("%d\n",c);
  return 0;
}
