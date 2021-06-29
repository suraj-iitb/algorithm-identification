#include<iostream>
using namespace std;
int a[2000000],b[10001],n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[a[i]]++;
		}
    int t=0;
    for(int i=0;i<=10000;i++){
        while(b[i]>=1)
        {
            a[t++]=i;
            b[i]--;
        }
    }
    for(int i=0;i<n;i++){
		if(i==n-1){
    		cout<<a[i]<<endl;
		}else{
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
