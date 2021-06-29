#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> A(n);

	for(int i = 0 ; i < n;i++){
		cin >> A[i];
	}





	int flag = 1;
	int count = 0;
	int index = 0; //先頭部分のインデックス

	while(flag == 1){
flag = 0;
		for(int j = n-1;j > index;j--){
			if(A[j-1] > A[j]){
				swap(A[j-1],A[j]);
				count++;
			}
			flag = 1;
		}
		index++;
	}


	for(int i = 0;i < n-1;i++){
		cout << A[i] <<' ' ;
	}
	cout << A[n-1] <<endl;
	cout << count <<endl;

}
