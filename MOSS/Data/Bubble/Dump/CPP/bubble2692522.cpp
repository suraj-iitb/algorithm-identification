#include <iostream>
using namespace std;

int N;
int A[110];
int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	int flag = 1;
	int count = 0;
	while(flag){
		flag = 0;
		int j = N;
		while(j>=1){
			if(A[j] < A[j-1]){
				count++;
				int tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				flag = 1;
			}
			j--;
		}
	}
	for(int i=1;i<=N;i++){
		if(i!=N) cout << A[i] <<" ";
		else cout << A[i] << endl;
	}
	cout << count << endl;
}
