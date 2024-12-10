'''
Write a python program to compute following operations on String :
a) To display word with the longest length.
b) To determine the frequency of occurrence of particular character in the string.
c) To check whether given string is palindrome or not.
d) To display index of first appearance of the substring.
e) To count the occurrences of each word in a given string.
'''

def longestWord(str) :
    longstr = ""
    i = 0
    while(i < len(str)) :
        word = "" #temp string
        while( i < len(str) and str[i] != ' ') :
            word += str[i]
            i = i + 1
        
        if(len(word) > len(longstr)) : #update longest string
            longstr = word
        
        while(i < len(str) and str[i] == ' ') :
            i = i + 1
    return longstr


def charOccurrence(str , x) :
    count = 0
    for i in range(len(str)) :
        if(str[i] == x) :
            count = count + 1
    
    return count


def isPalindrome(str) :
    front = 0
    end = len(str) - 1
    while(front < end) :
        if(str[front] == str[end]) :
            front = front + 1
            end = end - 1
        else :
            return -1
    return 1


def substringIndex(str, substr) :
    for i in range(len(str) - len(substr) + 1) : #to iterate till last possible index
        flag = True

        for j in range(len(substr)) :
            if(str[i + j] != substr[j]) :
                flag = False
                break
        if (flag == True) :
            return i
        
    return -1


def wordOccurence(str) :
    tempDic = {} #Dictionary to store word count
    word = ""

    for char in str :
        if (char != ' ') :
            word += char

        else :
            if word : #check word is empty or not
                if(word in tempDic) :
                    tempDic[word] += 1
                else :
                    tempDic[word] = 1
                    word = "" #reset
    #Handle last word
    if word :
        if(word in tempDic) :
            tempDic[word] += 1
        else :
            tempDic[word] = 1

    return tempDic 


def main() :
    str = input("\nEnter your string : ")

    while(True) :
        print("\n   1.To display word with longest length.")
        print("   2.To find frequency of occurence of particular character.")
        print("   3.To check string palindrome or not.")
        print("   4.To display index of first appereance of substring.")
        print("   5.To count occurence of each word.")
        print("   6.To Exit.")
        ch = int(input("Select valid option : "))

        if(ch == 1) :
            print("\nWord with longest length = ", longestWord(str))

        elif(ch == 2) :
            x = input("\nEnter Character : ")
            print(f"Character {x} occurrence = ",charOccurrence(str , x))
        
        elif(ch == 3) :
            if(isPalindrome(str) != -1) :
                print("\nThe given string is Palindrome.")
            else :
                print("\nNot a palindrome.")

        elif(ch == 4) :
            substr = input("\nEnter substring : ")
            result = substringIndex(str,substr)
            if (result != -1) :
                print(f"\nIndex of first appereance of {substr} = ", result)
            else :
                print(f"\n{substr} not found !!!")

        elif(ch == 5) :
            print("\nOccurence of each word in string -->")
            result = wordOccurence(str)
            for word,count in result.items():
                print(f"{word} : {count}")

        elif(ch == 6) :
            print("\nExited. Thank you...")
            break
        else :
            print("\nEnter a valid option !!!!")
        
main()
        
       