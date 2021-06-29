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

    int num_cnt = 0;
    in >> num_cnt;
    std::vector<int> data;
    data.reserve(num_cnt);
    for(int i = 0; i < num_cnt; i++) {
        
        int tmp = 0;
        in >> tmp;
        data.push_back(tmp);
    }

    int swap_cnt = 0;
    for(int i = num_cnt - 1; i >= 0; i--) {

        for(int j = 0; j < i; j++) {

            if(data[j] > data[j+1]) {

                std::swap(data[j], data[j+1]);
                swap_cnt++;
            }
        }
    }

    for(int i = 0; i < data.size(); i++) {

        std::cout << data[i];
        if(i != data.size() - 1) std::cout << " ";
    }
    std::cout << std::endl << swap_cnt << std::endl;
}













