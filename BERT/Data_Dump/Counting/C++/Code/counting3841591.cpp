#include <iostream>
#include <vector>
using namespace std;
#define VMAX 10000

void countingSort(vector<int>& input, vector<int>& output, int num) {
    vector<int> counting(VMAX+1, 0);
    for(vector<int>::iterator itr = input.begin(); itr != input.end(); ++itr) {
        counting[*itr] += 1;
    }
    
    for(int i=1; i<=VMAX; i++) {
        counting[i] = counting[i] + counting[i-1];
    }
    for(int i=num-1; i>=0; i--) {
        output[counting[input[i]] - 1] = input[i];
        counting[input[i]] -= 1;
    }
}

int main() {
    int num;
    cin >> num;
    vector<int> array(num, 0);
    vector<int> output(num, 0);
    for(int i=0; i<num;i++) {
        int number;
        cin >> number;
        array[i] = number;
    }

    countingSort(array, output, num);

    for(int i=0; i<num; i++) {
        if(i != 0) cout << " ";
        cout << output[i];
    }
    cout << endl; 
}
