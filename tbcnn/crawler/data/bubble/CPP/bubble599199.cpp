#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int a[100], count = 0;
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++){
		for(int j = N - 1; j > i; j--){
			if(a[j-1] > a[j]){
				int z = a[j-1]; a[j-1] = a[j]; a[j] = z;
				count++;
			}
		}
	}
	for(int i= 0; i < N - 1; i++)
		cout << a[i] <<" ";
	cout << a[N - 1] << endl;
	cout << count << endl;
}
