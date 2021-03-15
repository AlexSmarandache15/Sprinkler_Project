def Partition(left, right, low, high):
    #left-prima multime, right - a 2-a multime, low-primul indice, high-ulttimul indice
    pivot = left[high]
    i = low - 1 #index al celui mai mic element
    for j in range(low, high):
        if (left[j] < pivot) or ( (left[j] == pivot) and (right[j] > right[high])): #daca elementul este mai mic decat pivotul
            i = i + 1 #se incrementeaza indexul
            left[i], left[j] = left[j], left[i]
            right[i], right[j] = right[j], right[i]
    left[i + 1], left[high] = left[high], left[i + 1]
    right[i + 1], right[high] = right[high], right[i + 1]
    return i + 1

def QuickSort(left, right, low, high):
    #se sorteaza crescator prima multime si descrescator dupa a 2 a
    if low < high:
        pi = Partition(left, right, low, high)
        QuickSort(left, right, low, pi - 1)
        QuickSort(left, right, pi + 1, high)

