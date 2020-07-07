#import pysnooper
#import numpy
#import os,re,sys,operator
#from collections import Counter,deque
#from operator import itemgetter
#from itertools import accumulate,combinations,groupby,combinations_with_replacement,permutations
from sys import stdin,setrecursionlimit
#from copy import deepcopy
#import heapq
#import math
#import string

setrecursionlimit(10**6)
input=stdin.readline

def Counting_sort(array,max_value):
    cnt_element=[0]*(max_value+1)
    ans_array=[]
    for i in array: cnt_element[i]+=1
    for i,j in enumerate(cnt_element): ans_array+=[i]*j
    return ans_array

n=int(input().rstrip())
a=[int(i) for i in input().split()]
ans=Counting_sort(a,max(a))
print(*ans)
