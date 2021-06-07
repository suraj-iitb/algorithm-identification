#include <stdio.h>

int Comp(int *, int *, int, int);

int main(){
  int snm, tnm, i;
  int S[10000], T[500];

  scanf("%d", &snm);
  for(i=0; i<snm; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &tnm);
  for(i=0; i<tnm; i++){
    scanf("%d", &T[i]);
  }

  printf("%d\n", Comp(S, T, snm, tnm));

  return 0;
}

int Comp(int *S, int *T, int snm, int tnm){
  int i, j, nm=0;
  
  for(i=0; i<tnm; i++){
    for(j=0; j<snm; j++){
      if(T[i] == S[j]){
	nm++;
	break;
      }
    }
  }

  return nm;
}
