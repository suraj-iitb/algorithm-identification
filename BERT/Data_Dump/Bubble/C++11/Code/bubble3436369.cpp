//ALDS1_2_A Sort I - Bubble Sort
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
    for(int i = 0; i < l-1; i++) {
        for(int j = (l-1); j >= (i+1); j--) {
            if (a[j] < a[j-1]) {
                swap(a[j],a[j-1]);
                count++;
            }
            //cout << "i:" << i << " j:" << j << " count:" << count << " Array: ";
            //printArray(a,l); 
        }        
    }
    printArray(a,l);
    cout << count << endl;
}
