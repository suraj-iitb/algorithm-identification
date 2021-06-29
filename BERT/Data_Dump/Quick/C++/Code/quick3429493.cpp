#include<cstdio>
struct Card{
    char color;
    int num;
};
int partition(Card A[],int p,int r)
{
    int i=p-1;
    int j=p;
    int x=A[r].num;
    for(;j<r;j++)
    {
        if(A[j].num<=x)
        {
            i++;
            Card t;
            t=A[j];
            A[j]=A[i];
            A[i]=t;
        }
    }
    Card t;
    t=A[i+1];
    A[i+1]=A[r];
    A[r]=t;
    return i+1;
}
void quickSort(Card A[],int p,int r)
{
    if(p<r)
    {
        int q;
        q=partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}
void merge(Card A[],int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;
    Card M[100000],N[100000];
    for(int i=0;i<n1;i++)
    M[i]=A[left+i];
    for(int i=0;i<n2;i++)
    N[i]=A[mid+i];
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int i;
    for(i=0; i<right-left;i++)
    if(M[flag1].num<=N[flag2].num)
    {
        A[left+i]=M[flag1++];

    //    printf("cs1");
    if(flag1==n1) {flag3=1;break;}
    }
    else{
    A[left+i]=N[flag2++];

    if(flag2==n2) {flag3=2;break;}
    //printf("cs2");
    }
    for(int k=left+i+1;k<right;k++)
    if(flag3==1)
    {
        A[k]=N[flag2++];
        }
    else
    {
        A[k]=M[flag1++];
        }
/*        for(int i=0;i<n;i++)
    {
        if(i!=0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");*/
}
void mergeSort(Card A[],int left,int right)
{
    if(left<right-1)
    {
      //  printf("sss\n");
        int mid;
        mid=(left+right)/2;
        mergeSort(A,left,mid);
        //printf("mmm\n");
        mergeSort(A,mid,right);
        //printf("kkk\n");
        merge(A,left,mid,right);
        //printf("cs3");
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    char S[10];
    Card cards[100000];
    for(int i=0;i<n;i++)
    {
        scanf("%s%d",S,&cards[i].num);
        cards[i].color=S[0];
    }
    Card cards2[100000];
    for(int i=0;i<n;i++)
    {
    cards2[i]=cards[i];
    }
    quickSort(cards,0,n-1);
    mergeSort(cards2,0,n);
    int i;
    for(i=0;i<n;i++)
    if(cards2[i].color!=cards[i].color)
    {
    printf("Not stable\n");
    break;
    }
    if(i==n)
    printf("Stable\n");

    for(int i=0;i<n;i++)
    {
        printf("%c %d\n",cards[i].color,cards[i].num);
    }
    return 0;
}

