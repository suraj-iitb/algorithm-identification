#include <stdio.h>

int bubblesort(int a[],int N){
    int i,j,s,z,flag;
    s=0;
    z=0;
    flag=1;
    for(i=0;flag;i++){
      flag=0;
      for(j=N-1;j>=i+1;j--){
        if(a[j]<a[j-1]){
          z=a[j-1];
          a[j-1]=a[j];
          a[j]=z;
          flag=1;
          s++;
        }
      }
    }
  return s;
}

int main(void)
{
  int i,j,N,s,a[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  s=bubblesort(a,N);
  for(i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",a[i]);
  }
  printf("\n");


  printf("%d\n",s);
  return 0;
}

    
