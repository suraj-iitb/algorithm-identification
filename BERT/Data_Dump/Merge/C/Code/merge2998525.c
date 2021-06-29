#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int L[N],R[N],cnt=0;
void merge(int[],int,int,int);
void mergeSort(int[],int,int);



int main(void)
{
	int A[N],i,n;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

		mergeSort(A,0,n);
	
	for(i = 0; i < n;i++){
		printf("%d",A[i]);
		if(i!=n-1){
			printf(" ");
		}
	}


	printf("\n%d\n",cnt);
	return 0;
}

/*
	マージソート (昇順)
*/
void mergeSort(int A[], int left,int right)
{
    int mid;
	if(left+1 < right){
        mid = (left + right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }

}


/*
	マージ
*/
void merge(int A[N], int left, int mid, int right)
{
	int n1,n2,i,j,k;
    n1 = mid -left;
    n2 = right - mid;
	/* 前半の要素を作業用配列へ */
	for( i = 0; i < n1; ++i){
		L[i] = A[left + i];
	}

	/* 後半の要素を逆順に作業用配列へ */
	for( i = 0; i < n2 ; ++i){
		R[i] = A[mid + i];
	}

    L[n1] = 1e9+1;
    R[n2] = 1e9+1;

	/* 作業用配列の両端から取り出した要素をマージ */
	i = 0;
	j = 0;
	for( k = left; k < right ; ++k) {
				cnt++;
		/* 昇順にソートするので、小さい方の要素を結果の配列へ移す。 */
		if( L[i] <= R[j] ){ /* == の場合は先頭を優先すると安定なソートになる */
			A[k] = L[i];
			++i;
		}
		else{
			A[k] = R[j];
			++j;
		}
	}
}


