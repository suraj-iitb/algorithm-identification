#include<iostream>
#include<vector>
using namespace std;
static const int INF = 2000000000;
vector<int>l(300000), r(300000);
int count1=0;

void merge(vector<int>& v, int left,int mid,int right) {
	int n1 = mid - left; int n2 = right - mid;
	for (int i = 0; i <n1; i++)l[i]=v[left+i];
	for (int i = 0; i < n2; ++i)r[i] = v[mid + i];
	l[n1]=INF; r[n2]=INF;//番兵
	int i = 0; int j = 0;
	for (int k = left; k < right; ++k) {
		++count1;
		if (l[i] <= r[j]) {
			v[k] = l[i];
			i++;
		}
		else {
			v[k] = r[j];
			j++;
		}
	}
}

void mergesort(vector<int>& v, int left, int right) {
	if (left + 1 < right) {//rightは配列の最後の要素+1だから
		int mid = (left + right) / 2;
		mergesort(v, left, mid);
		mergesort(v, mid, right);
		merge(v, left, mid, right);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)cin >> v[i];
	mergesort(v,0,n);
	for (int i = 0; i < n; ++i) {
		if (i)cout << " ";
		cout << v[i];
	}cout << endl;
	cout << count1 << endl;
	return 0;
}
