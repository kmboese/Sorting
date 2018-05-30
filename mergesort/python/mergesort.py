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
    for i in range(0, len(lst)-1):
        if lst[i] > lst[i+1]:
            sorted = False
            break
    return sorted

'''
Bubble-sort algorithm used for sorting the base-case lists for mergesort
Time Complexity: 
    * Average Case: O(n^2 / 2)
    * Worst case: O(n^2)
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


'''
Sort a list of values using the mergesort algorithm
Time Complexity: 
    * Average Case: O(n log n) 
    * Worst Case: O(n log n)
Space Complexity: O(n)
'''
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
