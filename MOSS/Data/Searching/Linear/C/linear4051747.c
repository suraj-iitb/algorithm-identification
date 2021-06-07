#include<stdio.h>
#define N 10000

int main(){
  int n1,n2,i,j,c=0;
  int in[N],serch[N];

  scanf("%d",&n1);

  for(i=0;i<n1;i++){
    scanf("%d",&in[i]);
  }

  scanf("%d",&n2);
  
  for(i=0;i<n2;i++){
    scanf("%d",&serch[i]);
  }

  for(i=0;i<n2;i++){
    for(j=0;j<n1;j++){
      if( in[j]==serch[i]){
	c++;
	break;
      }
	}
  }

  printf("%d\n",c);
  return 0;
}

