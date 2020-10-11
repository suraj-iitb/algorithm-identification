#include <stdio.h>

main()
{
  int n[100],N,i,j,l=0,s=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&n[i]);
  }

  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--)
      {
	if(n[j]<n[j-1]){
	  s++;
	  l=n[j];
	  n[j]=n[j-1];
	  n[j-1]=l;
	  }
      }
  }
	for(i=0;i<N-1;i++){
	  printf("%d ",n[i]);
	}
	printf("%d\n",n[i]);
	printf("%d\n",s);

	return 0;
}
