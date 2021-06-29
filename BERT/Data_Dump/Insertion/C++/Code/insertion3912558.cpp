    //17D8103015J Kobayashi Ikuko Mingwon23 C++
    #include <iostream>
    #include <vector>

using namespace std;
    int main(){
    int n,v=0,i,j=0;
    std::vector<int> a;

    cin >> n;

    for(i=0;i<n;i++){
        cin >> v;
        a.push_back(v);
    }

    for(j=0;j<n;j++)cout <<a[j] << (j==n-1?'\n':' ');

    for(i=1;i<n;i++){
        v=a[i];   
        j=i-1;       
        while((j>=0) && (a[j]>v)){      
        a[j+1]=a[j];
        j--;
        a[j+1]=v;
        }

        for(j=0;j<n;j++)cout <<a[j] << (j==n-1?'\n':' ');
    }

    return 0;
    }
