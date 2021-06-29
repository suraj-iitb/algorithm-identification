#include<iostream>
#include<vector>
#include<string>
using namespace std;

void InputSet(std::vector<int> & a) {
	int n;
	cin >> n;
	a.resize(n,0);
	for(int i=0;i<n;++i) {
		cin >> a.at(i);
	}
}
void Print(std::vector<int> & a) {
	for(int j=0;j<(int)a.size();++j){
		if(j==0){
			cout << a[j];
		} else  {
			cout << " " << a[j];
		}
	}
	cout << endl;
}
int main(){
	vector<int> A;
	::InputSet(A);
	int n = (int)A.size();
		Print(A);
	for(int j=1;j<n;++j){
		int key = A[j];
		int i=j-1;
		while(i>=0 && A[i] > key) {
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
		Print(A);
	}
}
