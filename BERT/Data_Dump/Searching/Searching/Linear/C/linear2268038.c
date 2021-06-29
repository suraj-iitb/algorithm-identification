#include <stdio.h>


#define N 10000
#define Q 500

int main(){

  int n,q,i,j,c=0,temp=N;
  int S[N],T[Q];

  scanf("%d", &n);

  for(i=0 ; i<n ; i++){
    scanf("%d", &S[i]);
  }

   scanf("%d", &q);

  for(i=0 ; i<q ; i++){
    scanf("%d", &T[i]);
  }

  for(i=0 ; i<q ; i++){
    for(j=0 ; j<n ; j++){
      if(T[i]==S[j]) {
	if(temp!=T[i]){
	c++;
	temp=T[i];
	}
      }
    }
  }

  printf("%d\n",c);

  return 0;
}
