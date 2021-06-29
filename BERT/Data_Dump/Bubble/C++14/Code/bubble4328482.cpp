#include <iostream>
#include <vector>
#include <utility>

void print(std::vector<int> &vec){
    for(int i = 0; i < vec.size(); ++i){
        std::cout << vec.at(i);
        if(vec.size() - 1 != i){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
}

void insertionSort(std::vector<int> &vec){
    // This function sorts the partial array from the index "0" to "i" at each step.
    // In the loop where the "i + 1" th value is considered, the value will be inserted in a proper place in the "0-i" array or its end.
    for(int i = 1; i < vec.size(); ++i){
        auto v = vec.at(i), j = i - 1;
        while(0 <= j && v < vec.at(j)){
            vec.at(j + 1) = vec.at(j);
            --j;
        }
        // Because of "--j" at the end of the while loop, j indicate the index prior to the target place by 1.
        // Hence, j has to be incremented before the "v" is inserted in the proper place.
        vec.at(j + 1) = v;

        print(vec);
    }
}

int bubbleSort(std::vector<int> &vec){
    bool flg = true;
    int count = 0;
    while(flg){
        flg = false;
        // Compare the array in a reverse order
        for(int i = vec.size() - 1; 0 < i; --i){
            if(vec.at(i) < vec.at(i - 1)){
                std::swap(vec.at(i), vec.at(i - 1));
                flg = true; // If some two elements will be swapped, the next while loop will be activated.
                ++count;
            }
        }
    }

    return count;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a.at(i);
    }

    // for alds1_1_a.cpp
//    print(a);
//    insertionSort(a);

    // for alds1_2_a.cpp
    auto val = bubbleSort(a);
    print(a);
    std::cout << val << std::endl;
    
    return 0;
}
