#include <iostream>
#include <stdio.h>

#define MAX 100000
#define SENTINEL 2000000000

typedef struct Card
{
    char suit;
    int num;
};

Card A[MAX];
Card S[MAX];
Card L[MAX / 2 + 2];
Card R[MAX / 2 + 2];
int count = 0;

void merge(int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++)
    {
        L[i] = S[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = S[mid + i];
    }

    L[n1].num = SENTINEL;
    R[n2].num = SENTINEL;

    int i_L = 0;
    int i_R = 0;

    for (int k = left; k < right; k++)
    {
        count++;
        if (L[i_L].num <= R[i_R].num)
        {
            S[k] = L[i_L++];
        }
        else
        {
            S[k] = R[i_R++];
        }
    }
}

void mergeSort(int left, int right)
{
    int mid = (right + left) / 2;

    if (right - left > 1)
    {
        mergeSort(mid, right);
        mergeSort(left, mid);
        merge(left, mid, right);
    }
}

int partition(int p, int n)
{
    int i = p-1, j = 0;
    int x = A[n].num;
    Card temp;
    for (j = p; j < n; j++)
    {
        if (A[j].num <= x)
        {
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    temp = A[i+1];
    A[i+1] = A[n];
    A[n] = temp;
    i++;
    return i;
}

void quickSort(int p, int n)
{
    int i;
    if (p < n)
    {
        i = partition(p, n);
        quickSort(p, i-1);
        quickSort(i+1, n);
    }
    else
    {
        return;
    }
}

int main()
{
    int n;
    char c[10];
    int value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", c, 10);
        scanf("%d", &value);
        A[i].suit = c[0];
        A[i].num = value;
        S[i].suit = c[0];
        S[i].num = value;
    }
    
    quickSort(0, n-1);
    mergeSort(0, n);

    bool stable = true;
    for (int i = 0; i < n; i++)
    {
        if (A[i].suit != S[i].suit) { stable = false; }
    }
    
    if (stable == false) { printf("Not stable\n"); }
    else { printf("Stable\n"); }
    for (int i = 0; i < n; i++)
    {
        printf("%c %d\n", A[i].suit, A[i].num);
    }
}
