#include <cstdio>
#include <iostream>
#include <vector>

int swap_counter = 0;

void show_data(std::vector<int>& data)
{
    printf("%d", data[0]);
    for(int i = 1; i < data.size(); i++) {
        printf(" %d", data[i]);
    }
    puts("");
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    swap_counter++;
}

void do_selection_sort(std::vector<int>& data)
{
    int min_index;
    for(int i = 0; i < data.size() - 1; i++) {
        min_index = i;
        for(int j = i; j < data.size(); j++) {
            if(data[j] < data[min_index]) {
                min_index = j;
            }
        }
        if(i != min_index) {
            swap(&data[i], &data[min_index]);            
        }
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

    do_selection_sort(data);
    show_data(data);
    printf("%d\n", swap_counter);

    return 0;
}
