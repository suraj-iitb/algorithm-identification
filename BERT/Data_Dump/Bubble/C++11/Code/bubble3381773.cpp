#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	array<int,100>ar;
	int i,j;
	int cnt;
	int flg;
	cin>>n;
	for(i=0;i<n;i++)	cin>>ar[i];
	cnt=0;
	flg=1;
	i=0;
	while(flg){
		flg=0;
		for(j=n-1;j>=i+1;j--){
			if(ar[j]<ar[j-1]){
				swap(ar[j],ar[j-1]);
				flg=1;
				cnt++;
			}
		}
		i++;
	}
	for(i=0;i<n;i++){
		if(i==0)	cout<<ar[i];
		else		cout<<" "<<ar[i];
	}
	cout<<endl;
	cout<<cnt<<endl;
	return 0;
}
	
