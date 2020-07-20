#include<iostream>
using namespace std;


int bubbleSort(int N, int A[]){
	int cnt=0;
	int flag = 1;
	while(flag){
		flag=0;
		for(int i=N-1;i>=1;i--){
			if(A[i]< A[i-1]){
				flag=1;
				int tmp=A[i];
				A[i]=A[i-1];
				A[i-1]=tmp;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	
	int N,A[100],i;
	cin >> N;
	for(i=0;i<N;i++)cin >> A[i];
	
	int c = bubbleSort(N,A);
	for(i=0;i<N;i++){
		if(i>0) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << c << endl;

	return 0;
}

