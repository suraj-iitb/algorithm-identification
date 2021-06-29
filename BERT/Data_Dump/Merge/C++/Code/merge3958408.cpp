#include <iostream>

#define INFTY 1e15

using namespace std;

int count = 0;

void merge(int a[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int l[n1], r[n2];
	for(int i=0; i<n1; i++) l[i] = a[left+i];
	for(int i=0; i<n2; i++) r[i] = a[mid+i];
	l[n1] = INFTY;
	r[n2] = INFTY;
	int i=0;
	int j=0;
	for(int k=left; k<right; k++){
		count++;
		if(l[i] <= r[j]){
			a[k] = l[i];
			i++;
		}else{
			a[k] = r[j];
			j++;
		}
	}
}

void mergeSort(int a[], int left, int right){
	if(left+1 < right){
		int mid = (left + right)/2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main(){
	int n;
	cin >> n;

	int array[n];
	for(int i=0; i<n; i++) cin >> array[i];

	mergeSort(array, 0, n);

	for(int i=0; i<n; i++){
		cout << array[i];
		if(i!=n-1) cout << " ";
	}
	cout << endl;
	cout << count << endl;

	return 0;
}
