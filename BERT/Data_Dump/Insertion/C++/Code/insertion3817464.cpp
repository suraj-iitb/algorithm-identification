#include <iostream>
#include <list>
#include <string>
#include <iomanip>
using namespace std;

void insertion_sort(int nums[100], int n){
    int p;
    for(int i=1; i<n; i++){
        p = nums[i];
        for(int j=0; j<i; j++){
            if(p<nums[j]){
                for(int k=i-1; k>=j; k--){
                    nums[k+1]=nums[k];
                }
                nums[j] = p;
                break;
            }
        }
        for(int i=0; i<n; i++){
            cout << nums[i];
            if(i<n-1){
                cout << " ";
            }else{
                cout << endl;
            }
        }
    }
}
int main()
{
    int N;
    int nums[100];
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    for(int i=0; i<N; i++){
        cout << nums[i];
        if(i<N-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    insertion_sort(nums, N);
    return 0;
}
