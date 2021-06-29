#include <iostream>
#include <vector>
using namespace std;

int p,n;


pair<int,string> A[100010], s[100010];

void merge(int l, int m, int r) {
	int n1 = m - l, n2 = r - m;
	pair<int,string> L[n1 + 1], R[n2 + 1];
	for (int i = 0; i < n1; i++){
		L[i] = s[l + i];
    }
	for (int i = 0; i < n2; i++){
		R[i] = s[m + i];
    }
    L[n1].first = 1000000010;
    R[n2].first = 1000000010;
    int i = 0, j = 0;
	for (int k = l; k < r; k++) {
		if (L[i].first <= R[j].first) {
			s[k] = L[i];
			i++;
		}else {
			s[k] = R[j];
			j++;
		}
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

int partition(int p,int r){
    int x = A[r].first;
    int i = p-1;
    for (int j=p; j<r; j++){
        if (A[j].first <= x){
        i++;
        swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

int quicksort(int p,int r){
    if(p < r){
        int q = partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
    return 0;
}

int main(){
    cin >> n;
    bool flag = true;

    for(int i=0; i<n; i++){
        cin >> A[i].second >> A[i].first;
        s[i] = A[i];
    }
    quicksort(0,n-1);
    mergesort(0,n);

    for(int i=0; i<n; i++){
        if(A[i] != s[i]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    for(int i=0; i<n; i++){
        cout << A[i].second << " " << A[i].first << endl;
    }
    return 0;
}

