#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(auto &&i : a)
        std::cin >> i;
    
    int count = 0;
    for(int i=0; i<n; i++){
        int min_index = i;
        for(int j=i; j<n; j++){
            if(a.at(j) < a.at(min_index)){
                min_index = j;
            }
        }
        if(i != min_index){
            std::swap(a.at(min_index), a.at(i));
            count += 1;
        }
    }
    for(int i=0; i<n; i++){
        std::cout << a.at(i) << ((i == n - 1) ? "\n" : " ");
    }
    std::cout << count << std::endl;
}   
