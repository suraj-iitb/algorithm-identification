/*
* @Author: Ahmad
* @Date:   2020-12-29 12:46:41
* @Last Modified by:   Ahmad
* @Last Modified time: 2020-12-29 13:13:30
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct IOFast
{
   ios_base::Init i;
   IOFast() {
      cin.sync_with_stdio(0);
      cin.tie(0);
      cout.sync_with_stdio(0);
      cout.tie(0);
   }
} IOFast;

vector<ll> BubbleSort(vector<ll> v,int* c){
    for(int i = 0; i < v.size() ; ++i){
        for(int j = v.size() - 1 ; j > i ; j--){
            if (v[j] < v[j-1]){
                swap(v[j], v[j - 1]);
                (*c)++;
            }
        }
    }
    return v;
}
void print(vector<ll> v){
	for (int i = 0; i < v.size(); i++){
		cout << v[i];
	    if(i < v.size() - 1)
	    	cout << " ";
	}
	cout << "\n";
}
void solve(){
    int x; cin >> x;
    vector<ll> v;
    for (int i = 0; i < x; ++i){
		ll r; cin >> r;
		v.push_back(r);
    }
    int count = 0;
    v = BubbleSort(v, &count);
    print(v);
    cout << count << "\n";
}

int main(){
   solve();
// #ifndef Time
// 	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
// #endif
	return 0;
}	

