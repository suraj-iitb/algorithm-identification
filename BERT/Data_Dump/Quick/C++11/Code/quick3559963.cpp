//ALDS1_6_B Sort II - Quick Sort
#include <cstdio>
#include <utility>
#define MAX 100000
#define SENTINAL 2000000000
struct Card
{
	char kind;
	int number;
};
int cnt,n;
Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(Card *A, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
    }
    L[n1].number = R[n2].number = SENTINAL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        cnt++;
        if (L[i].number <= R[j].number)
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}

void mergeSort(Card *A, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(Card* A, int p, int r)
{
	Card x = A[r];
	Card temp;
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j].number <= x.number)
		{
			i++;
			std::swap(A[i],A[j]);
		}
	}
	std::swap(A[i+1],A[r]);
	return i+1;
}

void quickSort(Card* A, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main(void)
{
	int n;
	Card Q[MAX];
	Card M[MAX];
	scanf("%d\n",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%c %d\n",&Q[i].kind, &Q[i].number);
		M[i]=Q[i];
	}

	mergeSort(M,0,n);	
	quickSort(Q,0,n-1);
	bool stable = true;
	for (int i = 0; i < n; i++)
	{
		if(Q[i].kind != M[i].kind) stable = false;
	}
	stable?printf("Stable\n"):printf("Not stable\n");
	for (int i = 0; i < n; i++)
	{
		printf("%c %d\n", Q[i].kind, Q[i].number);
	}

	return 0;
}
