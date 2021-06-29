#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int data[n];
	for(int i = 0; i < n; i++){
		cin >> data[i];
	}
	for(int i = 0; i < n; i++){
		int tmp = data[i];
		int j = i - 1;
		while( j >= 0 and data[j] > tmp){
			data[j+1] = data[j];
			j--;
		}
		data[j+1] = tmp;		
		for(int k = 0; k < n; k++){
			if(k !=0) cout << " ";
			cout << data[k];
		}
		cout << endl;
	}
	return 0;
}
