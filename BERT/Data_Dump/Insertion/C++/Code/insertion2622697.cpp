#include <iostream>
#include <vector>
using namespace std;
int main(void){
	int a,n,key,j;
	cin >> n;
	vector<int> A;
	for(int i=0;i<n;i++){
		cin >> a;
		A.push_back(a);
	}
	for(int j=0;j<n-1;j++){
			cout << A[j] << " ";
	}
	cout << A[n-1] << endl;
	for(int i=1;i<n;i++){
		key = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > key){ 
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
		for(int j=0;j<n-1;j++){
			cout << A[j] << " ";
		}
		cout << A[n-1] << endl;
	}
	
	
}
