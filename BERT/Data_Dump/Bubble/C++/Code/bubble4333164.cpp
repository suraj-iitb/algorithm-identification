#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

void BubbleSort(vector<int> A){
    int count = 0;
    int flag = 1;
    int j = 1;
    while(flag==1&&j<=A.size()-1){
        flag = 0;
        for(int i=0;i<A.size()-j;i++){
            if(A[i]>A[i+1]){
                swap(A[i], A[i+1]);
                flag = 1;
                count++;
            }
        }
        j++;
    }
    for(int i=0;i<A.size();i++){
        if(i==A.size()-1){
            cout << A[i] << endl;
            cout << count << endl;
            break;
        }
        cout << A[i] << " ";
    }

}

int main(){
    int n;
    cin >> n;
    nums.resize(n);
    
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    BubbleSort(nums);

}
