#include <iostream>
#include <vector>

void printVector(std::vector<int> &vec)
{
    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        std::cout << (i ? " " : "") << vec[i];
    }
    std::cout << std::endl;
}

int main()
{
    int nums;
    std::cin >> nums;
    std::vector<int> v(nums);
    for (int i = 0; i < nums; ++i) {
        std::cin >> v[i];
    }
    printVector(v);
    
    for (int i = 1; i < nums; ++i) {
        int tmpVal = v[i];
        int idx = i - 1;
        while ((idx >= 0) && (v[idx] > tmpVal)) {
            v[idx + 1] = v[idx];
            --idx;
        }
        v[idx + 1] = tmpVal;
        printVector(v);
    }
    return 0;
}
