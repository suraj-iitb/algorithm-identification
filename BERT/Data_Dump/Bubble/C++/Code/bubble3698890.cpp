#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin >> n;
	int build[n] = {};

	for(int i=0; i<n;i++){
		cin >> build[i];
	}

	int count =0;
	bool flag = 1;
	while(flag){
		flag =0;
		for(int j=n-1;j>0;j--){
			if(build[j] < build[j-1]){
				swap(build[j],build[j-1]);
				count++;
				flag = 1;
			} 
		}
	}
	

	for(int i=0;i<n;i++) cout << build[i] << " \n"[i==n-1];
	cout << count << endl;


    return 0;
}

