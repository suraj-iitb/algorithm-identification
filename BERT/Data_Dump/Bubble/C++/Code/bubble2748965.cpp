#include<iostream>
#include<algorithm>

using namespace std;


int main(){
	int size, A[100], k = 0;
	
	cin >> size;
	
	for(int i=0;i<size;i++)
	cin >> A[i];

	for(int j = size-1; j > 0; j--) 
		for(int i = 0; i < j; i++)
			if(A[i] > A[i + 1]) {
				
				swap(A[i], A[i + 1]);
				k++;
				
		}
			 
	for(int i=0;i<size-1;i++)
	cout << A[i] << " ";
	
	cout << A[size-1] <<"\n";
	cout << k << "\n";
	
	return 0;
	
}

