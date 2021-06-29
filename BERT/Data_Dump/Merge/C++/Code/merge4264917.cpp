#include <iostream>

using namespace std;
#define MAX 500000
#define SEN 2000000000

int L[MAX/2+2],R[MAX/2+2];
int cnt = 0;
void merges(int A[],int leftt,int midd,int rightt)
{
    int n1 = midd - leftt;
    int n2 = rightt - midd;
    int i,j,k;
    for( i = 0;i < n1;i++)L[i] = A[leftt+i];
    for(i = 0;i < n2;i++)R[i] = A[midd+i];
    L[n1] = SEN;
    R[n2] = SEN;
    i = 0,j = 0;
    for(k = leftt;k < rightt;k++)
    {
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
}
void mergeSort(int A[],int leftt,int rightt){
if(leftt < rightt -1){
    int midd = (leftt + rightt)/2;
    mergeSort(A,leftt,midd);
    mergeSort(A,midd,rightt);
    merges(A,leftt,midd,rightt);
}
}
int main()
{
    int n,A[500000];
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> A[i];
    }
    mergeSort(A,0,n);
    for(int i = 0;i < n;i++)
    {
        if(i) cout <<" ";
        cout << A[i] ;
    }
    cout <<endl<< cnt<<endl ;
}

