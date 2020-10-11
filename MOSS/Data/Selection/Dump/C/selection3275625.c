#include <stdio.h>

int main()
{
  int n,i,j,num[100],minj,tmp,cnt=0;
  scanf("%d",&n);
  for(i=0;i<=n-1;i++){
    scanf("%d",&num[i]);
  }
  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(num[j]<num[minj]){
	minj=j;
      }
    }
    if(num[i]>num[minj]){
      tmp=num[i];
      num[i]=num[minj];
      num[minj]=tmp;
      cnt++;
    }
  }
  for(i=0;i<=n-1;i++){
    if(i==0) printf("%d",num[i]);
    else printf(" %d",num[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

