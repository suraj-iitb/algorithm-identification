#include <iostream>
using namespace std;
int N;
int A[110];

void show(){
	for(int i=1;i<=N;i++){
		if(i!=N) cout << A[i]  << " ";
		else cout << A[i] << endl;
	}
}
int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	for(int i=1;i<=N;i++){
		int v = A[i];
		int j = i-1;
		while(j>=0 && A[j]>v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		show();
	}
}
