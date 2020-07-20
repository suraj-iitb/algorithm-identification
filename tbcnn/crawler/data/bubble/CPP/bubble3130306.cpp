#include<iostream>

using namespace std;

int BubbleSort(int ary[],int n){
    int count = 0;
    bool flag = true;
    while(flag){
        flag=false;
        for(int i=n-1;i>0;i--){
            if(ary[i] < ary[i-1]){
                int temp=ary[i-1];
                ary[i-1] = ary[i];
                ary[i] = temp;
                flag=true;
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;

    int array[n];
    for(int i=0;i<n;i++){
        cin >> array[i];
    }

    int count;
    count = BubbleSort(array,n);
    for(int i=0;i<n-1;i++){
        cout << array[i] << " ";
    }
    cout << array[n-1] << endl;
    cout << count << endl;
    return 0;
}
