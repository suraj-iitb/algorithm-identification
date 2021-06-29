#include <iostream>

void print(int *sort, int N);
void insert_sort(int *sort, int N);

int main()
{
    int N;
    int *sort;
    
    while(std::cin >> N)
    {
        sort = new int[N];
        
        for(int i = 0; i < N; i++)
        {
            std::cin >> sort[i];
        }
        
        insert_sort(sort, N);
        print(sort,N);
    }

}

void print(int *sort, int N)
{
    for(int i = 0; i < N; i++)
    {
        std::cout << sort[i];
        
        if(i != N - 1)
        {
            std::cout << " ";
        }
    }
    
    std::cout << std::endl;
}

void insert_sort(int *sort, int N)
{
    int v,j;
    for(int i = 1; i < N ; i++)
    {
        print(sort,N);
        v = sort[i];
        j = i - 1;
        
        while((j>=0) && (sort[j] > v))
        {
            sort[j+1] = sort[j];
            j--;
        }
        sort[j+1] = v;
    }
}
