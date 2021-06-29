#include <stdio.h>
#define N 10000

int sch(int H[],int n,int k){
  int i=0;
  H[n]=k;
  while(H[i]!=k){
    i++;
  }
    return i!=n;
  }
int main(){
  int i,H[N+1],k,n,p,s=0;
  scanf("%d",&n);
  for(i=0;i<=n-1;i++)
    scanf("%d",&H[i]);
    scanf("%d",&p);
    for(i=0;i<=p-1;i++){
      scanf("%d",&k);
      if(sch(H,n,k))
	s++;
  }
  printf("%d\n",s);
  return 0;
}

