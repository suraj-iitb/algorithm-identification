#include<stdio.h>
int input(int*[]);
int isMatch(int*[], int*[], int, int);

main(){
  int n, q;
  int *S[10000], *T[500];

  n = input(S);
  q = input(T);
 
  printf("%d\n", isMatch(S, T, n, q));
  return 0;
}

int input(int* array[]){
  int i, e;
  scanf("%d", &e);
  for(i = 0; i < e; i++){
    scanf("%d", &array[i]);
  } 
  return e;
}

int isMatch(int* S[], int* T[], int n, int q){
  int i, j, count = 0;
  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(T[i] == S[j]){
	count++;
	break;
      }
    }
  }

  return count;
}
