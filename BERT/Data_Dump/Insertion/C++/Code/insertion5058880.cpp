
#include<string>
#include<vector>
#include<iostream>

using namespace std;

void printall(vector<int> &A, int n)
{
    for(int i=0;i<n;i++)
    {
        cout << A[i];
        if(i!=n-1)
            cout << " ";
    }
    cout << endl;
}
void insertionSort(vector<int> &A, int n)
{
    int v;
    int j;
    for(int i=1;i<n;i++)
    {
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=v;
        printall(A,n);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    printall(v,n);
    insertionSort(v,n);

}
