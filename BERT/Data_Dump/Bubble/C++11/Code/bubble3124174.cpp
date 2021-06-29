#include <iostream>
#include <vector>
#include <utility>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for(auto &&i : a)
        std::cin >> i;

    int count=0;

    bool flag = true;
    while(flag){
        flag = false;
        for(int j=n-1; j>0; j--){
            if(a[j] < a[j-1]){
                std::swap(a[j], a[j-1]);
                flag = true;
                count += 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        std::cout << a.at(i) << ((i == n - 1) ? "\n" : " ");
    }
    std::cout << count << std::endl;
}
