#include <iostream>
#include <vector>

void showVector(std::vector<int> readVec){
    int length = readVec.size();
    for(int i = 0; i < length; ++i){
        if(length - 1 != i){
            std::cout << readVec.at(i) << " ";
        }else{
            std::cout << readVec.at(i);
        }
    }
    
    std::cout << std::endl;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a.at(i);
    }

    bool flg = true;
    int i, j, tmp;
    int count = 0;
    while(flg){
        flg = 0;
        for(i = n - 1; 1 <= i; --i){
            if(a.at(i) < a.at(i - 1)){
                a.at(i) += a.at(i - 1);
                a.at(i - 1) = a.at(i) - a.at(i - 1);
                a.at(i) = a.at(i) - a.at(i - 1);
                flg = true;
                ++count;
            }
        }
    }
    
    showVector(a);    
    std::cout << count << std::endl;

    return 0;
}

