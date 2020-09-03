#include <bits/stdc++.h>  

using namespace std;

int main(){
     int i,j,n,temp;
    // cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    // cout<<"\nEnter the elements\n";
 
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    // clock_t start, end; 
    // start = clock(); 

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // end = clock();

    // ofstream myfile;
    // myfile.open ("time_bubble.txt", ios::app);
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    // myfile << n << " " << fixed  << time_taken << setprecision(5) << endl;
    // myfile.close();

    // cout<<"The sorted array is:"<<endl;
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<endl;

}