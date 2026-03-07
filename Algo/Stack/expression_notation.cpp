#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int get_precedence(char op)
{
    if (op == '^')
        return 4;
    else if (op == '*' || op == '/')
        return 3;
    else
        return 2;
}

bool is_operator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

string in_to_postfix(string exp)
{
    stack<char> st;
    string postfix = "";
    for (char c : exp)
    {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && is_operator(st.top()) && get_precedence(st.top()) >= get_precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

string in_to_prefix(string exp)
{
    reverse(exp.begin(), exp.end());
    for (char &c : exp)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    string prefix = in_to_postfix(exp);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string post_to_infix(string exp)
{
    stack<string> st;
    for (char c : exp)
    {
        if (isalnum(c))
            st.push(string(1, c));
        else if (is_operator(c))
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push("(" + a + c + b + ")");
        }
    }
    return st.top();
}

string pre_to_infix(string exp)
{
    reverse(exp.begin(), exp.end());
    stack<string> st;
    for (char c : exp)
    {
        if (isalnum(c))
            st.push(string(1, c));
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();

            st.push("(" + a + c + b + ")");
        }
    }
    return st.top();
}

int main()
{
    string exp;
    cout << "Enter Exp: ";
    cin >> exp;
    cout << "PostFix: " << in_to_postfix(exp);
    cout << "\nPreFix: " << in_to_prefix(exp);
    cout << "\nPostfix to Infix: " << post_to_infix(in_to_postfix(exp));
    cout << "\nPrefix to Infix: " << pre_to_infix(in_to_prefix(exp));
    return 0;
}