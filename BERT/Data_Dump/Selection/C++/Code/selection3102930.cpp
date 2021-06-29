#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int count = 0;
	for(int i = 0; i < n; i++){
        int minj = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(minj == i){
            continue;
        }
        else{
            swap(a[i], a[minj]);
            count++;
        }
    }
	for(int i = 0; i < n; i++){
		if(i == 0){
			cout << a[i];
		}
		else{
			cout << ' ' << a[i];
		}
	}
	cout << endl <<  count << endl;
}

