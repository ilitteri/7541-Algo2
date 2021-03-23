# Python3 program to sort an array
# using bucket sort
def insertionSort(arr):
    for i in range(1, len(arr)):
        up = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > up:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = up    
    return arr    
             
def bucketSort(arr):
    aux = []
    slot_num = 10 # 10 means 10 slots, each
                  # slot's size is 0.1
    for i in range(slot_num):
        aux.append([])
         
    # Put array elements in different buckets
    for j in arr:
        index_b = int(slot_num * j)
        aux[index_b].append(j)
     
    # Sort individual buckets
    for i in range(slot_num):
        aux[i] = insertionSort(aux[i])
         
    # concatenate the result
    k = 0
    for i in range(slot_num):
        for j in range(len(aux[i])):
            arr[k] = aux[i][j]
            k += 1
    return arr