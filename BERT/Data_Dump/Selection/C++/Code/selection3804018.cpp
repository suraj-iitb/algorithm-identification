#include <iostream>
#include <algorithm>

using namespace std;
int selectionsort(int a[],int n){
    int count =0;
    for(int i=0; i<n;i++){
        int min =i;
        
        for (int j=i;j<n;j++){
            if (a[j]<a[min]){
                min=j;
            }
        }
        int amin=a[min];
            a[min]=a[i];
            a[i]=amin;
           if(i!=min) count+=1;
    }
    return count;
}

int result (int a[],int n,int count){
    for (int i=0;i<n-1;i++){
        cout << a[i] <<" ";
    }
    cout << a[n-1] << endl;
    cout << count <<endl;
    return 0;
}




int main() {
    int a[103],n,count;
    cin >>n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    count =selectionsort(a,n);
    result (a,n,count);
    return 0;
}
