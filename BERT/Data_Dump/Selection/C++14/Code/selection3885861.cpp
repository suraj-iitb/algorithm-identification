#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int selectionSort(int A[],int n)
{
    int ret = 0;
    for(int i=0;i<n;i++){
        int mini = i;
        for(int j = i+1; j<n;j++){
            if(A[j] < A[mini])
                mini = j;
        }
        if(mini != i){
            swap(A[i],A[mini]);
            ret ++;
        }
    }
    return ret;
}


int main()
{
    int n;
    cin >> n;
    int A[100];
    for(int i=0;i<n;i++)
        cin >> A[i];
    int ret = selectionSort(A,n);
    for(int i=0;i<n;i++){
        if(i>0)
            cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << ret << endl;
}
