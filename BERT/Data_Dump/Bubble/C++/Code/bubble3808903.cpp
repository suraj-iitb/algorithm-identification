#include <iostream>


int bubble_sort(int arr[], int N);
void input_ex(int arr[], int *N);
void output_ex(int arr[], int N, int count);

int main()
{
    int arr[100];
    int N;
    int count = 0;

    input_ex(arr, &N);
    count = bubble_sort(arr, N);
    output_ex(arr, N, count);

    return 0;
}

int bubble_sort(int arr[], int N)
{
    int count = 0;
    int flag = 1;
    int v;

    while (flag){
        flag = 0;
        for (int j = N - 1; 0 < j; --j){
            if (arr[j] < arr[j - 1]){
                v = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = v;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

void input_ex(int arr[], int *N)
{
    std::cin >> *N;

    for (int x = 0; x < *N; ++x){
        std::cin >> arr[x];
    }

    return;
}

void output_ex(int arr[], int N, int count){
    for (int x = 0; x < N; ++x){
        if (x > 0){
            std::cout << " ";
        }
        std::cout << arr[x];
    }
        std::cout << std::endl;
        std::cout << count << std::endl;

}


