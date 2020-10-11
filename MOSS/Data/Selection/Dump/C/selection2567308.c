#include <stdio.h>

void SelectionSort(int a[],int n){
  int i,min,j,temp,cnt=0;

  for(i=0;i<n;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(a[j]<a[min]){
        min=j;
      }
    }
    temp=a[i];
    a[i]=a[min];
    a[min]=temp;

    if(i!=min){
      cnt++;
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

  SelectionSort(a,n);

  return 0;
}
