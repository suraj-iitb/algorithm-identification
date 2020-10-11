#include<stdio.h>

int main(){
  int v,i,j,k,n,a[100];

  scanf("%d",&n);

  for(i=0;i<=n-1;i++){
    scanf("%d",&a[i]);
  }

  for(k=0;k<=n-1;k++){
    printf("%d",a[k]);
    if(k!=n-1)printf(" ");
  }
  
  printf("\n");
  
  for(i=1;i<=n-1;i++){

    v=a[i];
    j=i-1;
    
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    
    a[j+1]=v;

    for(k=0;k<=n-1;k++){
      printf("%d",a[k]);
      if(k!=n-1)printf(" ");
    }

    printf("\n");
    
  }
return 0;
}
