/*
* @Author: Ahmad Hamadneh
* @Date:   2020-12-27 00:39:24
* @Last Modified by:   Ahmad Hamadneh
* @Last Modified time: 2020-12-28 00:50:40
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

class Sort
{
public:
    vector<ll> v;
	void insertionSort(){
        for(int i = 0; i < v.size(); ++i){
			    ll key = v[i];
			    int j = i - 1;
			    while (j >= 0 && v[j] > key){
			        v[j+1] = v[j];
			        j--;
			    }
			    v[j+1] = key;
			    print();
        }
	}
    void print(){
          for(int i = 0; i < v.size(); ++i)
          	  cout << v[i] << ((i == v.size() - 1) ? "\n" : " ");
	}	
};

void solve(){
	Sort s;
	int x; cin >> x;
	for (int i = 0; i < x; ++i){
		ll val; cin >> val;
        s.v.push_back(val);
	}
	s.insertionSort();
}

int main(){
   solve();

// #ifndef Time
	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
// #endif
	return 0;
}	

