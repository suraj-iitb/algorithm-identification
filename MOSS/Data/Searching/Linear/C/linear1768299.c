#include<stdio.h>
int linearSearch();
int key,S[10000],T[500],k=0,j,i,q,n;
int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  linearSearch();
  printf("%d\n",k);
  return 0;
}

int linearSearch()
{
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i] == S[j]){k++;
      break;
      }
    }
  }

}
