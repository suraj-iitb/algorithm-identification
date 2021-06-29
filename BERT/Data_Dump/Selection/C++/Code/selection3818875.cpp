#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void selection_sort(int nums[100], int n){
    int min, count, min_index;
    count = 0;
    for(int i=0; i<n; i++){
        min = nums[i];
        min_index = i;
        for(int j=i; j<n; j++){
            if(min > nums[j]){
                min = nums[j];
                min_index = j;
            }
        }
        if(min_index != i){
            nums[min_index] = nums[i];
            nums[i] = min;
            count++;
        }
    }
    for(int i=0; i<n; i++){
        cout << nums[i];
        if(i<n-1){
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
}

int main()
{
    int N;
    int num[100];
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num[i];
    }
    selection_sort(num, N);
    return 0;
}
