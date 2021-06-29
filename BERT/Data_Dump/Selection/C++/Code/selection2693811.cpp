#include <iostream>
using namespace std;
int num, mini;
int count = 0;

int main(void) {
    cin >> num;
    int array[num] = {};
    for (int i = 0; i < num; i++) {
        cin >> array[i];
    }
    for( int i = 0; i < num; i++) {
        mini = i;
        for(int j = i; j < num; j++) {
            if( array[j] < array[mini]) {
                mini = j;
            }
        }
        if(mini != i) {
            int temp = array[i];
            array[i] = array[mini];
            array[mini] = temp;
            count++;
        }
    }

    for(int i = 0; i < num; i++) {
        if(i != num - 1) {
            cout << array[i] << " ";
        } else {
            cout << array[i] << endl;
        }
    }
    cout << count << endl;

    return 0;
}
