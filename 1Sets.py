'''
In second year computer engineering class, group A student's play cricket, 
group B students play badmintion and group C students play football. 
Write a python program using function to compute following :-

a) List of students who play both cricket and badmintion.
b) List of students who play either cricket or badmintion but not both
c) Number of students who play neither cricket nor badmintion.
d) Number of students who play cricket and football but not badminton. 

(Note :- While realizing the group, duplicate entries should be avoided, 
Do not use SET built-in functions)
'''

def intersection(x, y):
    result = []
    for i in x:
        if i in y and i not in result:
            result.append(i)
    result.sort()
    return result

def union(x, y):
    result = y.copy()
    for i in x:
        if i not in result:
            result.append(i)
    result.sort()
    return result

def symmetric_diff(x, y):
    result = []
    for i in union(x, y):
        if i not in intersection(x, y):
            result.append(i)
    result.sort()
    return result

def difference(x, y):
    result = []
    for i in x:
        if i not in y:
            result.append(i)
    result.sort()
    return result

def get_input_group(prompt):
    group = []
    print(prompt)
    while True:
        try:
            x = int(input("\tEnter roll number (or type '0' to finish): "))
            if x == 0:
                break
            if x not in group:
                group.append(x)
            else:
                print("\tRoll number already entered. Please enter a different roll number.")
        except ValueError:
            print("\tInvalid input. Please enter a valid roll number.")
    
    return group

def main():

    total_students = int(input("Total number of students in second year computer engineering : "))

    G1 = get_input_group("\nGroups of students who play cricket : ")
    G1.sort()
    G2 = get_input_group("\nGroups of students who play badminton : ")
    G2.sort()
    G3 = get_input_group("\nGroups of students who play football : ")
    G3.sort()
    
    print("\nCRICKET group :: ", G1)
    print("BADMINTON group :: ", G2)
    print("FOOTBALL group :: ", G3)

    while True:
        print("\nSelect an option:")
        print("\t 1. List of students who play both cricket and badminton")
        print("\t 2. List of students who play either cricket or badminton but not both")
        print("\t 3. Number of students who play neither cricket nor badminton")
        print("\t 4. Number of students who play cricket and football but not badminton")
        print("\t 5. Exit")

        choice = int(input("Enter your choice : "))

        if choice == 1 :
            print("\nList of students who play both cricket and badminton : ", intersection(G1 , G2))
        elif choice == 2 :
            print("\nList of students who play either cricket or badminton but not both : ", symmetric_diff(G1, G2))
        elif choice == 3 :
            diffG3G1 = difference(G3 , G1)
            print("\nNumber of students who play neither cricket nor badminton : ", len(difference(diffG3G1 , G2)))
        elif choice == 4 :
            uniG1G3 = union(G1 , G3)
            print("\nNumber of students who play cricket and football but not badminton : ", len(difference(uniG1G3 , G2)))
        elif choice == 5 :
            print("\nExited the program bye...")
            break
        else:
            print("Invalid choice. Please select a valid option.")


main()
