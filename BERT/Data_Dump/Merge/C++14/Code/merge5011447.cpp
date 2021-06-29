#include <iostream>
#include <vector>
using namespace std;

int n, s[500000], cnt;

void merge(int l, int m, int r) {
	int n1 = m - l, n2 = r - m;
	vector<int> L(n1 + 1, 1000000001), R(n2 + 1, 1000000001);
	for (int i = 0; i < n1; i++){
		L[i] = s[l + i];
    }
	for (int i = 0; i < n2; i++){
		R[i] = s[m + i];
    }
    int i = 0, j = 0;
	for (int k = l; k < r; k++) {
		if (L[i] <= R[j]) {
			s[k] = L[i];
			i++;
		}else {
			s[k] = R[j];
			j++;
		}
		cnt++;
	}
}
void mergesort(int l, int r) {
	if (l + 1 < r) {
		int m = (l + r) / 2;
		mergesort(l, m);
		mergesort(m, r);
		merge(l, m, r);
	}
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    mergesort(0,n);
    for(int i=0; i<n-1; i++){
        cout << s[i] << " ";
    }
    cout << s[n-1] << endl;
    cout << cnt << endl;
}
