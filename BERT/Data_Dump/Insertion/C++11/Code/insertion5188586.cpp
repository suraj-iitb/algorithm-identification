#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll= long long;

void print_s(vector<int> s,int n){
rep(i,n){
	if(i>0) cout<<" ";
  	cout<<s[i];
}
  cout<<endl;
}
void sort(vector<int> s,int n){
int j,i,v;
for(int i=1;i<n;i++){
    int v=s[i];
    int j=i-1;
    while(j>=0 && s[j]>v){
        s[j+1]=s[j];
        j--;
    }
        s[j+1]=v;
		print_s(s,n);    
}

}

int main(void){
int num;
cin>>num;
vector<int> S(num);
rep(i,num) cin>>S[i];
print_s(S,num);
sort(S,num);
}
