#include<iostream>
using namespace std;
int BBS(int A[10000],int N){
	int sw=0;
	bool flag=1;
	for(int i=0;flag;i++){
		flag=0;
		for(int j=N-1;j>=i+1;j--){
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				flag=1;
				sw++;

			}

			

		}

	}

	return sw;
}

int main(void){

	int N,sw;
	int A[10000];
	cin >> N;

	for(int i=0;i<N;i++)cin >> A[i];


	sw = BBS(A,N);

	for(int i=0;i<N;i++){
		if(i)cout << " ";
		cout << A[i];
	}
    cout << endl;
	cout << sw << endl;

}

