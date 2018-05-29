from mergesort import mergeSort, bubbleSort, isSorted
import random
import time


divider = "___________________________________________________________________\n"


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