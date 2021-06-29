// last edited at 25.8.2015 by charis 

#include<iostream>
using namespace std;


/*
void  insertionSort(A, N){ // N??????????´??????????0-?????????????????????A
	for (int i=1; i<N; i++){
		int v=A[i];
		int j=i-1;
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1] =v; 
		for(int k=0; k<N; k++){
			if(k==N-1) cout << A[N-1] <<endl;
			else cout << A[k] << " " ;

		}
	}
}
*/

int main(){
	int N;
	cin >> N;
	
	int A[N];
	for(int k=0; k<N; k++){
		cin  >> A[k] ;
	}

	for(int k=0; k<N; k++){
		if(k==N-1)cout << A[N-1]<< endl;
		else cout << A[k] << " ";
	}	
	//insertionSort(A, N);
	for (int i=1; i<N; i++){
		int v=A[i];
		int j=i-1;
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1] =v; 
		for(int k=0; k<N; k++){
			if(k==N-1) cout << A[N-1] << endl;	
			else cout << A[k] << " " ;
		}
	}
	
	return 0;
}
