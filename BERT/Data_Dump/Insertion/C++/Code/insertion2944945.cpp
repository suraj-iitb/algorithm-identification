#include <iostream>

using namespace std;

int N, a[100];

void insertionSort(){
	for(int i=1; i<N; i++){
		int j=i;
		while(a[j-1] > a[j]){
			swap(a[j-1], a[j]);
			j--;
		}
		for(int i=0; i<N; i++){
			if(i != N-1) cout << a[i] << ' ';
			else cout << a[i] << endl;
		}
	}
}

int main()
{
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> a[i];

	for(int i=0; i<N; i++){
		if(i != N-1) cout << a[i] << ' ';
		else cout << a[i] << endl;
	}

	insertionSort();
}


