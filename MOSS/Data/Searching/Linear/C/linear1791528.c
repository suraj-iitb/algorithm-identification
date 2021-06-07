
#include<stdio.h>
#define S_MAX 10000
#define T_MAX 10000

int main()
{
  int S[S_MAX], n, T[T_MAX], exi[S_MAX], q, C=0, flag=0;
  int i, j, k;

  scanf("%d", &n);
  for(i=0 ; i<n ; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i=0 ; i<q ; i++){
    scanf("%d", &T[i]);
  }

  for(i=0 ; i<n ; i++){
    for(j=0 ; j<q ; j++){
      if(T[j] == S[i]){
	flag=1;
	for(k=0 ; k<C ; k++){
	  if(exi[k] == S[i]){
	    flag=0;
	    break;
	  }
	}
      }
    }
    if(flag == 1){
      exi[C]=S[i];
      C++;
    }
    flag=0;
  }

  printf("%d\n", C);

  return 0;
}
