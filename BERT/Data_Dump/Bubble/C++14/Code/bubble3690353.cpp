#include <bits/stdc++.h>
using namespace std;


	



int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];

	bool flg=1;
	int v,counter=0;
	
	for(int i=0;flg;i++){
		flg =0;
		for(int j=n-1;i<j;j--){
			if(a[j-1]>a[j]){
				v=a[j-1];
				a[j-1]=a[j];
				a[j]=v;
				counter++;
				flg=1;
			}
			
		}
	}

	for(int i=0;i<n-1;i++){
		cout<<a[i]<<" ";
	}
	cout<<a[n-1]<<endl;
	cout<<counter<<endl;
	


	return 0;
}


