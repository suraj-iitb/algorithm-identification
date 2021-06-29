#include <iostream>

template <typename T>
void print_array(const T a[], int length)
{
    for (int i = 0; i < length; i++){
        if (i > 0)
            std::cout << " "; 
        std::cout << a[i];
    }
}

template <typename T>
void insertion_sort(T a[], int length)
{
    for (int i = 1; i < length; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j + 1] < a[j]) {
                T temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            } else {
                break;
            }
        }
        print_array(a, length);
            std::cout << std::endl;
    }
}

int main() {
//    int a[6] = {5,2,4,6,1,3};
    int n = 0;
    std::cin >> n;
    int a[100] = {0};
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    print_array(a, n);
    std::cout << std::endl;
    insertion_sort(a, n);
    return 0;
}
