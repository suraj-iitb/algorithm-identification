#include <iostream>
#include <vector>

int main(){
    int num;
    std::vector<int> v;
    std::cin >> num;

    for(int i = 0; i < num; ++i){
        int val;
        std::cin >> val;
        v.push_back(val);
    }

    int swapCount = 0;
    for(int i = 0; i < num; ++i){
        for(int j = num -1; j > i; --j){
            if(v[j] < v[j - 1]){
                int tmp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tmp;
                ++swapCount;
            }
        }
    }

    std::cout << v[0];
    for(int i = 1; i < num; ++i){
        std::cout << ' ' << v[i];
    }
    std::cout << std::endl;
    std::cout << swapCount << std::endl;

    return 0;
}
