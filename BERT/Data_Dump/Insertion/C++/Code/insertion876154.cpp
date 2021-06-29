#include<cstdio>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<cwctype>
#include<algorithm>
#include<math.h>

using namespace std;

int data[101];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>data[i];
	}

	for(int i=1;i<=n;i++){
		if(i==1)cout<<data[i];
		else cout<<" "<<data[i];
	}

	cout<<endl;

	for(int j=2;j<=n;j++){
		int key=data[j],i=j-1;

		while(i>0 && data[i]>key){
			data[i+1]=data[i];
			i--;
		}

		data[i+1]=key;
		for(int i=1;i<=n;i++){
			if(i==1)cout<<data[i];
			else cout<<" "<<data[i];
		}
		cout<<endl;
	}
	
		return 0;
}
