#include <stdio.h>
int main()
{
  int n,a[100],i,key,j,k;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  for(i=0; i<n; i++){
    key = a[i];
    j = i-1;

    while(j>=0 && a[j]>key){
      a[j+1]=a[j];
      j--;
    }
    a[j+1] = key;

    for(k=0; k<n; k++){
      if(k==0) printf("%d",a[k]);
      else printf(" %d",a[k]);
    }
      printf("\n");
  }
  return 0;
}

