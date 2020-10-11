#include<stdio.h>

#include<stdio.h>
int main(){
  int step=0,i,j,num,tmp;
  int a[100];

  scanf("%d",&num);

  for(i=0;i<num;i++) scanf("%d",&a[i]);

  for(i=0;i<(num-1);i++){
    for(j=(num-1);j>i;j--){
      if(a[j-1] > a[j]){
        tmp = a[j-1];
        a[j-1] = a[j];
        a[j] = tmp;
        step++;
      }
    }
  }
  for(i = 0;i < num-1;i++) printf("%d ",a[i]);
  printf("%d",a[num-1]);
  printf("\n");
  printf("%d\n",step);
  return 0;
}
