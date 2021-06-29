#include<stdio.h>
#define N 100

int main(){
  int h,i,j,v,a[N],n;
  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf(" %d",&a[i]);
    if(a[i]<0 || a[i]>1000)break;
  }

  for(i=1; i<=n-1; i++){
    for(h=0; h<n-1; h++){
      printf("%d ",a[h]);
    }
    printf("%d\n",a[h]);
    
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
  }
  for(h=0; h<n-1; h++){
      printf("%d ",a[h]);
    }
    printf("%d\n",a[h]);

  return 0;
}

