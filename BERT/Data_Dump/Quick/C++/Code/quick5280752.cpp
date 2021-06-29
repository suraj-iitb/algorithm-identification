#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <cstring>
#include <vector>

using namespace std;

#define debug 0
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define INF 1000000010

typedef pair<char, int> P;

typedef long long int ll;

void merge(P* arr, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	P* L = (P*)calloc(n1+1, sizeof(P));
	P* R = (P*)calloc(n2+1, sizeof(P));
	rep(i, n1) L[i] = arr[left + i];
	rep(i, n2) R[i] = arr[mid + i];
	L[n1].second = R[n2].second = INF;
	int l = 0, r = 0;
	for(int i = left; i < right; i++){
		if(L[l].second <= R[r].second){
			arr[i] = L[l++];
		}
		else arr[i] = R[r++];
	}
}

void mergesort(P* arr, int left, int right){
	if(left + 1 < right){
		int mid = (left+right) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid, right);
		merge(arr, left, mid, right);
	}
}

int partition(P* arr, int p, int r){
	int x = arr[r].second;
	int i = p - 1;
	for(int j = p; j < r; j++){
		if(arr[j].second <= x){
			++i;
			P tmp = make_pair(arr[j].first, arr[j].second);
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	++i;
	P tmp = make_pair(arr[i].first, arr[i].second);
	arr[i] = arr[r];
	arr[r] = tmp;
	return i;
}

void quicksort(P* arr, int p, int r){
	if(p < r){
		int q = partition(arr, p, r);
		quicksort(arr, p, q-1);
		quicksort(arr, q+1, r);
	}
}

int main(){
	int n; cin >> n;
	P* A = (P*)calloc(n, sizeof(P));
	P* B = (P*)calloc(n, sizeof(P));
	rep(i, n) {
		cin >> A[i].first >> A[i].second;
		B[i] = make_pair(A[i].first, A[i].second);
	}
	
	quicksort(A, 0, n-1);
	mergesort(B, 0, n);

#if debug
	printf("merge\n");
	rep(i, n){
		printf("%c %d\n", B[i].first, B[i].second);
	}
#endif
	
	bool ans2 = true;
	for(int i = 0; i < n; i++){
		if(A[i].first != B[i].first) ans2 = false;
	}
	if(ans2) cout << "Stable";
	else cout << "Not stable";
	cout << endl;
	
	rep(i, n){
		printf("%c %d\n", A[i].first, A[i].second);
	}
	
	return 0;
}


