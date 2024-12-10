'''
Write a Python program to store marks scored in subject "Fundamental of Data Structure"
by N students in the class. Write functions to compute following :
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test 
d) Display mark with highest frequency.
'''

def average(score) :
    sum = 0
    presentcnt = 0

    for i in range(len(score)) :
        if(score[i] != -1) :
            sum = sum + score[i]
            presentcnt += 1
    
    if presentcnt == 0 :
        return 0
    
    return sum / presentcnt

def highest_and_lowest_score(score, n):
    highest = score[0]
    lowest = score[0]

    for i in range(1, n):
        if(score[i] > highest):
            highest = score[i]
        if(score[i] < lowest and score[i] != -1):
            lowest = score[i]

    return highest, lowest

def absentStudent(score) :
    count = 0
    for i in range(len(score)) :
        if(score[i] == -1) :
            count += 1
    return count

def highestFreq(score) :
    tempDic = {}
    count = 0
    most_frequency_mark = -1

    for i in score :
        if(i != -1) :
            if(i in tempDic) :
                tempDic[i] += 1
            else :
                tempDic[i] = 1
            if(tempDic[i] > count) :
                count = tempDic[i]
                most_frequency_mark = i
    
    return most_frequency_mark , count
            

def main() :

    score = []
    n = int(input("\nEnter total number of students in the class : "))
    for i in range(n) :
        x = input(f"Enter marks of student {i+1} [AB if absent] : ")
        if(x == 'AB') :
            score.append(-1)
        elif(x.isdigit()):
            x = int(x)
            score.append(x)
        else :
            print("\nEnter valid marks.")
    
    while(True) :
        print("\n1.Display the average of marks scored.")
        print("2.Display the highest and lowest marks scored.")
        print("3.Display the highest frequency of marks.")
        print("4.Display the absent students.")
        print("5.To EXIT !!")
        ch = int(input("Select valid option : "))

        if(ch == 1) :
            result = average(score)
            print("\nAverage marks of class = %.2f : " %result)
        
        elif(ch == 2):
            highest , lowest = highest_and_lowest_score(score,n)
            print("\nHeighest : ",highest," Lowest Marks : ",lowest)

        elif(ch == 3):
            marks , freq = highestFreq(score)
            if(marks != -1) :
                print(f"\n Highest Frequency marks : ",marks," Frequency : ",freq)
            else :
                print("\nNo highest Frequecny marks.")
        elif(ch == 4) :
            print("\nAbsent students in exam = ",absentStudent(score))
        elif(ch == 5) :
            print("\nExited. Thank you ..!!")
            break
        else :
            print("\nSelect valid option..!!!")


main()


