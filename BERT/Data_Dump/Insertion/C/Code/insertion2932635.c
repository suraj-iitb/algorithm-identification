#include<stdio.h>

int main(){
  int n,a[1000];
  int i,j,k;
  int v;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(i=1;i<n;i++){
    v=a[i];
    j=i-1;

     for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k!=n-1)
	printf(" ");
    }
    printf("\n");
    
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
  }
   for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k!=n-1)
	printf(" ");
    }
    printf("\n");
    
  return 0;
}

