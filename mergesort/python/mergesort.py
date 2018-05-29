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
    print("Args: {}".format(args))
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
    res = []
    i = 0
    j = 0

    dPrint("left = {}, right = {}".format(left, right))

    #Determine the shorter array to avoid out of bounds errors
    if len(left) < len(right):
        shorter = left
        longer = right
    else:
        shorter = right
        longer = left

    #Sort by element comparison
    while i < len(shorter) and j < len(longer):
        if shorter[i] < longer[j]:
            res.append(shorter[i])
            i += 1
        else:
            res.append(longer[j])
            j += 1
    #Append any remaining elements if one list was shorter than the other
    if (j < len(longer)):
        res.extend(longer[j:])
    if (i < len(shorter)):
        res.extend(shorter[i:])
    dPrint("res = {}".format(res))
    return res


'''Sort a list of values using the mergesort algorithm'''
def mergeSort(left, right=[]):
    #Initialize right and left lists on first run
    if not right:
        tmp = left
        left = tmp[:len(tmp)//2]
        right = tmp[len(tmp)//2:]
        dPrint("Init: {} and {}".format(left, right))
    #Base case: left or right (or both) list has one element, use bubbleSort and merge the two subarrays
    if (len(left) == 1 or len(right) == 1):
        dPrint("Base case: left = {}, right = {}".format(left, right))
        return(bubbleSort(merge(left, right)))

    #Merge the result of recursively splitting the two subarrays
    result = merge(\
                mergeSort(\
                    left[:len(left)/2], left[len(left)/2:]), \
                mergeSort(\
                    right[:len(right)/2], right[len(right)/2:])
                )
    return result


def main():
    elements = 5000 #number of elements to generate in sorted list
    int_range = 100 #upper range of random integers to generate
    lst = []
    start, end = None, None
    for i in range(elements):
        lst.append(random.randint(1,int_range))
    print("Number of elements to sort: {}".format(len(lst)))
    #print("Initial list: {}".format(lst))
    print(divider)

    #Bubble Sort
    print("Performing bubble sort...")
    start = time.time()
    bubble_sort_list = bubbleSort(lst)
    end = time.time()
    assert(isSorted(bubble_sort_list))
    assert(len(bubble_sort_list) == len(lst))
    #print("Bubble sorted list: {}".format(bubble_sort_list))
    bubble_sort_time = end-start
    print("Time: {}".format(round(bubble_sort_time, 3)))

    #Merge Sort
    print("\nPerforming merge sort...")
    start = time.time()
    merge_sort_list = mergeSort(lst)
    end = time.time()
    #print("Merge-Sorted list: {}".format(merge_sort_list))
    assert(isSorted(merge_sort_list))
    assert(len(merge_sort_list) == len(lst))
    merge_sort_time = end-start
    print("Time: {}".format(round(merge_sort_time, 3)))

    if merge_sort_time != 0.0:
        print("Merge sort sorted {} times faster"\
            .format(round(bubble_sort_time/merge_sort_time, 1)))

if (__name__ == "__main__"):
    main()