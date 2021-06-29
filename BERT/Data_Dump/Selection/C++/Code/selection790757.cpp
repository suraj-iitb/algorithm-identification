#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
int main(){
    int n;
	cin >> n;
    if(n >= 0 && n < 100){
		cout << "00" << endl;
    } else if(n >= 100 && n <= 5000){
		if((int)n/100<10){
			cout << "0" << n/100 << endl;
		} else{
			cout << n/100 << endl;
		}
    } else if(n >= 6000 && n<=30000){
		cout << (n/1000)+50 << endl;
    } else if(n >= 35000 && n<=70000){
	    cout <<  (n/1000-30)/5+80 << endl;
    } else if(n > 70000){
		cout << 89 << endl;
    }
	
    return 0;
}*/

int main(){
	int n;
	int hoge[100];
	int sum=0;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> hoge[i];
	}

	for(int i=0; i<n-1; ++i){
		int min_index = i;
		for(int j=i+1; j<n ;++j){
			if(hoge[min_index]> hoge[j]){
				min_index = j;
			}
		}
		if(min_index != i){
			int tmp = hoge[i];
			hoge[i] = hoge[min_index];
			hoge[min_index] = tmp;
			++sum;
		}
	}
	for(int i=0; i<n; ++i){
		if(i+1 != n)
			cout << hoge[i] << " ";
		else 
			cout << hoge[i] << endl;
	}
	cout << sum << endl;
}