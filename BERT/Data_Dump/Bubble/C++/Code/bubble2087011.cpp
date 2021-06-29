#include<iostream>
using namespace std;
int main(){
	int n,temp,cnt,flag;
	while(cin >> n){
		int k=0;
		int a[n];

		while(k!=n){
			cin >> a[k];
			k++;
		}
		cnt=0;
		flag=1;
		while(flag){
			flag=0;
			for(int i=0;i<n-1;i++){
				if(a[i]>a[i+1]){
					temp=a[i+1];
					a[i+1]=a[i];
					a[i]=temp;
					cnt++;
					flag=1;
				}
			}
		}

	
		int l=0;
		while(l!=n-1){
			cout << a[l] << " ";
		l++;
		}
		cout << a[n-1]<< endl;
		cout << cnt << endl;
	}
	return 0;
}
