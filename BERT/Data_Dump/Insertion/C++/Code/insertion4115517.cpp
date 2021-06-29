#include<iostream>
#include<vector>

void print(int len, std::vector<int>& v)
{
    for(int i=0;i<len;++i)
    {
        std::cout << v[i];
        if(i!=len-1)
        {
            std::cout<< " ";
        }
    }
    std::cout << '\n';
}

void insertion_sort(int len, std::vector<int>& v)
{
    print(len, v);
    int key;
    for(int i=1;i<len;++i)
    {
        key = v[i];
        int j = i - 1;
        for(;j>=0;--j)
        {
            if(key<v[j])
            {
                v[j+1] = v[j];
            }
            else
            {
                break;
            }
        }
        v[j+1] = key;
        print(len, v);
        
    }
}

int main()
{
    std::vector<int> v;
    int len;
    int value;
    std::cin >> len;
    for(int i=0;i<len;++i)
    {
        std::cin >> value;
        v.push_back(value);
    }
    
    insertion_sort(len, v);
    
    return 0;
}
