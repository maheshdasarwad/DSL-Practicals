'''
4.b). Write a python program to store roll numbers of students in array who attended 
    training program in
                   ** sorted order **.      
    Write function for searching whether particular student attended training 
    program or not, using --> Binary search and Fibonacci search.
'''

def binarySearch(arr,n,key) :
    start = 0
    end = n-1
    while( start <= end) :
        mid = start + (end - start) // 2 # // <--to get interger rather than float
        if(key == arr[mid]) :
            return mid
        elif( key < arr[mid]) : #search left
            end = mid - 1
        else : #search right
            start = mid + 1
    
    return -1

def faboSearch(arr,n,key) :
    
    fib1 = 0 #(m-2)th fabo no.
    fib2 = 1 #(m-1)the fabo no.
    fib = fib2 + fib1 #(m)th fabo no.

    while( fib < n) :
        fib1 = fib2
        fib2 = fib
        fib = fib2 + fib1

    offset = -1
    while(fib > 1) :
        #min(offser + (m-2)th fibo no , length - 1)
        i = min(offset + fib1 , n-1)

        if(arr[i] < key): #greater
            fib = fib2
            fib2 = fib1
            fib1 = fib - fib2
           
            offset = i

        elif(arr[i] > key): #lesser
            fib = fib1
            fib2 = fib2 - fib1
            fib1 = fib - fib2
        
        else :
            return i
        
    #imp Check last element
    if(key == fib2 and key ==arr[offset + 1]) :
        return offset + 1
    
    return -1

def main() :

    n = int(input("\nEnter the number of students : "))
    student = [] #created empty array

    print("\nEnter the *sorted list of students who attended the program --> ")
    for i in range(n) :
       rollno = int(input())
       student.append(rollno)
    
    while(True) :
        print("\n1. To search using Binary Search Method.")
        print("2. To search using Fibonacci Search Method.")
        print("3. To Exit.")
        x = int(input("\nEnter the valid choice : "))
       
        if(x == 1) :    
            key = int(input("\nEnter student roll number : "))
            result = binarySearch(student , n , key)
            if(result != -1) :
                print(f"Roll Number {key} attended program.")
            else :
                print(f"Roll Number {key} not attend program !!!")

        elif(x == 2) :
            key = int(input("\nEnter student roll number : "))
            result = faboSearch(student , n , key)
            if(result != -1) :
                print(f"Roll Number {key} attended program.")
            else :
                print(f"Roll Number {key} not attend program !!!")

        elif(x == 3) :
            print("\nExited. Thank you...!")
            break
        
        else :
            print("\nEntered a Invalid option...!")
    
main()
           
