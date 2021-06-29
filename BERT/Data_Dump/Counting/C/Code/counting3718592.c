#include <stdio.h>
#define MAX_LENGTH 2000002
#define MAX_NUM 10001
int Aoriginal[MAX_LENGTH]={0};
int Binsert[MAX_LENGTH]={0};
int Ccount[MAX_NUM]={0};
void CountingSort(int A[MAX_LENGTH], int B[MAX_LENGTH], int C[MAX_NUM], int n)
{
    for(int i=1;i<n+1;i++){Ccount[Aoriginal[i]]+=1;}
    for(int j=1;j<MAX_NUM+1;j++){Ccount[j]+=Ccount[j-1];}
    for(int i=n;i>0;i--)
    {
        Binsert[Ccount[Aoriginal[i]]]=Aoriginal[i];
        Ccount[Aoriginal[i]]-=1;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<n+1;i++){scanf("%d ", &Aoriginal[i]);}
    CountingSort(Aoriginal, Binsert, Ccount, n);
    for(int i=1;i<n+1;i++)
    {
        if(i!=n){printf("%d ", Binsert[i]);}
        else{printf("%d\n", Binsert[i]);}
    }
    return 0;
}

