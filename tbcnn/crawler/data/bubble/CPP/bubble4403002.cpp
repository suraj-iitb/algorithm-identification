#include<iostream>

int main(){
    int n,tmp,cnt=0;
    std::cin >> n;
    
    int a[n];
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }
    
    int flag=1;
    while(flag!=0){
        flag=0;
        int j=n-1;
        while(j!=0){
            if(a[j-1]>a[j]){
                tmp=a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
                cnt++;
                flag=1;
            }
            j--;
        }
    }
    for(int i=0;i<n-1;i++){
        std::cout << a[i] << " ";
    }
    std::cout << a[n-1] << "\n";
    std::cout << cnt << "\n";
    
    return 0;
}
