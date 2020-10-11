#include <stdio.h>

void BubbleSort(int a[],int n){
  int i,j,temp,cnt=0;

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j-1]>a[j]){
        temp=a[j];
        a[j]=a[j-1];
        a[j-1]=temp;
        cnt++;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

}

int main(void){
  int n,a[100],i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  BubbleSort(a,n);

  return 0;
}
