#include <stdio.h>

int main()
{
  int i,j,key,n,m;
  int l[100];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&l[i]);
  }
  for(i=0;i<n;i++){
    printf("%d",l[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");

  for(i=1;i<n;i++){
    key = l[i];
    j = i - 1;
    while(l[j]>key && j>=0){
      l[j+1] = l[j];
      j--;
    }
    l[j+1] = key;
    for(m=0;m<n;m++){
      printf("%d",l[m]);
      if(m<n-1)printf(" ");
    }
  printf("\n");
  } 
   return 0;
}
