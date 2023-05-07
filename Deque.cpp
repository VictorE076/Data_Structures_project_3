// Deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
//ifstream f("deque.in.txt");
//ofstream g("deque.out.txt");
ifstream f("deque.in");
ofstream g("deque.out");

int dq_size(int l, int r)
{
    if (l < 0 || r < 0)
        return 0;
    if (l > r)
        return 0;
    return abs(r - l) + 1;
}
int main()
{
    int n, k;
    f >> n >> k;
    int* dq_val, *dq_index;
    long long sum = 0;
    dq_val = new int[n + 1];
    dq_index = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dq_val[i] = -10000001;
        dq_index[i] = -10000001;
    }
    int left = 0, right = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        f >> x;
        while (dq_size(left, right) && right >= 0 && right <= n && dq_val[right] >= x)
        {
            right--;
        }
        dq_val[++right] = x;
        dq_index[right] = i;
        while (dq_size(left, right) && left >= 0 && left <= n && dq_index[left] <= i - k)
        {
            left++;
        }
        if (i < k - 1)
            continue;
        if(dq_size(left, right) && left >= 0 && left <= n)
            sum += dq_val[left];
    }
    g << sum;
    delete[] dq_val;
    delete[] dq_index;
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
