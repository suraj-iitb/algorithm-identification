// 選択ソート
#include<iostream>
using namespace std;

template<class T>
int selectionSort(T* array, int size)
{
        int s=0;
        T min;
        for(int i=0; i<size-1; i++){
                min = i;
                for(int j=i+1; j<size; j++){
                        if( array[j] < array[min] ){ min = j; }
                }
                T tmp;
                if( min != i){
                        tmp = array[min];
                        array[min] = array[i];
                        array[i] = tmp;
                        s++;
                }
        }
        return s;
}

int main()
{
        int n, s;
        cin >> n;
        int array[n];
        for(int i=0; i<n; i++){ cin >> array[i]; }

        s = selectionSort(array, n);

        cout << array[0];
        for(int i=1; i<n; i++){
                cout << " " << array[i];
        }
        cout << endl << s << endl;
        return 0;
}
        
