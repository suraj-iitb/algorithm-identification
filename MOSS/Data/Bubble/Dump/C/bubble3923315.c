#include<stdio.h>

int main(void){
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i = 0; i<n; i++){
    scanf("%d", &a[i]);
  }

  int flag = 1;
  int count = 0;
  int temp;
  int i =0;
  while(flag==1){
    flag=0;
    for(int j=n-1; j>=i+1; j--){
      if(a[j]<a[j-1]){
        temp=a[j];
        a[j]=a[j-1];
        a[j-1]=temp;
        flag=1;
        count++;
      }
    }
    i++;
  }
  for(int j=0; j<n-1; j++){
    printf("%d ",a[j]);
  }
  printf("%d\n", a[n-1]);
  printf("%d\n",count);

  return 0;
}

