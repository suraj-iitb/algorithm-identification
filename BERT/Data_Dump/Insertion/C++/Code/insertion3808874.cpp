#include <iostream>

void input_ex(int arr[], int* N);
void output_ex(int arr[], int N);
void sort_ex(int arr[], int N);

int main()
{
    int arr[100];
    int N;

    input_ex(arr, &N);
    output_ex(arr, N);
    sort_ex(arr, N);

}

void sort_ex(int arr[], int N)
{
    int v, j, i;

    for (i = 1; i < N; ++i){
        v = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > v){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = v;
        output_ex(arr, N);
    }
}

void output_ex(int arr[], int N)
{
    for (int x = 0; x < N; ++x){
        if (x > 0)
            std::cout << " ";

        std::cout << arr[x];
    }
        std::cout << std::endl;

    return;
}

void input_ex(int arr[], int* N)
{
    std::cin >> *N;
    for (int x = 0; x < *N; ++x){
        std::cin >> arr[x];
    }

    return;
}

