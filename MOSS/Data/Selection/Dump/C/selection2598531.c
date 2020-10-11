#include <stdio.h>

int selectsort(int a[],int N){
  int i,j,s,z,minj;
  s=0;
  z=0;
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(a[j]<a[minj]){
        minj=j;
      }
    }
    z=a[i];
    a[i]=a[minj];
    a[minj]=z;
    if(i!=minj){
      s++;
    }
  }
  return s;
}

int main(void)
{
  int i,N,s,a[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  s=selectsort(a,N);
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
