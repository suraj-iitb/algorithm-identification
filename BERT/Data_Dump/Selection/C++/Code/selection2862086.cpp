#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
		int N;
		int mini;
		int count = 0;
		cin >> N;
		int A[N];
		for(int i = 0; i < N; i++){
			cin >> A[i];
		}
		for(int i = 0; i < N; i++){
			mini = i;
			for(int j = i; j < N; j++){
				if(A[j] < A[mini]){
					mini = j;
				}
			}
			if(A[mini] != A[i]){
				int temp = A[mini];
				A[mini] = A[i];
				A[i] = temp;
				count++;
			}
		}
		for(int i = 0; i < N-1; i++){
			cout << A[i] << " ";
		}
		cout << A[N-1] << endl;
		cout << count << endl;
		return 0;
}
