#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int bubbleSort(int A[],int n)
{
    int ret = 0;
    bool flg = true;
    int i = 0;
    while(flg){
        flg = false;
        for(int j = n-1;j >= i+1;j--){
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                ret ++;
                flg = true;
            }
        }
        i++;
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
    int ret = bubbleSort(A,n);
    for(int i=0;i<n;i++){
        if(i>0)
            cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << ret << endl;
}

