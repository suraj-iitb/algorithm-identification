#include <iostream>
using namespace std;

void bubble_sort(int N, float* A){
	int nchange = 0;
	
	for(int i=0;i<N;i++){
		for(int j=N-1;j>i;j--){
			if(A[j-1] > A[j]){
				swap(A[j-1], A[j]);
				nchange++;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		if(i==N-1){
			cout << A[i] << endl;
		}else{
			cout << A[i] << " ";
		}
	}
	cout << nchange << endl;
}

int main(){
	int N;
	cin >> N;
	
	float A[N];
	for(int i=0;i<N;i++)
		cin >> A[i];

	bubble_sort(N, A);
	return 0;
}
