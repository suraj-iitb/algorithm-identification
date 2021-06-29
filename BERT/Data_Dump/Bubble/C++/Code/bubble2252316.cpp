#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a[100];
	int N;
	int cnt=0;
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> a[i] ;
	}
	
	for(int i=0;i<N;i++){
		for(int j=N-1;j>=i+1;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				cnt++;
			}
		}
	}
	for(int i=0;i<N-1;i++){
		cout << a[i] << " " ;
	}
	cout << a[N-1];
	cout << endl << cnt << endl;
	
	return 0;
}
