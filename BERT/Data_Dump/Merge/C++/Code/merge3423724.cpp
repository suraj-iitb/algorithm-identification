#include<cstdio>
int num=0;
int n;
void merge(int A[],int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;
    int M[500010],N[500010];
    for(int i=0;i<n1;i++)
    M[i]=A[left+i];
    for(int i=0;i<n2;i++)
    N[i]=A[mid+i];
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int i;
    for(i=0; i<right-left;i++)
    if(M[flag1]<=N[flag2])
    {
        A[left+i]=M[flag1++];
        num++;
    //    printf("cs1");
    if(flag1==n1) {flag3=1;break;}
    }
    else{
    A[left+i]=N[flag2++];
    num++;
    if(flag2==n2) {flag3=2;break;}
    //printf("cs2");
    }
    for(int k=left+i+1;k<right;k++)
    if(flag3==1)
    {
        A[k]=N[flag2++];
        num++;
    }
    else
    {
        A[k]=M[flag1++];
        num++;
    }
/*        for(int i=0;i<n;i++)
    {
        if(i!=0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");*/
}
void mergeSort(int A[],int left,int right)
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
  //  int n;
    scanf("%d",&n);
    int A[500010];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    //TODO
   // printf("bbb");
    mergeSort(A,0,n);
   // printf("aaa");
    for(int i=0;i<n;i++)
    {
        if(i!=0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",num);
    return 0;
}

