import random
import copy
import time


QUIET = True
divider = "___________________________________________________________________\n"

'''Print debug messages if not in quiet mode'''
def dPrint(message):
    if not QUIET:
        print("\tDEBUG: {}".format(message))

'''Time a function'''
def time_fn(fn, args):
    start = time.time()
    fn(args)
    end = time.time()
    return round(end-start,5)

'''Returns True is a list is sorted, false otherwise'''
def isSorted(lst):
    sorted = True
    i = 0
    while i < len(lst)-1:
        if lst[i] > lst[i+1]:
            sorted = False
            break 
        i += 1
    return sorted


'''
Bubble-sort algorithm used for sorting the base-case lists for mergesort.
Time Complexity: 
    * Worst case: O(n^2)
    * Average Case: O(n^2 / 2)
Space Complexity: O(n)
'''
def bubbleSort(lst):
    tmp_list = copy.deepcopy(lst) #temp value to use for swapping values
    tmp = None
    for i in range(len(tmp_list)):
        for j in range(i+1, len(tmp_list)):
            if (tmp_list[i] > tmp_list[j]):
                tmp = tmp_list[i]
                tmp_list[i] = tmp_list[j]
                tmp_list[j] = tmp
    return tmp_list

'''Merge two lists by element comparison'''
def merge(left, right):
    dPrint("left = {}, right = {}".format(left, right))
    i = 0
    j = 0
    res = []
    if len(left) < len(right):
        shorter = left
        longer = right
    else:
        shorter = right
        longer = left

    dPrint("Shorter = {}, Longer = {}".format(shorter, longer))
    dPrint("len(shorter) =  {}, len(longer) = {}".format(len(shorter), len(longer)))
    while i < len(shorter) and j < len(longer):
        dPrint("In loop: i = {}, j = {}".format(i, j))
        if shorter[i] < longer[j]:
            res.append(shorter[i])
            i += 1
        else:
            res.append(longer[j])
            j += 1
    dPrint("i = {}, j = {}".format(i, j))
    #Append any remaining elements
    while j < len(longer):
        res.append(longer[j])
        j += 1
    return res


'''Sort a list of values using the mergesort algorithm'''
def mergeSort(left, right=[], init=False):
    #Initialize right and left lists on first run
    if init:
        tmp = left
        left = tmp[:len(tmp)//2]
        right = tmp[len(tmp)//2:]
        dPrint("Init: {} and {}".format(left, right))
    #Base case: left or right has one element
    '''
    if (len(left) == 1 and len(right) == 1):
        a,b, = left[0], right[0]
        dPrint("Base case: left = {}, right = {}".format(left, right))
        if a < b:
            return [a,b]
        else:
            return [b,a]
    '''
    if (len(left) == 1 or len(right) == 1):
        return(bubbleSort(merge(left, right)))
    #Split the list in half
    #dPrint("1: list contains {}{}".format(left,right))
    #left = mergeSort(left[:len(left)/2], left[len(left)/2:], sorted) #mergesort first half of list
    #dPrint("2a: sorted list contains {}".format(sorted))
    #mergesort first half of list
    #right = mergeSort(right[:len(right)/2], right[len(right)/2:], sorted)

    tmp = merge(\
                mergeSort(\
                    left[:len(left)//2], left[len(left)//2:]), \
                mergeSort(\
                    right[:len(right)//2], right[len(right)//2:])
                )
    dPrint("tmp contains {}".format(tmp))
    return tmp


def main():
    elements = 100 #number of elements to generate in sorted list
    int_range = 100 #upper range of random integers to generate
    lst = []
    start, end = None, None
    for i in range(elements):
        lst.append(random.randint(1,int_range))
    print("Number of elements to sort: {}".format(len(lst)))
    print(divider)
    #Bubble Sort
    print("Performing bubble sort...")
    start = time.time()
    bubble_sort_list = bubbleSort(lst)
    end = time.time()
    assert(isSorted(bubble_sort_list))
    #print("Bubble sorted list: {}".format(bubble_sort_list))
    bubble_sort_time = end-start
    print("Time: {}".format(round(bubble_sort_time, 3)))

    #Merge Sort
    print("\nPerforming merge sort...")
    start = time.time()
    merge_sort_list = mergeSort(lst, init=True)
    end = time.time()
    assert(isSorted(merge_sort_list))
    #print("Merge-Sorted list: {}".format(merge_sort_list))
    merge_sort_time = end-start
    print("Time: {}".format(round(merge_sort_time, 3)))

    print("Merge sort sorted {} times faster"\
        .format(round(bubble_sort_time/merge_sort_time, 1)))

if (__name__ == "__main__"):
    main()