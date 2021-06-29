#include <iostream>
#include <cstdio>
using namespace std;

const int M = 1000000005;
const int Max = 100005;
struct Card
{
    char c;
    int n;
};
Card A[Max], S[Max];
Card a[Max/2], b[Max/2];

void Merge(Card S[], int left, int right, int mid)//归并（归并时比较排序）
{
    int n1 = mid-left, n2 = right-mid;//以mid为界限，分割为两个数组
    for(int i=0; i<n1; i++)
    {
        a[i] = S[i+left];
        //Count++;
    }
    for(int i=0; i<n2; i++)
    {
        b[i] = S[i+mid];
        //Count++;
    }
    a[n1].n = M, b[n2].n = M;//确保最后一个数较大，利于以下排序（M超出了S中元素的范围）
    int k=left, ka=0, kb=0;
    //Count++;
    while(k<right)
    {
        if(a[ka].n>b[kb].n)//升序排列
        {
            S[k++] = b[kb++];
        }
        else
        {
            S[k++] = a[ka++];
        }
        //Count++;//计数
    }
}

void MergeSort(Card S[], int left, int right)//用于分割数组，分别排序（分治）
{
    if(left+1<right)//判断是否可以分割
    {
        int mid = (left+right)/2;
        MergeSort(S, left, mid);
        MergeSort(S, mid, right);
        Merge(S, left, right, mid);//归并
    }
}

void swap(Card *x, Card *y)
{
    Card temp = *x;
    *x = *y;
    *y = temp;
}
int Partition(Card A[], int p, int r)
{
    Card x = A[r], t;
    //cout << x.n << endl;
    int i=p-1;
    for(int j=p; j<r; j++)
    {
        if(A[j].n<=x.n)
        {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
            //swap(A[i], A[j]);
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
   // swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(Card A[], int p, int r)
{
    if(p<r)
    {
        int q = Partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main()
{
    int n, flag = 1;
    char C[5];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s %d", C, &A[i].n);
        A[i].c = C[0];
        S[i].n = A[i].n;
        S[i].c = C[0];
    }
    quickSort(A, 0, n-1);
    MergeSort(S, 0, n);
    for(int i=0; i<n; i++)
    {
        if(S[i].c!=A[i].c)
        {
            flag = 0;
            break;
        }
    }
    if(flag) printf("Stable\n");
    else     printf("Not stable\n");
    for(int i=0; i<n; i++)
    {
        printf("%c %d\n", A[i].c, A[i].n);
    }
    return 0;
}

