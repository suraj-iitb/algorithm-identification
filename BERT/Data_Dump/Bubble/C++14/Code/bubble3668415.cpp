#include<bits/stdc++.h>

int main(){
    using namespace std;
    size_t n;
    cin >> n;
    
    vector<size_t> a(n);
    for(auto& i : a)cin >> i;
    
    unsigned long ans{0};
    
    bool f{true};
    while(f){
        f = false;
        for(size_t i = 1; i < n; ++i)if(a[i] < a[i - 1] && ++ans && (f = true))swap(a[i], a[i - 1]);
    }
    copy(a.begin(), a.end() - 1, ostream_iterator<size_t>(cout, " "));
    cout << a.back() << endl << ans << endl;
}
