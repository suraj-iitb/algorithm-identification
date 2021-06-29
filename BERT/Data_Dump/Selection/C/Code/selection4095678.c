#include<stdio.h>

int main(){
  int i,j,minj,n,a[100],temp,cnt=0;

  scanf("%d",&n);

  for(i=0;i<=n-1;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[minj])minj=j;
    }

    temp=a[i];
    a[i]=a[minj];
    a[minj]=temp;
    if(i!=minj)cnt++;
  }

  for(i=0;i<=n-1;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }

  printf("\n%d\n",cnt);

  return 0;
}
