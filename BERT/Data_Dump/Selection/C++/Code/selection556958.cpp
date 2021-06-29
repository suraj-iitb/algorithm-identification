#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

void InputSet(std::vector<int> & a) {
	int n;
	cin >> n;
	a.resize(n,0);
	for(int i=0;i<n;++i) {
		cin >> a.at(i);
	}
}
void Printf(std::vector<int> & a) {
	for(int i=0;i<(int)a.size();++i) {
		if (i>0){ 
			cout << " ";
		}
		cout  << a.at(i);
	}
	cout << std::endl;
}

void SelectionSort(std::vector<int> & A,int & swaptimes)
{
	for(int i=0;i<(int)A.size();++i){
		int mini=i;
		for(int j=i;j<(int)A.size();++j){
			if (A[j] < A[mini]) {
				mini = j;
			}
		}
		if (mini != i) {
			int tmp = A[mini];
			A[mini] = A[i];
			A[i]=tmp;
			swaptimes++;
		}
	}
}
int main(){
	std::vector<int> A;
	::InputSet(A);
	int swaptimes=0;
	SelectionSort(A,swaptimes);
	::Printf(A);
	cout << swaptimes << std::endl;
}
