#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void insertionSort(vector<int> array,int n)
{
    for(int i=1;i<n;i++){
        for(int k=0;k<n-1;k++)
            cout << array[k] << ' ';
        cout << array[n-1] << endl;
        int value = array[i];
        int j = i -1;
        while(j >= 0 && array[j] > value){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = value;
    }
    for(int k=0;k<n-1;k++)
        cout << array[k] << ' ';
    cout << array[n-1] << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin >> vec[i];
    insertionSort(vec,n);
}

