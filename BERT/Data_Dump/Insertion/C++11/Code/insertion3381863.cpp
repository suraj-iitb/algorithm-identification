#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	array<int,100>ar;
	int i,j;
	int tmp;
	cin>>n;
	for(i=0;i<n;i++)	cin>>ar[i];
	for(i=0;i<n;i++){
		if(i==0)	cout<<ar[i];
		else		cout<<" "<<ar[i];
	}
	cout<<endl;
	for(i=1;i<n;i++){
		tmp=ar[i];
		j=i-1;
		while(j>=0&&ar[j]>tmp){
			ar[j+1]=ar[j];
			j--;
		}
		ar[j+1]=tmp;
		for(int k=0;k<n;k++){
			if(k==0)	cout<<ar[k];
			else		cout<<" "<<ar[k];
		}
		cout<<endl;
	}
	
	return 0;
}
	
