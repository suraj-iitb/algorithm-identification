#include <stdio.h>
#include <stdlib.h>

#define INF 200000000

typedef struct ca{
  char mark;
  int num;
} Card;

void quicksort(Card *, int, int);
int Partition(Card *, int, int);
void merge(Card *, int, int, int);
void mergesort(Card *, int, int);
int checkstable(Card *, Card *);

int n;

int main(){
        Card *A, *B;
        int i, p, r, q, left, right;

        scanf("%d", &n);
        A = malloc(sizeof(Card) * n);
		B = malloc(sizeof(Card) * n);
        for(i = 0 ; i < n ; i++){
                scanf(" %c %d", &A[i].mark, &A[i].num);
                B[i] = A[i];
        }

		p = 0;
		r = n - 1;
		quicksort(A, p, r);

		left = 0;
		right = n;
		mergesort(B, left, right);

		int stable = checkstable(A, B);
		if(stable)printf("Stable\n");
		else printf("Not stable\n");
		for(i = 0 ; i < n ; i++){
			printf("%c %d\n", A[i].mark, A[i].num);
		}

        return 0;
}

int Partition(Card *A, int p, int r){
        int x, i, j;
		Card buf;
        x = A[r].num;
        i = p - 1;
        for(j = p  ; j < r ; j++){
                if(A[j].num <= x){
                        i = i + 1;
                        buf = A[i];
                        A[i] = A[j];
                        A[j] = buf;
                }
        }
        buf = A[i + 1];
        A[i + 1] = A[r];
        A[r] = buf;
        return i + 1;
}

void quicksort(Card *A, int p, int r){
  int q;
  if(p < r){
    q = Partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

void merge(Card *B, int left, int mid, int right){
	int n1, n2, i, j, k;
	Card *L, *R;
	n1 = mid - left;
	n2 = right - mid;

	L = malloc((n1+1) * sizeof(Card));
	R = malloc((n2+1) * sizeof(Card));

	for(i = 0 ; i < n1 ; i++){
		L[i] = B[left + i];
	}
	for(i = 0 ; i < n2 ; i++){
		R[i] = B[mid + i];
	}

	L[n1].num = INF; R[n2].num = INF;

	i = 0; j = 0;
	for(k = left ; k < right ; k++){
		if(L[i].num <= R[j].num){
			B[k] = L[i];
			i++;
		}else{
			B[k] = R[j];
			j++;
		}
	}
}

void mergesort(Card *B, int left, int right){
  if(left + 1 < right){
    int mid = (left + right) / 2;
    mergesort(B, left, mid);
    mergesort(B, mid, right);
    merge(B, left, mid, right);
  }
}

int checkstable(Card *A, Card *B){
	int i;
	for(i = 0 ; i < n ; i++){
		if(A[i].mark != B[i].mark)return 0;
	}
	return 1;
}
