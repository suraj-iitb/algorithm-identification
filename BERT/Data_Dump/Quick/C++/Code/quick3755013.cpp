#include <iostream>

const int MAX = 100000;
const int SENTINEL = 1000000001;

typedef struct
{
    char c;
    int value;
} Card;

void swap(Card &x, Card &y)
{
    Card temp = x;
    x = y;
    y = temp;
}

int partition(Card *array, int p, int r)
{
    int i = p, x = array[r].value;
    for (int j = p; j < r; j++)
    {
        if (array[j].value <= x)
        {
            swap(array[i++], array[j]);
        }
    }
    swap(array[i], array[r]);
    return i;
}

void quickSort(Card *array, int p, int r)
{
    if (r < p + 1)
        return;
    int m = partition(array, p, r-1);
    quickSort(array, p, m);
    quickSort(array, m+1, r);
}

void merge(Card *array, int left, int mid, int right)
{
    int n1 = mid - left, n2 = right - mid, l = 0, r = 0;
    Card L[n1 + 1], R[n2 + 1];
    L[n1].value = R[n2].value = SENTINEL;
    for (int i = left; i < mid; i++)
        L[i - left] = array[i];
    for (int i = mid; i < right; i++)
        R[i - mid] = array[i];
    for (int i = left; i < right; i++)
    {
        if (L[l].value > R[r].value)
            array[i] = R[r++];
        else
            array[i] = L[l++];
    }
}

void mergeSort(Card *array, int left, int right)
{
    if (left + 2 > right)
        return;
    int mid = (left + right) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid, right);
    merge(array, left, mid, right);
}

int main()
{
    int n;
    bool stable = true;
    Card array1[MAX], array2[MAX];
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> array1[i].c >> array1[i].value;
        array2[i].c = array1[i].c;
        array2[i].value = array1[i].value;
    }
    quickSort(array1, 0, n);
    mergeSort(array2, 0, n);
    for (int i = 0; i < n; i++)
    {
        if (array1[i].c != array2[i].c)
        {
            stable = false;
            break;
        }
    }
    if (stable)
        std::cout << "Stable" << std::endl;
    else
        std::cout << "Not stable" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << array1[i].c << " " << array1[i].value << std::endl;
    }
    /*
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << array2[i].c << " " << array2[i].value << std::endl;
    }
    */
}

