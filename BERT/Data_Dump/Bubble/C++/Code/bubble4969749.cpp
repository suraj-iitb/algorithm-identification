//
// Created by nfspp on 2020/11/5.
//

#include <iostream>
int bubble_sort(int a[], int n)
{
    int inverse = 0;
    int start = 0;
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = n-1; i > start; i--)
        {
            if (a[i] < a[i-1])
            {
                flag = 1;
                int cache = a[i];
                a[i] = a[i-1];
                a[i-1] = cache;
                inverse++;
            }
            
        }
        start++;
    }
    return inverse;
}

int main()
{
    int n;
    int a[105];
    std::cin>>n;
    for (int i = 0; i< n; i++)
    {
        std::cin >> a[i];
    }
    int inverse = bubble_sort(a, n);
    for (int i = 0; i < n-1; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << a[n-1] << std::endl;
    std::cout << inverse << std::endl;
    return 0;
}
