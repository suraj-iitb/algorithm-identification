#include <iostream>
using namespace std;

int main(){
	int N;
	int A[100];
	int count = 0;

	cin>>N;

	for(int i=0; i<N; i++)
		cin>>A[i];

	for(int i=0; i<N-1; i++){
		for(int j=0; j<N-i-1; j++){
			if(A[j]>A[j + 1]){
				swap(A[j], A[j + 1]);
				count++;
			}
		}
	}

	for(int i=0; i<N-1; i++){
		cout << A[i] <<" ";
	}
    cout<< A[N-1]<<endl;
	cout<<count<<endl;

	return 0;
}

