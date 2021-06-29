#include <iostream>
#include <cstdio>
using namespace std;

static const int SENTINEL = 2000000000;
static const int MAX = 100000;
struct Card {char suit; int value; };
Card L[MAX/2+2], R[MAX/2+2];

void merge(Card A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i != n1; ++i)
    {
        L[i] = A[left+i];
    }
    for (int i = 0; i != n2; ++i)
    {
        R[i] = A[mid+i];
    }

    L[n1].value = R[n2].value = SENTINEL;

    int i = 0;
    int j = 0;

    for (int k = left; k != right; ++k)
    {
        if (L[i].value <= R[j].value)
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}

void mergeSort(Card A[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(Card A[], int p, int r)
{
    int x = A[r].value;
    int i = p - 1;

    for (int j = p; j != r; ++j)
    {
        if (A[j].value <= x)
        {
            ++i;
            swap(A[j], A[i]);
        }
    }

    swap(A[i+1], A[r]);

    return i+1;
}

void quickSort(Card A[], int left, int right)
{
    if (left < right)
    {
        int mid = partition(A, left, right);
        quickSort(A, left, mid-1);
        quickSort(A, mid+1, right);
    }
}

int main()
{
    char str[10];
    bool flat = true;
    int n, x;
    Card A[MAX], B[MAX];

    scanf("%d", &n);

    for (int i = 0; i != n; ++i)
    {
        scanf("%s %d", str, &x);
        B[i].suit = A[i].suit = str[0];
        B[i].value = A[i].value = x;
    }

    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);

    for (int i = 0; i != n; ++i)
    {
        if (A[i].suit != B[i].suit)
        {
            flat = false;
            break;
        }
    }

    if (flat)
    {
        printf("Stable\n");
    }
    else
    {
        printf("Not stable\n");
    }

    for (int i = 0; i != n; ++i)
    {
        printf("%c ", B[i].suit);
        printf("%d\n", B[i].value);
    }
    
    return 0;
}
