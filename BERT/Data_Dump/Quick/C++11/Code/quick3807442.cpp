#include <iostream>
#include <cstdio>

using namespace std;

struct Card {
    char suit;
    int value;
};

#define INF 1000000000

void merge(Card card[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    Card L[n1 + 1];
    Card R[n2 + 1];
    for (int i = 0; i < n1; i++)
        L[i] = card[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = card[mid + i];
    L[n1].value = INF;
    R[n2].value = INF;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i].value <= R[j].value)
        {
            card[k] = L[i];
            i++;
        } else
        {
            card[k] = R[j];
            j++;
        }
    }
}

void merge_sort(Card card[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        merge_sort(card, left, mid);
        merge_sort(card, mid, right);
        merge(card, left, mid, right);
    }
}


int partition(Card card[], int p, int r)
{
    int x = card[r].value;
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (card[j].value <= x)
        {
            i++;
            swap(card[i], card[j]);
        }
    }
    swap(card[i + 1], card[r]);
    return i + 1;
}

void quick_sort(Card card[], int p, int r)
{
    if (p < r)
    {
        int q = partition(card, p, r);
        quick_sort(card, p, q - 1);
        quick_sort(card, q + 1, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Card card[n];
    Card card_cmp[n];
    char S[16];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", S);
        card[i].suit = card_cmp[i].suit = S[0];
        scanf("%d", &(card[i].value));
        card_cmp[i].value = card[i].value;
    }
    quick_sort(card, 0, n - 1);
    merge_sort(card_cmp, 0, n);

    bool stable = true;

    for (int i = 0; i < n; i++)
    {
        if (card[i].suit != card_cmp[i].suit)
        {
            stable = false;
            break;
        }
    }
    if (stable)
        printf("Stable\n");
    else
        printf("Not stable\n");
    for(int i = 0; i < n; i++)
        printf("%c %d\n", card[i].suit, card[i].value);
}
