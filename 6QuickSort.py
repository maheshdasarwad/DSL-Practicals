'''
Write a python program to store first year percentage of students in array. 
Write function for sorting array -->
                     of floating point numbers in ascending order 
using quick sort and
display top five scores.
'''

def quickSort(arr, start ,end) :
    
    if( start >= end ) : #base case for recursion
        return
    
    pivotIndex = start
    pivot = arr[pivotIndex]

    i = start + 1
    j = end

    while(True) :
        while(i <= end and arr[i] < pivot) :
            i = i + 1
        while(j >= pivotIndex and arr[j] > pivot) :
            j = j - 1

        if(i < j) :
            arr[i] , arr[j] = arr[j] , arr[i]
        else :
            arr[pivotIndex] , arr[j] = arr[j] , arr[pivotIndex]
            break

    quickSort(arr , start , j - 1) #Left part
    quickSort(arr, j + 1 , end) #Right part

def main() :
    n = int(input("Enter the number of students : "))
    student = []
    for i in range(n) :
        percentage = float(input(f"Enter percentage for student {i + 1} :"))
        student.append(percentage)

    #Original -->
    print("\nOriginal percentages : ", student)

    #Sorted in ascending order -->
    quickSort(student , 0 , n - 1)
    print("\nSorted Percentages : ", student)

    #To display top five scores -->
    print("\nTop five scores : ")
    for i in range(n-5 , n) :
        print(student[i])
    
main()