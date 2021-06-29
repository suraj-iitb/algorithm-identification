#include <stdio.h>
#define MAX1 100000
#define MAX 500000
#define INFTY 1000000001

typedef struct pp{
    char mark;
    int num;
}list;

void quicksort(list *,int,int);
int partition(list *,int,int);
void merge(list *,int ,int ,int );
void mergeSort(list *,int ,int );
void swap(list *,int,int);

int main()
{
    int a,flag=0;
    int i;
    list A[MAX1],B[MAX1];

    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%s%d",&A[i].mark,&A[i].num);
        B[i]=A[i];
    }

    quicksort(A,0,a-1);
    mergeSort(B,0,a);

    for(i=0;i<a;i++)
    {
      if(A[i].mark==B[i].mark){ }
      else { flag=1; break; } 
    }

    if(flag==1) printf("Not stable\n");
    else printf("Stable\n");

    for(i=0;i<a;i++)
    {
    printf("%s %d\n",&A[i].mark,A[i].num);
    }

    return 0;
}

void quicksort(list *A,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

int partition(list *A,int p,int r)
{
    list x,temp;
    int i,j;

    x=A[r];
    i=p-1; //i=-1
    for(j=p;j<=r-1;j++) //j=0
    {
        if(A[j].num<=x.num)
        {
            i=i+1;
            swap(A,i,j); //A[i]とA[j]を交換
        }
    }
    swap(A,i+1,r); //A[i+1]とA[r]を交換
    return i+1; //pivotの添え字を返す
}

void swap(list *A,int i,int j)
{
    list temp;
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
    return;
}

void mergeSort(list *array,int left,int right)
{
    int mid;

    if(left+1<right)
    {
        mid = (left+right)/2;
        mergeSort(array,left,mid);
        mergeSort(array,mid,right);
        merge(array,left,mid,right);
    }
    return;
}

void merge(list *array,int left,int mid,int right)
{
    int n1,n2;
    int i,j,k;
    static list L[MAX/2+2],R[MAX/2+2];   //LとRの配列を保存しておくためにstatic変数を使う

    n1 = mid-left;
    n2 = right-mid;

    for(i=0;i<n1;i++) L[i] = array[left+i];
    for(i=0;i<n2;i++) R[i] = array[mid+i];
    i=j=0;

    L[n1].num=R[n2].num=INFTY;          //最大の値を入れる事によって必ず配列に入れた値を比較しマージできる
    for(k=left;k<right;k++)
    {
        if(L[i].num<=R[j].num)
        {
            array[k]=L[i]; i++;
        }
        else
        {
            array[k]=R[j]; j++;
        }
    }
    return;
}
