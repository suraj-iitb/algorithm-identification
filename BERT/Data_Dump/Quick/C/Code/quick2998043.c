#include <stdio.h>
#define N 100000

typedef struct Card{
  char mark[2];
  int num;
  int firstorder;
}card;

int partition(card*, int, int);
void quicksort(card*, int, int);

int main(){
  card A[N];
  int i, j, num;
  int flag = 0;
  
  scanf("%d", &num);

  for(i = 0 ; i < num; i++){
    scanf("%s", A[i].mark);
    scanf("%d", &A[i].num);
    A[i].firstorder = i;
  }
  /*  
  printf("\nbefore\n");
  for(i = 0; i < num; i++){
    printf("%s %d  %d\n",A[i].mark, A[i].num, A[i].firstorder);
  }
  */
  quicksort(A, 0, num-1);

  for(i = 0; i < num-1; i++){
    for(j = i+1;j < num; j++ ){
      if(A[i].num == A[j].num){
	if(A[i].firstorder > A[j].firstorder){
	  flag = 1;
	  break;
	}
      }
      else{
	break;
      }
    }
    if(flag == 1){
      break;
    }
  }
  
  //printf("after\n");

  if(flag == 0){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  
  for(i = 0; i < num; i++){
    printf("%s %d\n",A[i].mark, A[i].num);
  }
  
  return 0;
}

int partition(card *A, int p, int r){
  
  int i, j;
  int x;
  card temp;
  
  x = A[r].num;
  i = p-1;
  
  for(j = p; j < r; j++){
    if(A[j].num <= x){
      i = i+1;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;

  return i+1;
}

void quicksort(card *A, int p, int r){
  int q;
  
  if(p < r){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
  
}

