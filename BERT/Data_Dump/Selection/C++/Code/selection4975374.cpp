#include <iostream>

int selection_sort(int a[], int n)
{
    int swap = 0;
    for (int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            int cache = a[i];
            a[i] = a[min_idx];
            a[min_idx] = cache;
            swap++;
        }
    }
    return swap;
}

int main()
{
    int n;
    int a[105];
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int swap = selection_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        if (i != 0) std::cout << " " ;
        std::cout << a[i];
    }
    std::cout << std::endl;
    std::cout << swap << std::endl;
    return 0;
}
