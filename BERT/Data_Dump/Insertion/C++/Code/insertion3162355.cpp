#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int N;
	cin >> N;

	vector<int> a(N);
	for(int i=0;i<N;i++) cin >> a[i];
	
	for(int i=0;i<N;i++){
		int target = a[i];
		for(int j=0; j<i; j++){
			if(target < a[j]){
				//target should be allocated to a[j]
				//previous a[j]~a[i-1] should be moved to right element
				for(int k=i-1; k>=j; k--){
					a[k+1] = a[k];
				}
				a[j] = target;
				break;
			}
		}
		
		//print intermediate sequence
		for(int n=0; n<N; n++){
			cout << a[n];
			if(n<N-1) cout << ' ';
			else cout << '\n';
		}
	}
	
	return 0;
}
