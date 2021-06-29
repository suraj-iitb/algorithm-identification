#include<cstdio>
#define MAXNUM 20000000;
struct  Card
{
    char suit;
    int value;
};

Card A[100010],B[100010];
Card L[50005], R[50005];


int partition(Card A[], int p, int r)
{
    int i= p-1;
    Card  x = A[r];
    for(int j=p; j<r; j++)
    {
        if(A[j].value <= x.value)
        {
            i++;
            Card cur = A[i];
            A[i] = A[j];
            A[j] = cur;
        }
    }
    A[r] = A[++i];
    A[i] = x;
    return i;
}

void Quick_Sort(Card A[], int p, int r)
{
    if(p < r)
    {
       int q = partition(A,p,r);
        Quick_Sort(A,p,q-1);
        Quick_Sort(A,q+1,r);
    }
}

void Merge(Card A[], int   left, int mid, int right )
{
    int n1 = mid - left;
    int n2 = right - mid;
    //int n = right - left;
    for(int i=0; i < n1; i++)
        L[i] = A[left + i];
    for(int i=0; i < n2; i++)
        R[i] = A[mid + i];
    // Merge
    L[n1].suit = 'A';
    L[n2].suit = 'A';
    L[n1].value = MAXNUM;
    R[n2].value = MAXNUM;
    int i = 0;
    int j = 0;
    for(int k=left; k < right; k++)
    {
        if(L[i].value <= R[j].value)
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void Merge_Sort(Card A[], int left, int right)
{
    if(left + 1 < right)
    {
        int  mid = (left + right) / 2;
        Merge_Sort(A,left,mid);
        Merge_Sort(A,mid, right);
        Merge(A,left,mid,right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char s[5];
    int v;
    for(int i=0; i<n; i++)
    {
        scanf("%s %d", s, &v);
        A[i].suit = B[i].suit = s[0];
        A[i].value = B[i].value = v;
    }
    Quick_Sort(A,0,n-1);
    Merge_Sort(B,0, n);
    int flag = 1;
    for(int i=0; i<n; i++)
    {
        if(A[i].suit != B[i].suit)
        {
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("Stable\n");
    else
        printf("Not stable\n");
    
    for(int i=0; i<n; i++)
    {
        //if(i) printf(" ");
        printf("%c %d\n", A[i].suit, A[i].value);
    }
    //printf("\n");

    return 0;
}
