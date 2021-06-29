#include<iostream>
using namespace std;

const int maxn = 100001;
const int INFTY =1e9+1;
int n;

struct Card
{
	char suit;
	int value;
};

Card L[maxn / 2 + 1], R[maxn / 2 + 1];

void merge(struct Card a[], int n, int l, int mid, int r) {
	int n1 = mid - l;
	int n2 = r - mid;
	for (int i = 0; i < n1; i++) L[i] = a[l + i];
	for (int i = 0; i < n2; i++)  R[i] = a[mid + i];
	L[n1].value = R[n2].value = INFTY;
	int i =0, j = 0;
	for (int k = l; k < r; k++) {
		if (L[i].value <= R[j].value) {
			a[k] = L[i]; i++;
		}
		else {
			a[k] = R[j]; j++;
		}
	}
}

void mergeSort(struct Card a[], int n, int l, int r) {
	if (l + 1 < r) {
		int mid = (l + r) / 2;
		mergeSort(a, n, l, mid);
		mergeSort(a, n, mid, r);
		merge(a, n, l, mid, r);
	}
}

int partition(struct Card a[], int n, int p, int r) {
	
	Card x = a[r];
	int i = p - 1;
	Card t;
	for (int j = p; j < r; j++) {
		if (a[j].value <= x.value) {
			i++;
			t = a[i]; a[i] = a[j]; a[j] = t;
		}
	}
	t = a[i + 1]; a[i + 1] = a[r]; a[r] = t;
	return i + 1;
}

void quickSort(struct Card a[], int n, int p, int r) {
	int q;
	if (p < r) {
		q = partition(a, n, p, r);
		quickSort(a, n, p, q - 1);
		quickSort(a, n, q + 1, r);
	}
}
struct Card a[maxn], b[maxn];
int main() {
	cin >> n;
	char s;
	int v;
	int stable = 1;

	for (int i = 0; i < n; i++) {
		cin >> s >> v;
		a[i].suit = b[i].suit = s;
		a[i].value = b[i].value = v;
	}
	mergeSort(a, n, 0, n);
	quickSort(b, n, 0, n - 1);

	for (int i = 0; i < n; i++) {
		if (a[i].suit != b[i].suit)  stable = 0;
	}

	if (stable == 1) cout<<"Stable"<<endl;
	else cout<<"Not stable"<<endl;

	for (int i = 0; i < n; i++) {
		cout<<b[i].suit<<" "<<b[i].value<<endl;
	}

	return 0;
}
