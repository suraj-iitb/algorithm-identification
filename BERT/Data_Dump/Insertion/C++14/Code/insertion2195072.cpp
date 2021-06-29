#include <iostream>
#include <vector>
using namespace std;

void isort(std::vector<int> vec){
    for(int i=0;i<vec.size();++i){
        auto v = vec[i];
      
        int j=i-1;
        for (j; j>=0; --j ){
            if(vec[j]<=v) break;
            vec[j+1] = vec[j];
        }
        vec[j+1] = v;

        for(auto& a:vec) cout<<a<<((&a!=&vec.back())? " ":"\n");
    }
} 

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int nb; cin>>nb;
    std::vector<int> cards; cards.resize(nb);
    for(auto& a:cards) cin>>a;
    isort(cards);
}
