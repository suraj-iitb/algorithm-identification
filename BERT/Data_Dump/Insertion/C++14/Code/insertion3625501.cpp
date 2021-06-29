#include<iostream>
#include<vector>

int main(){
    using namespace std;
    // input
    size_t n;
    cin >> n;
    vector<unsigned int> a(n);
    for(auto& i : a)cin >> i;
    
    auto output = [&a, &n](){for(size_t i = 0; i < n; ++i)cout << a[i] << " \n"[i + 1 == n];};
    
    // process
    for(size_t i = 1; i < n; ++i){
        output();
        auto v = a[i];
        auto j = i;
        for(; j-- > 0 && a[j] > v;)a[j + 1] = a[j];
        a[j + 1] = v;
    }
    output();
}
