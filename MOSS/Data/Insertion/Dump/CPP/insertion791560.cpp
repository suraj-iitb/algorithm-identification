#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}
	for(int k=0; k<n; ++k){
			if(k+1 != n){
				cout << arr[k] << " ";
			} else{
				cout << arr[k] << endl;
			}
	}
	for(int i=1; i<n; ++i){
		int j;
		int tmp = arr[i];
		
		for( j=i; j>0 && arr[j-1]>tmp; --j){
			arr[j] = arr[j-1];
		}
		arr[j] = tmp;

		for(int k=0; k<n; ++k){
			if(k+1 != n){
				cout << arr[k] << " ";
			} else{
				cout << arr[k] << endl;
			}
		}

	}
}
