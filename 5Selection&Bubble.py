'''
5. Write a python program to store first year percentage of students in array . 
Write function for sorting array of floating point numbers in ascending order using 
a) Selection sort 
b) bubble sort and 
    display top five scores.
'''

def selectionSort(arr , n) :
    for i in range(n) :
        min = i
        j = i + 1
        for j in range( i+1, n) :
            if(arr[j] < arr[min]) :
                min = j
        if(min != i) :
            arr[i] , arr[min] = arr[min] , arr[i]

def bubbleSort(arr , n) :
    i = n - 1
    while(i >= 0) :
        for j in range(0 , i) :
            if(arr[j] > arr[j + 1]) :
                arr[j] , arr[j+1] = arr[j+1] , arr[j]
        i = i - 1

def main() :
    n = int(input("\nEnter the number of students : "))
    student = [] #created empty array

    for i in range(n) :
       percentage = float(input(f"\nEnter the percentage of student {i+1} : "))
       student.append(percentage)
    
    while(True) :
        print("\n1. To sort using Selection Sort Method.")
        print("\n2. To sort using Bubble Sort Method.")
        print("\n3. To Exit.")
        x = int(input("\nEnter the valid choice : "))

        if(x == 1) :
            selectionSort(student , n)
            print("\nSelection sort Result -->", student)
            print("\nTop 5 percentage --> ")
            for i in range(n-5 , n) :
                print(student[i])
        
        elif(x == 2) :
            bubbleSort(student , n)
            print("\nBubble sort Result -->", student)
            print("\nTop 5 percentage --> ")
            for i in range(n-5 , n) :
                print(student[i])

        elif(x == 3) :
            print("\nExited. Thank you...!")
            break
        
        else :
            print("\nEntered a Invalid option...!")
    
main()