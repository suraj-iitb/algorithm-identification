#include <stdio.h>

void select_myself(int x[],int y);

int main()
{
  int a,i;
  int in[100];

  scanf("%d",&a);
  if(1<=a&&a<=100){
    for(i=0;i<a;i++){
      scanf("%d",&in[i]);
    }
    select_myself(in,a);
  }
  return 0;
}

void select_myself(int x[],int y){
  int i,j,small,change,keep;
  int count=0;

  for(i=0;i<y-1;i++){
    small=i;
    for(j=i+1;j<y;j++){
      if(x[small]>x[j]){
	small=j;
    }
    }
    if(small != i){
      keep=x[i];
      x[i]=x[small];
      x[small]=keep;
      count++;
    }
  }

    for(j=0;j<y;j++){
      if(j>0) printf(" ");
      printf("%d",x[j]);
    }
    printf("\n%d\n",count);
}
      

