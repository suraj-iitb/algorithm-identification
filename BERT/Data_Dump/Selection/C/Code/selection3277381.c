#include<stdio.h>

int main(){
  int i,j,minj,n,w,c=0;
  int a[100];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    minj=i;
    
    for(j=i;j<n;j++){

      if(a[j]<a[minj]) minj=j;
      
    }
    
    if(a[i]!=a[minj]){
      w=a[i];
      a[i]=a[minj];
      a[minj]=w;
      c++;
    }
    
  }
  
  for(i=0;i<n;i++){
    
    printf("%d",a[i]);
    
    if(i!=n-1) printf(" ");
  }
  
  printf("\n%d\n",c);
  
  return 0;
}

