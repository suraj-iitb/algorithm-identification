#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <iomanip>
#include <valarray>
#include <vector>
#include <sstream>

void output(std::vector<int> values){
    for(int i = 0; i < values.size()-1; ++i){
        std::cout << values[i] << " ";
    }
    std::cout << values[values.size()-1] << std::endl;
}


int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;
    std::vector<int> values;

    for(int i = 0; i < n; ++i){
        int val;
        std::cin >> val;
        values.push_back(val);
    }

    output(values);

    for(int i = 1; i < n; ++i){
        int key = values[i];
        int j = i-1;
        while(j >= 0 && values[j] > key){
            values[j+1] = values[j];
            --j;
        }
        values[j+1] = key;
        output(values);
    }

}
