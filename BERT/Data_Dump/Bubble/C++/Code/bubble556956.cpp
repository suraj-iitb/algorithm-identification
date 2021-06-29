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

void BubbleSort(std::vector<int> & A,int & swaptimes)
{
	for(int i=0;i<(int)A.size();i++){
		for(int j=(int)A.size()-1;j>i;--j){
			if (A[j] < A[j-1]) {
				int tmp = A[j];
				A[j] = A[j-1];
				A[j-1]=tmp;
				swaptimes++;
			}
		}
	}
}

int main(){
	std::vector<int> A;
	::InputSet(A);
	int swaptimes=0;
	BubbleSort(A,swaptimes);
	::Printf(A);
	cout << swaptimes << std::endl;
}
