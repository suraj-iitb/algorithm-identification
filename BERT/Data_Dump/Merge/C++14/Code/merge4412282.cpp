#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//using ll = long long;
using namespace std;

const int INF = 1001001001;
int co = 0;

void merge(vector<int> &a, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	vector<int> l(n1+1), r(n2+1);
	rep(i, n1) l.at(i) = a.at(left+i);
	rep(i, n2) r.at(i) = a.at(mid+i);
	l.at(n1) = r.at(n2) = INF;
	int i = 0, j = 0;
	for(int k = left; k < right; k++){
		co++;
		if(l.at(i) <= r.at(j)){
			a.at(k) = l.at(i);
			i++;
		}else{
			a.at(k) = r.at(j);
			j++;
		}
	}
}

void mergeSort(vector<int> &a, int left, int right){
	if(left + 1 < right){
		int mid = (left+right)/2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> s(n);
	rep(i, n) cin >> s.at(i);
	mergeSort(s, 0, n);
	rep(i, n){
		if(i != 0) cout << " ";
		cout << s.at(i);
		
	}
	cout << endl;
	cout << co << endl;
	
	return 0;
}
