#include <iostream>
//#include <cstdio>
using namespace std;
#define SENTINEL 2000000000

struct card{char flower; int num;};

struct card A[100000], B[100000];
int  n;

void swap_test(struct card &a,struct card &b)
{
	struct card t = a; a = b; b = t; 
}

int partition(struct card A[], int p, int r)
{
	int x = A[r].num;
	int i = p - 1;
	int j;
	for(j=p; j < r; j++)
	{
		if(A[j].num <= x) swap(A[++i], A[j]);
	}
	swap(A[i+1], A[r]);
	return i+1;
}

struct card L[100000/2 + 2], R[100000/2 + 2];

void merge(struct card A[], int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i=0; i < n1; i++) L[i] = A[left + i];
	for(int i=0; i < n2; i++) R[i] = A[mid + i];	
	L[n1].num = SENTINEL;
	R[n2].num = SENTINEL;
	
	int k, i = 0, j = 0; 
	for(k = left; k < right; k++)
	{
		if(L[i].num <= R[j].num) A[k] = L[i++];
		else A[k] = R[j++]; 
	}
} 

void merge_sort(struct card A[], int left, int right)
{
	if(left + 1 < right)
	{
		int mid = (left + right)/2;
		merge_sort(A, left, mid);
		merge_sort(A, mid, right);
		merge(A, left, mid, right);
	}
}
void quick_sort(struct card A[], int p, int r)
{
	if(p < r)
	{	
		int q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A,q+1, r);	
	}

}

int main() {
	
	char S[10];
	int v;
	
	cin >> n;
	for(int i=0; i < n; i++)
	{
		cin >> S;
		cin >> v;
		A[i].flower = B[i].flower = S[0];
		A[i].num = B[i].num = v;
	}
	
	quick_sort(A, 0, n-1);
	merge_sort(B, 0, n);
	
	
	int stable = 1;
	for(int i=0; i < n; i++)
	{
		if(A[i].flower != B[i].flower)
		{
			stable=0;
			break;		
		}
	}
	
	if(stable) cout << "Stable" << endl;
	else cout << "Not stable" << endl;

	for(int i=0; i < n; i++)
	{
			cout << A[i].flower << " " << A[i].num << endl;
	}
	
//	system("pause");
	return 0;
}

