#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int* A, int n){
	bool flag = true;
	int cnt = 0;
	while(flag){
		flag = false;
		for(int j=n-1; j>0; j--){
			if(A[j-1] > A[j]){
				swap(A[j-1], A[j]);
				flag = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	int A[100];
	int cnt;
	
	for(int i=0; i<n; i++) cin >> A[i];
	cnt = bubbleSort(A, n);
	
	cout << A[0];
	for(int i=1; i<n; i++) cout << " " << A[i];
	cout << "\n" << cnt << endl;
	return 0;
}
