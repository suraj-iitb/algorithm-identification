#include <iostream>
void print_array(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<a[n-1]<<std::endl;
}

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        print_array(a, n);
        int cache = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > cache)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = cache;
    }
    print_array(a, n);
}

int main(void)
{
    int n;
    int a[200];
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    insertion_sort(a, n);
    return 0;
}
