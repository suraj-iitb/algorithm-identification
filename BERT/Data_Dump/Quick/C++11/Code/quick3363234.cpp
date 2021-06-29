#include<stdio.h>
#include<limits.h>

struct Card{
	char a;
	int x;
};

int partition(Card a[], int p, int r){
	int i = p - 1;
	int x = a[r].x;
	for (int j = p; j < r; j++){
		if (a[j].x <= x){
			i++;
			Card tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	Card tmp = a[i+1];
	a[i+1] = a[r];
	a[r] = tmp;
	return i+1;
}

void quickSort(Card a[], int p, int r){
	if (p < r){
		int q = partition(a, p, r);
		quickSort(a, p, q-1);
		quickSort(a, q+1, r);
	}
}

void Merge(Card a[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	Card* L = new Card[n1+1];
	Card* R = new Card[n2+1];
	for ( int i = 0; i < n1; i++) L[i] = a[left + i];
	L[n1].x = INT_MAX;
	for (int i = 0; i < n2; i++) R[i] = a[mid + i];
	R[n2].x = INT_MAX;
	int i = 0;
	int j = 0;
	while(i < n1 || j < n2){
		if (L[i].x <= R[j].x){
			a[left + i + j] = L[i];
			i++;
		}
		else{
			a[left + i + j] = R[j];
			j++;
		}
	}
}

void MergeSort(Card a[], int left, int right){
	if (left + 1 < right){
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid, right);
		Merge(a, left, mid, right);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	Card A[1000000];
	Card B[1000000];
	char S[10];
	int v;
	for (int i = 0; i < n; i++) {
		scanf("%s %d", S, &v);
		A[i].a = B[i].a = S[0];
		A[i].x = B[i].x = v;
	}
	quickSort(A, 0, n-1); 
	MergeSort(B, 0, n);
	for (int i = 0; i < n; i++){
		if (A[i].a != B[i].a){
			printf("Not stable\n");
			break;
		}
		if (i == n-1) printf("Stable\n");
	}
	for (int i = 0; i < n; i++) printf("%c %d\n", A[i].a, A[i].x);
}
