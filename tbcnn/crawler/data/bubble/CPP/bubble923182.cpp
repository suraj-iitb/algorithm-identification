// BubbleSort
#include<iostream>
using namespace std;

template<class T>
int bubbleSort(T* array, int size)
{
        int nSwap=0;
        for(int i=size; i>0; i--){
                for(int j=0; j<i-1; j++){
                        if( array[j] > array[j+1] ){
                                int tmp = array[j+1];
                                array[j+1] = array[j];
                                array[j] = tmp;
                                nSwap++;
                        }
                }
        }
        return nSwap;
}

int main()
{
        int n;
        cin >> n;
        int array[n];
        for(int i=0; i<n; i++){
                cin >> array[i];
        }
        int s;
        s = bubbleSort(array, n);

        cout << array[0];
        for(int i=1; i<n; i++){
                cout << " " << array[i];
        }
        cout << endl << s << endl;
        return 0;
}
