#include <iostream> // std::cout & std::endl
#include <string>   // std::to_string 
#include <vector>
#include <algorithm>// std::reverse
#include <fstream>

std::string file_name = "./case.txt";

int main() {

#ifdef DEBUG
    std::ifstream in(file_name);
    if(!in) {
        std::cout << "can not open file: " << file_name << std::endl;
    }
#else
    #define in std::cin 
#endif

    int cnt = 0;
    in >> cnt;
    std::vector<int> data;
    data.reserve(cnt);
    while(cnt--) {
        
        int tmp = 0;
        in >> tmp;
        data.push_back(tmp);
    }

    for(int i = 0; i < data.size(); i++){
    
        for(int j = i - 1; j >= 0; j--) {
        
            if(data[j] > data[j+1]) {
                
                std::swap(data[j], data[j+1]);
            }
            else 
                break;
        }

        for(int k = 0; k < data.size(); k++) {
            
            
            std::cout << data[k];
            if(k != data.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
}













