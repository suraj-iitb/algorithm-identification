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
    for(int i = 0; i < num_cnt; i++) {

        int min_idx = i;
        for(int j = i; j < num_cnt; j++) {

            if(data[j] < data[min_idx]) {

                min_idx = j;
            }
        }
        if(min_idx != i) {

            swap_cnt++;
            std::swap(data[i], data[min_idx]);
        }
    }

    for(int i = 0; i < data.size(); i++) {

        std::cout << data[i];
        if(i != data.size() - 1) std::cout << " ";
    }
    std::cout << std::endl << swap_cnt << std::endl;
}

