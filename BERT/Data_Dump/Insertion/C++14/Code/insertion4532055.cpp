#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); i++)
vector<int> insertsort(vector<int> &a){
    for (int i=1; i<a.size(); i++){
        int v=a[i];//動かす値を持つ
        int j=i-1;//調べる上限を持つ
      	rep(i, a.size()){
      	    cout << a[i];
      	    if (i != a.size()-1) cout << " ";
            else cout << endl;
      	} 
        while (j>=0 && a[j] > v){
            a[j+1] = a[j];//動かす値が上限より小さい場合、挿入するので、
            j--;
        }
        a[j+1] = v;
        }
  	return a;
}
int main(){
    
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
  	insertsort(a);
  	rep(i, a.size()){
      cout << a[i];
      if (i != a.size()-1) cout << " ";
   	  else cout << endl;
    }
}
