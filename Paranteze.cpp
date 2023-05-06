// Paranteze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;
//ifstream f("paranteze.in.txt");
//ofstream g("paranteze.out.txt");
ifstream f("paranteze.in");
ofstream g("paranteze.out");
struct info
{
    char first;
    int second;
    info(const char a, const int b) : first(a), second(b){}
    ~info(){}
};
void clear_stack(stack<info>& s)
{
    while (!s.empty())
        s.pop();
}
int main()
{
    int gl_max = 0;
    int n;
    char ch;
    stack<info> st;
    f >> n;
    int* check;
    check = new int[n];
    for (int i = 0; i < n; i++)
    {
        check[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        f >> ch;
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(info(ch, i));
        }
        //
        if (ch == ')')
        {
            if (!st.empty() && st.top().first == '(')
            {
                int temp = i - st.top().second + 1;
                if (st.top().second > 0)
                {
                    check[i] = temp + check[st.top().second - 1];
                }
                st.pop();
            }  
            else
            {
                clear_stack(st);
            }   
        }
        //
        if (ch == ']')
        {
            if (!st.empty() && st.top().first == '[')
            {
             
                int temp = i - st.top().second + 1;
                if (st.top().second > 0)
                {
                    check[i] = temp + check[st.top().second - 1];
                }
                st.pop();
            }
            else
            {
                clear_stack(st);
            }
        }
        //
        if (ch == '}')
        {
            if (!st.empty() && st.top().first == '{')
            {
                int temp = i - st.top().second + 1;
                if (st.top().second > 0)
                {
                    check[i] = temp + check[st.top().second - 1];
                }
                st.pop();
            }
            else
            {
                clear_stack(st);
            }
        }
        //
    }
    for (int i = 0; i < n; i++)
    {
        if (check[i] > gl_max)
            gl_max = check[i];
    }
    g << gl_max;
    delete[] check;
    f.close();
    g.close();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
