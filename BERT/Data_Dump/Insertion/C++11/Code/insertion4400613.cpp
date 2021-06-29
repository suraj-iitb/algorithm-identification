#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    
    std::vector<int> v;
    int tmp;
    while(std::cin >> tmp){v.push_back(tmp);}
    
    auto print_v = [](std::vector<int> v){ 
        for(int i=0; i<v.size(); i++){
            std::cout << v[i] ;
            if(i<v.size()-1){
                std::cout << " ";
            }else{
                std::cout << std::endl;
            }
        }
    };
    print_v(v);
    
    for(int i=1; i<v.size(); i++){
        int j = i+1;
        while(--j>=0 && v[j-1] > v[j]){
            std::swap(v[j-1], v[j]);
        }
        print_v(v);
    }
    
}
