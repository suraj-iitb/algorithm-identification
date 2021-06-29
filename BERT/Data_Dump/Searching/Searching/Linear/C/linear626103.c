#include <stdio.h>
#define N 10000
#define Q 500

int search(int [],int [],int,int);

int main(void){

  int n,q;
  int S[N];
  int T[Q];
  int i;
  int count;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  count = search(S,T,n,q);

  printf("%d\n",count);

  return 0;
}

int search(int S[],int T[],int n,int q){

  int i,j;
  int count=0;

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i] == S[j]){
	count++;
	break;
      }
    }
  }

  return count;
}
