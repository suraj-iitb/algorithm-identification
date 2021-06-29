#include <stdio.h>

typedef long long llong;

const int MAX = 100000;
const int SENTINEL = 2000000000;

struct  Card
{
    char suit;
    int value;
};
Card L[MAX/2+2], R[MAX / 2+2 ];

void m_sort(Card A[],  const int& left, const int& mid, const int& right)
{
   
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++)
    {
        L[i].suit = A[left + i].suit;
        L[i].value = A[left + i].value;
    }

    for (int i = 0; i < n2; i++)
    {
        R[i].suit = A[mid + i].suit;
        R[i].value = A[mid + i].value;
    }
    L[n1].value = SENTINEL;
    R[n2].value = SENTINEL;
    int i=0, j = 0;
    for (int k=left;k<right;k++)
    {
        if (L[i].value<=R[j].value)
        {
            A[k].value = L[i].value;
            A[k].suit = L[i].suit;
            i++;
        }
        else
        {
            A[k].value = R[j].value;
            A[k].suit = R[j].suit;
            j++;
        }
    }
}
void m_sort(Card A[], const int& left,  const int& right)
{
    if (left+1<right)
    {
        int mid = (left + right) / 2;
        m_sort(A ,left, mid);
        m_sort(A,  mid,right);
        m_sort(A,  left, mid, right);
    }
}

int partition(Card A[], int p,int r)
{
    int x = A[r].value;
    char v = A[r].suit;
    int i = p - 1;
    Card tmp;
    for (int j = p; j<= r-1 ; j++)
    {
        if (A[j].value<=x)
        {
            i++;
            tmp.value = A[i].value;
            tmp.suit = A[i].suit;
            A[i].value = A[j].value;
            A[i].suit = A[j].suit;
            A[j].value = tmp.value;
            A[j].suit = tmp.suit;
        }
    }
    tmp.value = A[i + 1].value;
    tmp.suit = A[i + 1].suit;
    A[i + 1] = A[r];
    A[i + 1].suit = A[r].suit;
    A[r].value = tmp.value;
    A[r].suit = tmp.suit;
    return i + 1;
}
void q_sort(Card A[], int p,int r)
{
    if (p<r)
    {
        int q = partition(A,p, r);
        q_sort(A,p,q-1);
        q_sort(A,q + 1, r);
    }
}
bool isStable(Card  m_A[], Card  q_B[],int n)
{
    for(int i=0;i<n;i++)
    {
        if (m_A[i].suit != q_B[i].suit)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n,v;
    struct Card  A[MAX], B[MAX];
    char S[10];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", S, &v);
        A[i].value = B[i].value = v;
        A[i].suit = B[i].suit = S[0];
    }
    m_sort(A,  0, n);
    q_sort(B, 0, n-1);
    
    if(isStable(A,B,n))
    {
        printf("Stable\n");
    }
    else
    {
        printf("Not stable\n");
    }
    for (int i = 0; i < n; i++)
        printf("%c %d\n", B[i].suit, B[i].value);

    return 0;
}

