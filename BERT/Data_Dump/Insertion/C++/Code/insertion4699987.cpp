#include<iostream>
using namespace std;

void print(int A[], int n){
	for(int i = 0; i < n; i++){
		cout << A[i];
		if(i!=n-1) cout << " ";
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	int A[n+7];
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	print(A, n);
	for (int i = 1 ; i < n; i++){
		int key = A[i];
	    /* insert A[i] into the sorted sequence A[0,...,j-1] */
	    int j = i - 1;
	    while (j >= 0 && A[j] > key){
	    	A[j+1] = A[j];
	        j--;
		}  
	    A[j+1] = key;
	    print(A, n);
	}    
}
    

