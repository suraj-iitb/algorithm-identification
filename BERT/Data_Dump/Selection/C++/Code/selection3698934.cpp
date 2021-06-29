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
	for(int i=0; i<n ;i++){
		int mini = i;
		for(int j=i;j<n;j++){
			if(build[mini] > build[j])
				mini = j;
		}
		if(build[mini] != build[i]){
			swap(build[mini],build[i]);
			count++;
		}
			
	}
	

	for(int i=0;i<n;i++) cout << build[i] << " \n"[i==n-1];
	cout << count << endl;


    return 0;
}

