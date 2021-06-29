#include<stdio.h>
main()
{
  int i,j,v,n,a[1000];
  scanf("%d",&n);
  for(i=0; i<n; i++){
  scanf("%d",&a[i]);
  }
  for(i=0; i<=n-1; i++){
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }
    for(j=0; j<n; j++){
    printf("%d",a[j]);
    if(a[j+1] == '\0')printf("\n");
    else printf(" ");
    }
  }
  return 0;
}
