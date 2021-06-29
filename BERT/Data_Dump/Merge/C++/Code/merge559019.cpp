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

void Merge(std::vector<int> & A, int left, int mid, int right,int & comps)
{
	int n1 = mid - left;
	int n2 = right - mid;
//  create array L[0...n1], R[0...n2]
	static std::vector<int> L,R;
	if (n1+1 > (int)L.size()) L.resize(n1+1);
	if (n2+1 > (int)R.size()) R.resize(n2+1);
	//for (int i = 0; i<n1;++i) {
	//	L[i] = A[left + i];
	//}
	std::copy(A.begin()+left,A.begin()+mid,L.begin());
	//for (int i = 0; i<n2;++i) {
	//	R[i] = A[mid + i];
	//}
	std::copy(A.begin()+mid,A.begin()+right,R.begin());
	const int SENTINEL=(int)(((unsigned int)(-1))>>1);
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	int i = 0;
	int j = 0;
	for (int k = left; k<right;++k) {
		++comps;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		} else {
			A[k] = R[j];
			j = j + 1;
		}
	}
}

void MergeSort(std::vector<int> & A, int left, int right,int & comps)
{
	if (left+1 < right) {
		int mid = (left + right)/2;
		MergeSort(A, left, mid,comps);
		MergeSort(A, mid, right,comps);
		Merge(A, left, mid, right,comps);
	}
}

int main(){
	std::vector<int> A;
	::InputSet(A);
	int comps=0;
	MergeSort(A,0,(int)A.size(),comps);
	::Printf(A);
	cout << comps << std::endl;
}
