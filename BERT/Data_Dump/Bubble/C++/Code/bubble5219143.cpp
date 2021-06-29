#include <iostream>
using namespace std;

int cnt=0;

void bubbleSort(int* A, int N){
	int flag=1;
	while(flag){
		flag=0;
		for(int j=N-1;j>0;j--){
			if(A[j]<A[j-1]){
				swap(A[j], A[j-1]);
				flag=1;
				cnt++;
			}
		}
	}
}


int main(){
	int n, i, A[999];
	
	cin >> n;
	
	for(i=0;i<n;i++){
		cin >> A[i];
	}
	
	bubbleSort(A, n);
	
	int k=0;
	for(i=0;i<n;i++){
		if(k++) cout << " ";
		cout << A[i];
	}
	cout << endl << cnt << endl;
	
	return 0;
}

