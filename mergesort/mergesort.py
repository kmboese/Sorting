import random

'''
Bubble-sort algorithm used for sorting the base-case lists for mergesort.
Time Complexity: 
    * Worst case: O(n^2)
    * Average Case: O(n^2 / 2)
Space Complexity: O(n)
'''
def bubbleSort(lst):
    tmp = None #temp value to use for swapping values

    for i in range(len(lst)):
        for j in range(i+1, len(lst)):
            if (lst[i] > lst[j]):
                tmp = lst[i]
                lst[i] = lst[j]
                lst[j] = tmp

'''Sort a list of values using the mergesort algorithm'''
def mergeSort(lst):
    #Base case: list is 2 elements or less
    if (len(lst) <= 2):
        return(bubbleSort(lst))

    

def main():
    print("MergeSort:\n")
    lst = [6,15,2,7,11,8,1]
    bubbleSort(lst)
    print("List contents: {}".format(lst))

if (__name__ == "__main__"):
    main()