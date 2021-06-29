#include <stdio.h>

int main(){
  int a,ch,j,n[105],i;
  scanf("%d",&a);
  for( i=0;i<a;i++)scanf("%d",&n[i]);
  for( j=0;j<a-1;j++)printf("%d ",n[j]);
  printf("%d\n",n[a-1]);
  for(i=1;i<a;i++){
    j=i;
    while(1){

      if(j==0)break;
      if(n[j]<n[j-1]){

	ch=n[j];
	n[j]=n[j-1];
	n[j-1]=ch;
	j--;
      }else break;
    }
    for( j=0;j<a-1;j++)printf("%d ",n[j]);
    printf("%d\n",n[a-1]);

  }
  return 0;
}
