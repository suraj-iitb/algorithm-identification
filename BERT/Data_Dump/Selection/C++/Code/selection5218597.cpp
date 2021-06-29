#include <iostream>
using namespace std;

int cnt = 0;

void selectionSort(int* A, int N){
	int i, j, min;
	for(i=0;i<N;i++){
		min=i;
		for(j=i;j<N;j++){
			if(A[j]<A[min]){
				min=j;
			}
			
		}
		swap(A[i], A[min]);
		if(i!=min) cnt++;
	}
}

int main(){
	int n, A[10000];
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	
	selectionSort(A, n);
	int k =0;
	for(int i=0;i<n;i++){
		if(k++) cout << " ";
		cout << A[i];
	}
	cout << endl << cnt << endl;;
}

