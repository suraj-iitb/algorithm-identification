#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> A, int N){
	size_t v=0;
	size_t j=0;
	for(size_t i=1;i< N ; i++){
		v=A[i];
		j= i-1;
		for(size_t k=0; k< N;k++){
			cout<<A[k];
			if(k!=N-1){
				cout<<" ";
			}
		}
		while(j>=0 && A[j]> v ){
			A[j+1] =A[j];
			j--;
			A[j+1] = v;
		}

		cout<<endl;
	}
	for(size_t k=0; k< N;k++){
		cout<<A[k];
		if(k!=N-1){
			cout<<" ";
		}
	}
	cout<<endl;

}

	int main(){
		size_t num=0;


		cin >> num;
   vector<int> A(num);
		for(size_t i=0; i<num ; i++){
			cin >> A[i];
		}

		insertionSort(A, num);

		return 0;

	}

