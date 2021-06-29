#include<bits/stdc++.h>
#define INFTY 1000000000
#define N 500000
using namespace std;
int num=0,n=0;
vector<int> a(N,0),L(N/2+2,0),R(N/2+2,0);

void merge(vector<int> &a,int left,int mid,int right){
	int n1 = mid - left;
	int n2 = right - mid;
	//vector<int> L(n1),R(n2);
	
	for(int i=0;i<n1;i++) L.at(i) = a.at(left+i);
	for(int i=0;i<n2;i++) R.at(i) = a.at(mid+i);
	
	L.at(n1) = INFTY;
	R.at(n2) = INFTY;
	//L.push_back(INFTY);
	//R.push_back(INFTY);

	int j=0,i=0;
	for(int k=left;k<right;k++){
		num++;
		if(L.at(i) <= R.at(j)){
			a.at(k) = L.at(i);
			i++;
		}else{
			a.at(k) = R.at(j);
			j++;
		}
	}
}

void mergeSort(vector<int> &a,int left,int right){
	int mid;
	if(left+1 < right){
		mid = (left+right)/2;
		//mergeSort(left,mid);
		mergeSort(a,left,mid);
		//mergeSort(mid,right);
		mergeSort(a,mid,right);
		//merge(left,mid,right);
		merge(a,left,mid,right);
	}
}

int main(){
	int i=0;
	cin >> n;
	for(i=0;i<n;i++) cin >> a.at(i);
	//mergeSort(0,n);
	mergeSort(a,0,n);
	
	for(i=0;i<n;i++){
		if(i == n-1) cout << a.at(i) << endl;
		else cout << a.at(i) << " ";
	}

	cout << num << endl;
}

