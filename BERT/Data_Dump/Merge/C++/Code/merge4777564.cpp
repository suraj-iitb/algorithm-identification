#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

/* scan char
char* a_tmp[2]; //{' ', '\0'}
scanf("%c", a_tmp);//アルファベット1文字
*/

/*scan str
vector<char> a_tmp;
int n = ;//loop回数

for(int i=0;i<n;i++){
  scanf("%c", a_tmp[i]);
}

*/

using namespace std;

vector<int> v;
int cnt = 0;

void merge(int left, int mid, int right) {
	vector<int> L, R;
	for (int i = 0; i < mid - left; i++) L.push_back(v[left + i]);
	for (int i = 0; i < right - mid; i++) R.push_back(v[mid + i]);
	L.push_back(INFINITY);
	R.push_back(INFINITY);
	
	int i = 0;
	int j = 0;

	for (int k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			v[k] = L[i];
			i++;
		}
		else {
			v[k] = R[j];
			j++;
		}
		cnt++;
	}
	return;
}

void mergeSort(int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(left,  mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
	return;
}

int main(){
	int n = 0;
	cin >> n;

	int tmp = 0;
	for(int i= 0; i<n; i++){
		cin >> tmp;
		v.push_back(tmp);
	}

	mergeSort(0, v.size());
	cout << v[0];
	for (int i = 1; i < v.size(); i++) cout << ' ' << v[i];
	cout << endl << cnt << endl;

	return 0;
}
