#include<bits/stdc++.h>
using namespace std;

const int INF_M = 1000000001;

int countI = 0;

int lArr[250001];
int rArr[250001];

void marge(int* a, int start,int end,int mid){
	int n1 = mid - start;
	int n2 = end - mid;
	for(int i = 0; i < n1;i++){
		lArr[i] = a[start + i];
	}
	lArr[n1] = INF_M;
	for(int i = 0;i < n2;i++){
		rArr[i] = a[mid + i];
	}
	rArr[n2] = INF_M;

	int iL = 0;
	int iR = 0;
	for(int i = start; i < end;i++){
		countI++;
		if(lArr[iL] <= rArr[iR]){
			a[i] = lArr[iL];
			iL++;
		}else{
			a[i] = rArr[iR];
			iR++;
		}	
	}
}

void margeSort(int* a,int start,int end){
	if(start + 1 < end){
		int mid = (start +  end) / 2;
		margeSort(a,start,mid);
		margeSort(a,mid,end);
		marge(a,start,end,mid);
	}
}

int main(){
	int n;
	cin >> n;
	int a[500000];
	for(int i = 0; i < n;i++){
		cin >> a[i];
	}
	margeSort(a,0,n);
	for(int i = 0;i < n;i++){
		cout << a[i] << ((i != n -1) ? " " : "") << flush;
	}
	cout << endl;
	cout << countI << endl;
}
