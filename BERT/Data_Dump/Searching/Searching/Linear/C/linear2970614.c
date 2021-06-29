#include<stdio.h>
int main(){
  int i,j,n,q,S[10000],T[1000],a,b,c,d,count=0,count2=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  for(a=0;a<q;a++){
    for(b=0;b<n;b++){
      if(T[a]==S[b]) {
        count++;
        count2++;
        if(count2>=2){
          count--;
        }
      }
    }
    count2=0;
  }
  printf("%d\n",count);
  return 0;
}

