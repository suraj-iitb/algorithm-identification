#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int num=0;

void marge(int a[], int left, int mid, int right){
	int n1 = mid-left;
	int n2 = right-mid;
	vector<int> a1(n1);
	for(int i=0; i<n1; i++)
		a1[i] = a[left+i];
	a1.push_back(INT_MAX);
	vector<int> a2(n2);
	for(int i=0; i<n2; i++)
		a2[i] = a[mid+i];
	a2.push_back(INT_MAX);
	int ltop = 0;
	int rtop = 0;
	for(int i=left; i<right; i++){
		if(a1[ltop]<=a2[rtop]){
			a[i] = a1[ltop];
			ltop++;
		}else{
			a[i] = a2[rtop];
			rtop++;
		}
		num++;
	}
}

void margeSort(int a[], int left, int right){
	if(left+1<right){
		margeSort(a, left, (left+right)/2);
		margeSort(a, (left+right)/2, right);
		marge(a, left, (left+right)/2, right);
	}
}

int main(){
	int n;
	cin >> n;
	int s[500000];
	for(int i=0; i<n; i++)
		cin >> s[i];
	margeSort(s, 0, n);
	for(int i=0; i<n; i++){
		if(i)
			cout << ' ';
		cout << s[i];
	}
	cout << endl;
	cout << num << endl;
	return 0;
}
