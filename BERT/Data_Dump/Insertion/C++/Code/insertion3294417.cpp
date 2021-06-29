#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> a,int n){
  	for(int i=0;i<n;i++){
      if(i!=n-1) cout<<a.at(i)<<" ";
      if(i==n-1) cout<<a.at(i)<<endl;;      
    }
}

void insertsort(vector<int> a,int n){
	int target,hikaku;
  	for(int i=1;i<n;i++){
    	target=a.at(i);
      	hikaku=i-1;
      while(hikaku>=0 && a.at(hikaku)>target){
      	a.at(hikaku+1)=a.at(hikaku);
        hikaku--;
        a.at(hikaku+1)=target;
      }
       print(a,n);
    }
}

int main(){
	int n;cin>>n;
  	vector<int> a(n);
  	for(int i=0;i<n;i++) cin>>a.at(i);
  	print(a,n);
  	insertsort(a,n);
}
