
#include <stdio.h>
#include <string.h>

#define DEF_ELEM_MAX 2000001

typedef long long llong;

int A[DEF_ELEM_MAX];
int B[DEF_ELEM_MAX];
int C[DEF_ELEM_MAX];
int N;

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
void CountingSort(int *A, int *B, int k)
{
	int i;
    for ( i = 0 ; i <= k ; i++ ) {
        C[i] = 0;
    }

    // C[i] ??? i ???????????°????¨??????????
    for ( i = 0 ; i < N ; i++ ) {
        C[A[i]]++;
    }

    // C[i] ??? i ??\????????°???????????°????¨??????????
    for ( i = 1 ; i <= k ; i++ ) {
        C[i] += C[i-1];
    }

    for ( i = N-1 ; i >= 0 ; i-- ) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
	}
}

/////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	int i;
	int maxv = 0;
//
	scanf("%d", &N);
	for ( i = 0 ; i < N ; i++ ) {
		scanf("%d", &A[i] );
		if (A[i] > maxv) {
			maxv = A[i];
		}
	}

	CountingSort(A, B, maxv);

	for ( i = 0 ; i < N ; i++ ) {
		printf("%d", B[i]);
		if ( i < N-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}

	return 0;
}
