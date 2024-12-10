'''
4.a). Write a python program to store roll numbers of students in array who attended 
    training program in 
                   ** random order **. 
    Write function for searching whether particular student attended training 
    program or not, using --> Linear search and Sentinel search.
'''

def linearSearch(arr, n , key) :
    flag = -1

    for i in range(n) :
        if(arr[i] == key) :
            flag = i
            break

    return flag

def sentinelSearch(arr,n,key) :

    lastelm = arr[n-1]
    arr[n-1] = key #acts as sentinal element

    i = 0
    while(arr[i] != key) :
        i = i+1
    
    arr[n-1] = lastelm
    if(i < n-1 or key == lastelm) : #key found
        return i
    else : #key not fount
        return -1 

def main() :

    n = int(input("\nEnter the number of students : "))
    student = [] #created empty array

    print("\nEnter the list of students who attended the program --> ")
    for i in range(n) :
       rollno = int(input())
       student.append(rollno)
    
    while(True) :
        print("\n1. To search using Linear Search Method.")
        print("2. To search using Sentinal Search Method.")
        print("3. To Exit.")
        x = int(input("Enter the valid choice : "))

       
        if(x == 1) :    
            key = int(input("\nEnter student roll number : "))
            result = linearSearch(student , n , key)
            if(result != -1) :
                print(f"Roll Number {key} attended program.")
            else :
                print(f"Roll Number {key} not attend program !!!")

        elif(x == 2) :
            key = int(input("\nEnter student roll number : "))
            result = sentinelSearch(student , n , key)
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
