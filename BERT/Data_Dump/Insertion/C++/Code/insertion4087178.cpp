#include <iostream>

void insertionSort(int A[], int N)
{
    for (int k = 0; k < N; k++)
    {
        std::cout << A[k];

        if (k < N-1) std::cout << " ";
        else         std::cout << std::endl;
    }
    
    for (int i = 1; i < N; i++)
    {
        int v = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        for (int k = 0; k < N; k++)
        {
            std::cout << A[k];

            if (k < N-1) std::cout << " ";
            else         std::cout << std::endl;
        }
    }
}

int main()
{
    int num;
    std::cin >> num;

    int *element = new int[num];

    for (int i = 0; i < num; i++) std::cin >> element[i];

    insertionSort(element, num);
}
