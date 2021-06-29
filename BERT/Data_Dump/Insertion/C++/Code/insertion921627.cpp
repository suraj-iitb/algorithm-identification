#include<iostream>
using namespace std;

void printArray(int* array, int size)
{
        int n;
        for(int i=1; i<size; i++){
                cout << array[i] << " ";
        }
        
        cout << array[size] << endl;
}

template<class T>        
void insertSort(T* array, int size)
{
        int tmp, j;
        for(int i=1; i<=size; i++){
                tmp = array[i];
                array[0] = tmp; // array[0] is used for sentinel
                for(j=i-1; array[j] > tmp; j--){
                        array[j+1] = array[j];
                }
                array[j+1] = tmp;
                printArray(array, size);
        }
}
        

int main()
{
        int n;
        cin >> n;

        int elem[n+1]; // n[0]は番兵として使う
        for(int i=1; i<=n; i++){
                cin >> elem[i];
        }

        insertSort(elem, n);

        return 0;
}
        
