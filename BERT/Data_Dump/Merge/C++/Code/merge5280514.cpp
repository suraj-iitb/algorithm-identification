#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <cstring>
#include <vector>

using namespace std;

#define debug 0
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define INF 1000000100

typedef long long int ll;

ll cnt;

//left-mid, mid-rightの配列をマージしてAに並べる?
void merge(int* A, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int* L = (int*)calloc(n1+1, sizeof(int));
	int* R = (int*)calloc(n2+1, sizeof(int));
	rep(i,n1) L[i] = A[left + i];
	rep(i,n2) R[i] = A[mid + i];
	L[n1] = INF; R[n2] = INF;
	int i = 0, j = 0; //iはLの、jはRのイテレータ
	for(int k = left; k < right; k++){
		if(L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
		cnt++;
	}
}

void mergeSort(int* A, int left, int right){
	if(left + 1 < right){
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(){
	int n; cin >> n;
	int* s = (int*)calloc(n+1, sizeof(int));
	rep(i,n) cin >> s[i];
	cnt = 0;
	mergeSort(s, 0, n);
	rep(i, n){
//		cout << s[i] << " \n"[i == n-1];
		printf("%d%c", s[i], " \n"[i == n-1]);
	}
//	cout << cnt << endl;
	printf("%lld\n", cnt);
	
	return 0;
}


