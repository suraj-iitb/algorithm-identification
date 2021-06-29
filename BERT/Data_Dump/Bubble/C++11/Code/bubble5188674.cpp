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
int bub_sort(vector<int> s,int n){
  int f=1,count=0;
  for(int i=0;f;i++){//f=0で終了
    f=0;
  	for(int j=n-1;j>=1+i;j--){
    	if(s[j]<s[j-1]){
        //swap
			swap(s[j],s[j-1]);
            f=1;
         	count++;
        }
    }
  }
  print_s(s,n);
  return count;
}

int main(void){
int num,ans;
cin>>num;
vector<int> S(num);
rep(i,num) cin>>S[i];
ans=bub_sort(S,num);
cout<<ans<<endl;
}
