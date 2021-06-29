#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<ctime>
#include<cstdlib>
#include<numeric>
#include <typeinfo>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)
const int inf=1e8;
const ll INF=1e16;
#define MOD 1000000007
#define mod 1000000009

int main(){
	int n;
	cin>>n;
	int a[n];
	loop(i,0,n){
		cin>>a[i];
	}
	loop(i,1,n){
		cout<<a[0];
		loop(i,1,n){
			cout<<" "<<a[i];
		}
		cout<<"\n";
		int v=a[i];
		int j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
	}
	cout<<a[0];
	loop(i,1,n){
		cout<<" "<<a[i];
	}
	cout<<"\n";
}
