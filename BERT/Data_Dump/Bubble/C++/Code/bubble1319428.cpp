#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b){
	int h = a;
	a = b;
	b = h;
}

int BubbleSort(vector<int>& A){
	int count = 0;
	for(int i = 0;i<A.size();i++){
		for(int j = A.size()-1; j>i; j--){
			if(A[j] < A[j-1]){
				count++;
				swap(A[j], A[j-1]);
			}
		}
	}
	return count;
}

int main(){
	int n,h;
	vector<int> v;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> h;
		v.push_back(h);
	}
	int c = BubbleSort(v);
	cout << v[0];
	for(int i=1;i<n;i++){
		cout << " " << v[i];
	}
	cout << endl << c << endl;
	return 0;
}
