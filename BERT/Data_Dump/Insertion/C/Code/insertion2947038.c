#include <stdio.h>

int main(){
  int i;
  int length;
  int c;
  scanf("%d",&length);

  int A[length];
  for(i = 0 ; i < length ; i++){
    scanf("%d" , &A[i]);
  }

  for(c = 0 ; c < length ; c++){
    printf("%d",A[c]);
     if(length - 1 != c)printf(" ");
  }
  printf("\n");



  /*insertion sort start*/
  int v;
  int j;
  for(i = 1 ; i < length ; i++){
    int v = A[i];
    int j = i - 1;
    while (j >= 0){
      if(A[j] < v)break;
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for(c = 0 ; c < length ; c++){
      printf("%d",A[c]);
       if(length - 1 != c)printf(" ");
    }
    printf("\n");
  }



  return 0;
}

