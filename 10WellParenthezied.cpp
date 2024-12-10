/*
In any language program mostly syntax error occurs due to unbalancing 
delimiter such as (), {}, [].
Write C++ program using stack to check whether given expression 
is well parenthesized or not.
*/

#include <iostream>
#include <stack>
using namespace std;

int checkParenthesis(string &exp)
{
    int n = exp.size();
    bool flag = true;
    stack<char> s;

    for(int i = 0 ; i < n ; i++)
    {
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            s.push(exp[i]);
        }
        
        else if(exp[i] == '}')
        {
            if(!s.empty() && s.top() == '{') s.pop();
            else
            {
                flag = false;
                break;
            }
        }
        else if(!s.empty() && exp[i] == ']')
        {
            if(s.top() == '[') s.pop();
            else
            {
                flag = false;
                break;
            }
        }
        else if(!s.empty() && exp[i] == ')')
        {
            if(s.top() == '(') s.pop();
            else
            {
                flag = false;
                break;
            }
        }
    }
    
    if(!s.empty()) return false;

    return flag;
}

int main()
{
    string exp;
    cout<<"\nEnter your expression : ";
    getline(cin,exp);

    bool ans = checkParenthesis(exp);
    if(ans == true)
    {
        cout<<"\nThe Expression "<<exp<<" is well parenthesized."<<endl;
    }
    else cout<<"\nThe Expression "<<exp<<" is not well parenthesized."<<endl;

    return 0;
}


