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
		int min_j = i;
		for(int j=i; j<N; j++){
			if(a[min_j] > a[j]) min_j = j;
		}
		if(i != min_j){
			swap(a[i],a[min_j]);
			swapped++;
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
