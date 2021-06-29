#include <stdio.h>
main()
{
  int i,n[100],N,mini,j,s=0,l=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&n[i]);
  }
  
  for(i=0;i<N;i++){
    mini = i;
    for(j=i;j<N;j++){
      if(n[j]<n[mini]) mini=j;
    }

    l=n[i];
    n[i]=n[mini];
    n[mini]=l;
    if(i!=mini)s++;

  }
  for(i=0;i<N-1;i++){
    printf("%d ",n[i]);
  }
  printf("%d\n",n[i]);
  printf("%d\n",s);
  return 0;
  
}
