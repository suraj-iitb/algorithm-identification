#include <stdio.h>

void bubble_myself(int x[],int y);

int main()
{
  int a,i;
  int in[100];

  scanf("%d",&a);
  if(1<=a&&a<=100){
    for(i=0;i<a;i++){
      scanf("%d",&in[i]);
    }
    bubble_myself(in,a);
  }

  return 0;
}

void bubble_myself(int x[],int y){
  int i,j,z;
  int count=0;
  
  for(i=0;i<y-1;i++){
    for(j=y-1;j>i;j--){
      if(x[j-1]>x[j]){
	z=x[j];
	x[j]=x[j-1];
	x[j-1]=z;
	count++;
      }
    }
  }
  for(j=0;j<y;j++){
    if(j>0) printf(" ");
    printf("%d",x[j]);
  }
   printf("\n%d\n",count);
}

