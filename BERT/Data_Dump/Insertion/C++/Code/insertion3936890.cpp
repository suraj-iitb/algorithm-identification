#include<iostream>
using namespace std;
int a[105];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n-1;++i){						//4.原来没打 
		cout<<a[i]<<' ';						//4.					 
	}											//4.					
	cout<<a[n-1]<<endl;							//4.
	for(int i=1;i<n;++i){
		int t=a[i];
		int j=i-1;
		while(j>=0&&a[j]>t){					//3.升序是">",降序是"<" 
			a[j+1]=a[j];						 
			--j;
		}
		a[j+1]=t;								//1.后一位（原打成a[j]） 
		for(int i=0;i<n-1;++i){					//2.此循原来写外面了 
			cout<<a[i]<<' ';					//2. 
		}										//2.
		cout<<a[n-1]<<endl;						//2.
	}
	return 0;
} 
