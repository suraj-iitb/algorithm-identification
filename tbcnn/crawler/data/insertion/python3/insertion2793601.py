#16D8101012J 伊藤惇　dj Python3

def Insertion_Sort():
    N=int(input())
    A=list(map(int,input().split()))
    for i in range(0,N):
        v=A[i]
        j=i-1
        while j>=0 and A[j]>v:
            A[j+1]=A[j]
            j=j-1
        A[j+1]=v
        
        print(A[0],end="")
        for i in range(1,N):
            print(" {}".format(A[i]),end="")
        print('\n',end="")
        


if __name__ == "__main__":
    Insertion_Sort()

    

