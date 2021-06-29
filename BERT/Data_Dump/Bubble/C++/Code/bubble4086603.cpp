#include <iostream>

int bubbleSort(int A[], int N)
{
    int sortedNum = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;

        for (int j = N-1; j > 0; j--)
        {
            if (A[j] < A[j-1])
            {
                int temp = A[j];
                A[j]   = A[j-1];
                A[j-1] = temp;
                sortedNum++;
                flag = true;
            }
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

    int sortedNum = bubbleSort(element, num);

    for (int i = 0; i < num; i++)
    {
        std::cout << element[i];

        if (i < num - 1) std::cout << " ";
        else             std::cout << std::endl;
    }

    std::cout << sortedNum << std::endl;
}
