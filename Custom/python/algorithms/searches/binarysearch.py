def binarysearch(arr, x):
    left, right = 0, len(arr)-1

    while left <= right:
        mid = left + (right - left) // 2

        if x == arr[mid]:
            return mid
        
        if x < arr[mid]:
            right = mid - 1
        else:
            left = mid
    
    return -1
