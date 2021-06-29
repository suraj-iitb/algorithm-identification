#include <stdio.h>

void rinir(int *,int *);

int n,q,count=0;

int main(){
  int i,c;
  scanf("%d",&n);
  //printf("n:%d\n",n);
  int s[n+1];

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  //printf("q:%d\n",q);
  int t[q];

  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  rinir(s,t);
  printf("%d\n",count);

  return 0;
}
void rinir(int *a,int *b){
  int i,j=0;
  for(i=0;i<q;i++){
    a[n]=b[i];
    while(a[j]!=a[n]){
        j++;
      }
    if(j!=n)count++;
    j=0;
  }
}

