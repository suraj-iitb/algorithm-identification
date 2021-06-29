#include<stdio.h>

int search(int N[],int n,int keyli){
  int i=0;
  N[n]=keyli;
  while(N[i]!=keyli)i++;
  return i !=n;

}

int main(){
  int i,n,N[10000+1],q,keyli,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&N[i]);
}

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&keyli);
    if(search(N,n,keyli))sum++;
}
  printf("%d\n",sum);

  return 0;
}

