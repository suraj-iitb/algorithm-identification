#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000007

int counter = 0;

void merge(vector<int> &array, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> array1;
    vector<int> array2;
    for (int i = 0; i < n1; i++)
    {
        array1.push_back(array[left + i]);
    }
    array1.push_back(MAX);
    for (int i = 0; i < n2; i++)
    {
        array2.push_back(array[mid + i]);
    }
    array2.push_back(MAX);

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n1 + n2; i++)
    {
        if (array1[c1] < array2[c2])
        {
            array[left + i] = array1[c1];
            c1++;
        }
        else
        {
            array[left + i] = array2[c2];
            c2++;
        }
        counter++;
    }
}

void mergeSort(vector<int> &array, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid, right);
        merge(array, left, mid, right);
    }
}

int main()
{
    int num;
    cin >> num;
    vector<int> array;
    for (int i = 0; i < num; i++)
    {
        int v;
        cin >> v;
        array.push_back(v);
    }

    mergeSort(array, 0, num);

    for (vector<int>::iterator itr = array.begin(); itr != array.end(); ++itr)
    {
        if (itr != array.begin())
            cout << " ";
        cout << *itr;
    }
    cout << endl;
    cout << counter << endl;
}

