#include <iostream>
#include <utility>
#include <vector>
using namespace std;


int cnt=0;
vector<int> bsort(vector<int> vec){
     for(int i=0;i<vec.size()-1;++i){
        for(auto itr=vec.rbegin();itr!=vec.rend()-i;++itr){
            if(*itr>=*(itr+1)) continue;
            swap(*itr,*(itr+1));
            cnt++; 
        }
    }
    return vec;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int nb; cin>>nb;
    std::vector<int> lines; lines.resize(nb);
    for(auto& a:lines) cin>>a;
    
    auto sorted = bsort(lines);
    for(auto& a:sorted) cout<<a<<(&a!=&sorted.back()?" ":"\n");
    cout<<cnt<<"\n";
}
