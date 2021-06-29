#include <stdio.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int S[500000], L[250001], R[250001];
int cnt=0;

int main(){
	int n, i;

	scanf("%d", &n);
	for(i=0; i<n; i++)
    	scanf("%d", &S[i]);

	mergeSort(S, 0, n);

	for(i=0; i<n-1; i++)
		printf("%d ",S[i]);
	printf("%d\n%d\n", S[n-1], cnt);

	return 0;
}

void merge(int S[], int left, int mid, int right)
{ 
  int n1 = mid - left; 
  int n2 = right - mid;
  int i, j, k;
	
	for(i=0; i<n1; i++) 
    	L[i] = S[left + i];
	
	for(i=0; i<n2; i++) 
    	R[i] = S[mid + i];

	L[n1] = R[n2] = 1000000001;

	i = j = 0;
	k = left;
	while(k < right){
    	cnt++;
		if (L[i] <= R[j]) S[k++] = L[i++];
		else S[k++] = R[j++];
	}
}

void mergeSort(int S[], int left, int right)
{
	int mid;
	if(left+1 < right){
	  mid = (left + right) / 2;
	  mergeSort(S, left, mid);
	  mergeSort(S, mid, right);
	  merge(S, left, mid, right);
  }
}
