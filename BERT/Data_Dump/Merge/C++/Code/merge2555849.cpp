#define PI 3.14159265359
#define INF 2000000000
#define MAX 500000
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

int cnt = 0;
int L[MAX/2+2], R[MAX/2+2];
	
void merge(int A[],int n,int left,int mid,int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	//?????????2??????????????????????????¨??????????????§????????±??????
	for (int i = 0;i < n1;i++) L[i] = A[left + i];
	for (int i = 0;i < n2;i++)R[i] = A[mid + i];
	L[n1] = R[n2] = INF;
	int i =0, j = 0;
	for (int k = left;k < right;k++) {
		cnt++;
		if (L[i] <= R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}
}

void mergeSort(int A[],int n,int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A,n, left, mid);
		mergeSort(A,n, mid, right);
		merge(A,n, left, mid, right);
	}
}

int main() {
	int n, A[MAX + 1],i;
	cin >> n;
	for (i = 0;i < n;i++) cin >> A[i];
	
	mergeSort(A,n,0,n);

	for (i = 0;i < n;i++) {
		if (i) cout << " ";
		cout << A[i];
	}

	cout <<endl<< cnt<<endl;

    return 0;
}
