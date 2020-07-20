#include<iostream>
using namespace std;

int N;

void out(int* arr){
	for(int i=0; i<N; i++) {
		cout << arr[i];
		if(i!=N-1) cout << " ";
	}
	cout << endl;
}

int main(){
	cin >> N;
	int* A = new int[N];

	for(int i=0;i<N;i++){
		cin >> A[i];
	}

//bubble sort
	int tmp, count=0;;
	bool flag=true;

	while(flag){
		flag=false;
		for(int j=N-1;j>=1;j--){
			if(A[j]<A[j-1]){
				count++;
				tmp=A[j];
				A[j]=A[j-1];
				A[j-1]=tmp;
				flag=true;
			}
		}
	}
	out(A);
	cout << count << endl;
	return 0;
}

