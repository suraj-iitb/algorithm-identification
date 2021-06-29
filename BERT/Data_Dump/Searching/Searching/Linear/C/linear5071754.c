#include <stdio.h>

int linearSearch(int[],int[],int,int);

int main(){
  int i,n,S[10000],T[10000],q,key,a;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  a=linearSearch(S,T,n,q);

     printf("%d\n",a);
                                                                          

  return 0;



}


int linearSearch(int S[],int T[],int n,int q){
  int i,j,cnt=0;

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j]==T[i]){
        cnt++;
        break;
      }
    }
  }
  return cnt;
}
