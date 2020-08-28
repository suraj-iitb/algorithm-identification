#include <bits/stdc++.h>  

using namespace std;

int main(int argc, char *argv[]){
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
    // string f1 = "Results/bubble/tau";
    // string f2 = f1.append(string(argv[1]));
    // myfile.open (f2, ios::app);
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    // myfile << fixed  << time_taken << setprecision(5) << endl;
    // myfile.close();

    // cout<<"The sorted array is:"<<endl;
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<endl;

} 