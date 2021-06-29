#include<iostream>
#include<cstdio>
using namespace std;

const int MAX = 100000;
const int maxnum = 1000000010;
struct Card {
	char suit;
	int value;
};

Card L[MAX / 2 + 2], R[MAX / 2 + 2];

// ??????????????¶
void merge(Card A[], int n,int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) {
		L[i].suit = A[left + i].suit;
		L[i].value = A[left + i].value;
	}
	for (int i = 0; i < n2; i++) {
		R[i].suit = A[mid + i].suit;
		R[i].value = A[mid + i].value;
	}

	// ???????±???¨??°?????????????????????????????§?????°
	L[n1].value = R[n2].value = maxnum;
	int i = 0, j = 0;
	// ?????¶
	for (int k = left; k < right; k++) {
		if (L[i].value <= R[j].value)
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}
// ??????
void mergeSort(Card A[], int n, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, n ,left, mid);
		mergeSort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}

// ??????
int partition(Card A[],int p, int r) {
	Card x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j].value <= x.value) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

// ????????????
void quickSort(Card A[], int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

// ?????¶?????????????¨?????????????????????????????????±????????¶?????????????????\?????????????¨???????
bool isStable(struct Card C1[], struct Card C2[], int n) {
	for (int i = 0; i < n; i++) {
		if (C1[i].suit != C2[i].suit)
			return false;
	}
	return true;
}
Card C1[MAX], C2[MAX];
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c %d", &C1[i].suit, &C1[i].value);
		getchar();
		C2[i] = C1[i];
	}
	// ??????C1??°???????????????????????????C2??°??????????????????????????¶?????????????????????????????±???
	// ???????????\???????????????????¨????
	mergeSort(C1, n, 0 ,n);
	quickSort(C2, 0, n -1);

	if (isStable(C1, C2, n))
		printf("Stable\n");
	else
		printf("Not stable\n");

	for (int i = 0; i < n; i++)
		printf("%c %d\n", C2[i].suit, C2[i].value);
	return 0;
}