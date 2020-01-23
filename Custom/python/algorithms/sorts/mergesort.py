def mergesort(arr, l, r):
    if l < r:
        mid = int(l + (r - l) // 2)

        mergesort(arr, l, mid)
        mergesort(arr, mid + 1, r)

        merge(arr, l, r, mid)

def merge(arr, l, r, mid):
    left_arr = [arr[x] for x in range(l, mid)]
    right_arr = [arr[x] for x in range(mid, r+1)]

    i, j, k = 0, 0, 0

    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] < right_arr[j]:
            arr[k] = left_arr[i]
            i += 1
        else:
            arr[k] = right_arr[j]
            j += 1
        k += 1
    
    while i < len(left_arr):
        arr[k] = left_arr[i]
        i += 1
        k += 1
    while j < len(right_arr):
        arr[k] = right_arr[j]
        j += 1
        k += 1


a = [1,52,7,5,0,2,4]
print(a)
mergesort(a, 0, 6)
print(a)