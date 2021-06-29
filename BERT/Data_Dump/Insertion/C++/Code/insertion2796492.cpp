#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int v=a[i];
        int j=i-1;
        while(0<=j && a[j] > v){
        	a[j+1]=a[j];
		j--;
	}
	a[j+1]=v;
        for(int o=0;o<n;o++){
	  if(o) cout<<" ";
	  cout<<a[o];
        }
        cout<<endl;
    }
    return 0;
}
