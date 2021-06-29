#include <stdio.h>

int main(){
  int k=0,ch,n[105],i,j,a;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&n[i]);
  }
  for(i=0;i<a-1;i++){
    for(j=1;j<a-i;j++){
      if(n[j]<n[j-1]){
	ch=n[j];
	n[j]=n[j-1];
	n[j-1]=ch;
	k++;
      }
    }
  }
  for(i=0;i<a-1;i++)printf("%d ",n[i]);
  printf("%d\n",n[a-1]);
  printf("%d\n",k);
  return 0;
}
