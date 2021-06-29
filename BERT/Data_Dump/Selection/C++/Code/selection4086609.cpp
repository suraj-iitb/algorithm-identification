#include <iostream>

int selectionSort(int A[], int N)
{
    int sortedNum = 0;

    for (int i = 0; i < N; i++)
    {
        int minj = i;

        for (int j = i; j < N; j++)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }

        if (A[i] != A[minj])
        {
            int temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            sortedNum++;
        }
    }

    return sortedNum;
}

int main()
{
    int num;
    std::cin >> num;

    int *element = new int[num];
    for (int i = 0; i < num; i++) std::cin >> element[i];

    int sortedNum = selectionSort(element, num);

    for (int i = 0; i < num; i++)
    {
        std::cout << element[i];

        if (i < num - 1) std::cout << " ";
        else             std::cout << std::endl;
    }

    std::cout << sortedNum << std::endl;
}
