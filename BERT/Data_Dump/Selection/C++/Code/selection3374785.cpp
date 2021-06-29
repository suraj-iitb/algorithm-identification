#include <iostream>
#include <vector>

int main()
{
    int num;
    std::cin >> num;
    std::vector<int> v;
    for(int i = 0; i < num; ++i){
        int val;
        std::cin >> val;
        v.push_back(val);
    }

    int count = 0;
    for(int i = 0; i < num; ++i){
        int mini = i;
        for(int j = i+1; j < num; ++j){
            if(v[j] < v[mini]){
                mini = j;
            }
        }
        if(i == mini) continue;
        count++;
        int tmp = v[i];
        v[i] = v[mini];
        v[mini] = tmp;
    }

    std::cout << v[0];
    for(int i = 1; i < num; i++){
        std::cout << ' ' << v[i];
    }
    std::cout << std::endl;

    std::cout << count << std::endl;

    return 0;
}

