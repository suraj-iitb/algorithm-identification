#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int N;
	cin >> N;

	vector<int> a(N);
	for(int i=0;i<N;i++) cin >> a[i];
	
	// i ... number of sorted elements
	// j ... location of bubble (right end)
	
	int swapped = 0;
	for(int i=0;i<N;i++){
		for(int j=N-1; j>i; j--){
			if(a[j] < a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				swapped++;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		cout << a[i];
		if(i<N-1) cout << ' ';
		else cout << endl;
	}
	cout << swapped << endl;
	
	return 0;
}
