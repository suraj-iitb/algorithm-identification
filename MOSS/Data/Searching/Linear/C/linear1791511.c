#include <stdio.h>
int main(){
  int i,j=0,c=0,n1,n2,retu1[10000],retu2[500];
  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&retu1[i]);
  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&retu2[i]);
  }
  for(i=0;i<n2;i++){
    j=0;
    while(j<n1){
      if(retu1[j]==retu2[i]){
	c++;
	break;
      }
      else j++;
    }
  }
  printf("%d\n",c);
  return 0;
}
