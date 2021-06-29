#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){

	int n;
	cin >> n;

	int box[n];
	for(int k=0 ;k<n;k++){
			cin >>box[k];
			if(k==n-1)
				cout << box[k];
			else
				cout << box[k] << " ";
	}// 入力終わり
	cout << endl;

	int k;
	for(int i=1 ; i < n;i++){

		int v = box[i];
		int j = i-1;
		while(j >=0 && box[j] >v){
			box[j+1] = box[j];
			j--;
		}
		box[j+1] = v;
		for(k = 0; k< n;k++){
			if(k==n-1)
				cout << box[k];
			else
				cout << box[k] << " ";
		}
		cout << endl;
	}

	return 0;
}
