// Proc2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
//ifstream f("proc2.in.txt");
//ofstream g("proc2.out.txt");
ifstream f("proc2.in");
ofstream g("proc2.out");
struct t_p
{
    int task;
    int proc;
};
struct rule
{
    bool operator()(t_p& a, t_p& b)
    {
        return a.task > b.task;
    }
};
int main()
{
    priority_queue<int, vector<int>, greater<int>> procesoare;
    priority_queue <t_p, vector<t_p>, rule> task_proc;
    int n, m, x, y;
    f >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        procesoare.push(i);
    }
    for (int i = 1; i <= m; i++)
    {
        f >> x >> y;
        while (!task_proc.empty() && x >= task_proc.top().task)
        {
            procesoare.push(task_proc.top().proc);
            task_proc.pop();
        }
        t_p temp;
        temp.task = x + y;
        temp.proc = procesoare.top();
        //cout << temp.proc << endl;
        g << temp.proc << endl;
        procesoare.pop();
        task_proc.push(temp);
    }
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
