#include <iostream>

using namespace std;

int main(){
	int A[100],N,i,v,j,k;

	cin >> N;
	
	for(i=0;i<N;i++){
		cin >> A[i];
	}

	for(k=0;k<N-1;k++){
			cout << A[k] << " " ;
		}
			cout << A[N-1] <<endl;
	
	for(i=1;i<N;i++){
		v = A[i];
		j = i-1;

		while(j >= 0 && A[j]>v){
			A[j+1]=A[j];
			j--;
			A[j+1] =v;
		}

		for(k=0;k<N-1;k++){
			cout << A[k] << " " ;
		}
			cout << A[N-1] <<endl;
	}

	return 0;
}
