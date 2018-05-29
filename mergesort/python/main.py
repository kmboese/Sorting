from mergesort import mergeSort, bubbleSort, isSorted
import random
import time
import sys


divider = "___________________________________________________________________\n"

#Constants
ELEMENTS = 5000
INT_RANGE = 100
#Argument locations for the following command line inputs
ELEMENT_FLAG_INDEX = 1
INT_RANGE_FLAG_INDEX = 2

'''
Parses command line arguments for the mergesort tester
    Returns:
        * elements: number of elements to use in list for sorting
        * int_range: range of numbers to generate when creating lists
'''
def parseArgs():
    elements, int_range = None, None
    #Assign default values if no arguments given
    if (len(sys.argv) == 1):
        elements = ELEMENTS
        int_range = INT_RANGE
    elif (len(sys.argv) == 3):
        elements = int(sys.argv[ELEMENT_FLAG_INDEX])
        int_range = int(sys.argv[INT_RANGE_FLAG_INDEX])
    else:
        print("Error: wrong number of arguments given. "\
        "Syntax: python main.py {[elements] [integer-range]}")
        exit()

    return elements, int_range

def main():
    elements, int_range = parseArgs()
    lst = []
    start, end = None, None
    for i in range(elements):
        lst.append(random.randint(1,int_range))
    print("Number of elements to sort: {}\tNumber range: {}"\
        .format(elements, int_range))
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
