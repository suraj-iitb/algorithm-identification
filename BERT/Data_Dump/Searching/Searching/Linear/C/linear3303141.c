#include<stdio.h>

int main(){
  int i,j,k,t,q;
  int n,cnt;
  int A_size[10000];

  cnt = 0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",A_size+i);
  
   scanf("%d",&q);
   for(j=0;j < q;j++){
    scanf("%d",&t);
    for(k=0;k < n;k++)
      if(A_size[k] == t){
	cnt++;
	break;
      }
   }
  
    printf("%d\n",cnt);
    return 0;

}

