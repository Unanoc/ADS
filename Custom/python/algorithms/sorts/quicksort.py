def quicksort(arr):
    _quicksort(arr, 0, len(arr)-1)

def _quicksort(arr, start, end):
    if start < end:
        pivot = partition(arr, start, end)

        _quicksort(arr, start, pivot-1)
        _quicksort(arr, pivot+1, end)


def partition(arr, start, end):
    pivot = arr[end]
    wall = start-1

    for i in range(start, end):
        if arr[i] < pivot:
            wall += 1
            arr[i], arr[wall] = arr[wall], arr[i]
        
    wall += 1
    arr[wall], pivot = pivot, arr[wall]

    return wall




test1 = [5,1,7,3,8,2,5,3,7,9]
print(test1)

quicksort(test1)
print(test1)
