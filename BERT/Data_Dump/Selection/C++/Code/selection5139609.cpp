
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int selectionSort(vector<int> &A, int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int minj=i;
        for(int j=i;j<n;j++)
        {
            if(A[j]<A[minj])
            {
                minj=j;
            }
        }
        if(i!=minj)
        {
            swap(A[i],A[minj]);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    int res_num;
    vector<int> A;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    res_num=selectionSort(A,n);

    for(int j=0;j<n;j++)
    {
        cout << A[j];
        if(j!=n-1)
            cout << " "  ;  
    }
    cout << endl;
    cout << res_num << endl;

}
