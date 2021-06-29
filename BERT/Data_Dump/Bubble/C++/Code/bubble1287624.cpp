#include <iostream>
using namespace std;

int bubbleSort(int *array, int N) {
    int sortCount=0;
    bool flag = 1;
    while (flag) {
        flag = 0;
        for (int i=N-1; i>0; i--) {
            if (array[i] < array[i-1]) {
                int tmp = array[i];
                array[i] = array[i-1];
                array[i-1] = tmp;
                flag = 1;
                sortCount++;
            }
        }
    }
    
    /*
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            if (array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                sortCount++;
            }
        }
    }
     */
    return sortCount;
}

int main(int argc, const char * argv[]) {
    int N, array[100], sortCount=0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> array[i];
    }
    sortCount = bubbleSort(array, N);
    for (int i=0; i<N; i++) {
        cout << array[i];
        if (i == N-1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    cout << sortCount << endl;
    
    return 0;
}
