#include <cstdio>
#include <iostream>
#include <vector>

void show_data(std::vector<int>& data)
{
    printf("%d", data[0]);
    for(int i = 1; i < data.size(); i++) {
        printf(" %d", data[i]);
    }
    puts("");
}

void solve(std::vector<int>& data)
{
    show_data(data);
    for(int i = 1; i < data.size(); i++) {
        int supposed_max = data[i];
        int j = i - 1;
        while(0 <= j && supposed_max < data[j]) {
            data[j + 1] = data[j]; // copy to higher index
            j--;
        }
        data[j + 1] = supposed_max;
        show_data(data);
    }
}

int main()
{
    int input_size;
    std::cin >> input_size;
    std::vector<int> data(input_size);
    for(int i = 0; i < data.size(); i++) {
        std::cin >> data[i];
    }

    solve(data);
    return 0;
}
