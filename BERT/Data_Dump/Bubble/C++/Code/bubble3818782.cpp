#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void bubble_sort(int nums[100], int n){
    int count, temp=0;
    count = 0;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>i; j--){
            if(nums[j-1] > nums[j]){
                count++;
                temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
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
    bubble_sort(num, N);
    return 0;
}
