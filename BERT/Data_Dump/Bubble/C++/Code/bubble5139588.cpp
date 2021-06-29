
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(vector<int> &A, int n)
{
    int flg = 1;
    int cnt=0;
    while(flg)
    {
        flg=0;
        for(int j=n-1;j>=1; j--)
        {
            if(A[j]<A[j-1])
            {
                int tmp;
                swap(A[j-1],A[j]);
                flg=1;
                cnt++;
            }
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

    res_num=bubbleSort(A,n);

    for(int j=0;j<n;j++)
    {
        cout << A[j];
        if(j!=n-1)
            cout << " "  ;  
    }
    cout << endl;
    cout << res_num << endl;

}
