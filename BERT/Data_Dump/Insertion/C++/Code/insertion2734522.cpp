#include <iostream>
int main()
{
    int a, n[100];
    std::cin >> a;
    for (int i = 0; i < a; i++)
        std::cin >> n[i];

    for (int i = 0; i < a; i++)
    {
        int v = n[i], j = i - 1;
        while (j >= 0 && n[j] > v)
            n[j + 1] = n[j--];
        n[j+1] = v;
        for (int i = 0; i < a; i++)
            std::cout << n[i] << (i<a - 1 ? " " : "\n");
    }
}

