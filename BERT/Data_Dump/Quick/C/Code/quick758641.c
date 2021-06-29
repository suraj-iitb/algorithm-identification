#include<stdio.h>

#include<stdio.h>
 
struct Card{
  char suit[2];
  int value;
  int index;
};
struct Card A[100000];

void IsStable(struct Card C[], int lenght)
{
  int stable = 0;
  int i;
  for(i = 1; i < lenght; i++){
    if((C[i].value == C[i+1].value) && (C[i].index > C[i+1].index)){
      stable = 1;
      break;
    }
  }
  if(stable == 0){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  return;
}

int Partition(struct Card A[], int p, int r)
{
  struct Card w;
  int x = A[r].value;
  int i = p-1, j, k;
  for(j = p; j < r; j++){
	  if(A[j].value <= x){
		i = i+1;
		w = A[i];
		A[i] = A[j];
		A[j] = w;
	}
  }
  w = A[i+1];
  A[i+1] = A[r];
  A[r] = w;
  return(i+1);
}

void Quicksort(struct Card A[], int p, int r)
{
  int q;
  if(p < r){
    q = Partition(A, p, r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
}

int main()
{
	int n, i;

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%1s %d", A[i].suit, &(A[i].value));
		A[i].index = i;
	}

	Quicksort(A, 0, n-1);
	IsStable(A, n);
	for(i = 0; i < n; i++){
		printf("%s %d\n", A[i].suit, A[i].value);
	}

	return(0);
}
