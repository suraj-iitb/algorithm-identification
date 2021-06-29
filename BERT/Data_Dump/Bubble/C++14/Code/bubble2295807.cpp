#include <cstdio>
#include <iostream>
#include <vector>

int counter = 0;

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    counter++;
}

void do_bubble_sort(std::vector<int>& data)
{
    for(int i = 0; i < data.size() - 1; i++) {
        for(int j = 0; j < data.size() - 1 - i; j++) {
            if(data[j + 1] < data[j]) {
                swap(&data[j], &data[j + 1]);
            }
        }
    }
}

void show_data(std::vector<int>& data)
{
    printf("%d", data[0]);
    for(int i = 1; i < data.size(); i++) {
        printf(" %d", data[i]);
    }
    puts("");
}

int main()
{
    int input_size;
    std::cin >> input_size;
    std::vector<int> data(input_size);
    for(int i = 0; i < data.size(); i++) {
        std::cin >> data[i];
    }

    do_bubble_sort(data);

    show_data(data);
    printf("%d\n", counter);

    return 0;
}
