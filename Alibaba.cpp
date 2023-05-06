// Alibaba.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;
//ifstream f("alibaba.in.txt");
//ofstream g("alibaba.out.txt");
ifstream f("alibaba.in");
ofstream g("alibaba.out");
const int d = (int)'0';
void print_stack(stack<int>& s)
{
    stack<int> temp;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty())
    {
        //cout << temp.top();
        g << temp.top();
        temp.pop();
    }     
}
int main()
{
    stack<int> st;
    int n, k;
    f >> n >> k;
    int count = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        char ch;
        f >> ch;
        x = (int)ch - d;
        while (!st.empty() && x > st.top() && count < k)
        {
            st.pop();
            count++;
        }
        if((int)st.size() < n - k)
            st.push(x);
    }
    print_stack(st);
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
