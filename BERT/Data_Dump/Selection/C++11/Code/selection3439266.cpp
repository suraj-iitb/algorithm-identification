//ALDS1_2_B Sort I - Section Sort
#include <iostream>
using namespace std;

void swap(int& n1, int& n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void printArray(int* a, int n)
{
    for(int i=0; i<n; i++ ) {
        cout << *(a+i);
        if(i<n-1) cout << " ";
    }
    cout << endl;
}

int main()
{
    int l;
    int a[100];
    cin >> l;
    for(int i=0; i<l; i++) {
        cin >> a[i];
    }

    int count = 0;
    int mini;    
    for(int i = 0; i < l; i++) {
        mini = i;
        for(int j = i; j < l; j++) {
            if (a[j] < a[mini]) {
                mini = j;
                
            }
        }
        if (a[i] != a[mini]) {
            swap(a[i],a[mini]);
            count++;
        }
    
    }
    printArray(a,l);
    cout << count << endl;
}
