// RMQ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//ifstream f("rmq.in.txt");
//ofstream g("rmq.out.txt");
ifstream f("rmq.in");
ofstream g("rmq.out");
struct powr
{
    int first;
    int second;
};
int exponent(int a)
{
    int exp = 0;
    while (a > 1)
    {
        exp++;
        a = a >> 1;
    }
    return exp;
}
int get_min(const int a, const int b)
{
    if (a > b)
        return b;
    return a;
}
int main()
{
    int n, m;
    f >> n >> m;
    int exp = exponent(n);
    int* powers_exp;
    powers_exp = new int[exp + 1];
    int p = 1;
    for (int i = 0; i <= exp; i++)
    {
        powers_exp[i] = p;
        p = p << 1;
    }
    //
    powr* closest_power;
    closest_power = new powr[n + 1];
    closest_power[0].first = 0;
    closest_power[0].second = 0;
    closest_power[1].first = 1;
    closest_power[1].second = 0;
    for (int i = 2; i <= n; i++)
    {
        if (closest_power[i - 1].first << 1 == i)
        {
            closest_power[i].first = closest_power[i - 1].first << 1;
            closest_power[i].second = closest_power[i - 1].second + 1;
            continue;
        }
        closest_power[i].first = closest_power[i - 1].first;
        closest_power[i].second = closest_power[i - 1].second;
    }
    //
    vector<int>* rmq;
    rmq = new vector<int>[exp + 1];
    int val;
    for (int i = 0; i < n; i++)
    {
        f >> val;
        rmq[0].push_back(val);
    }
    for (int i = 1; i <= exp; i++)
    {
        for (int j = 0; j <= n - powers_exp[i]; j++)
        {
            rmq[i].push_back(get_min(rmq[i - 1][j], rmq[i - 1][j + (powers_exp[i] >> 1)]));
        }
    }
    //
    int x, y;
    for (int i = 0; i < m; i++)
    {
        f >> x >> y;
        x--;
        y--;
        int len = y - x + 1;
        int cls_power = closest_power[len].first;
        int index = closest_power[len].second;
        int answer = get_min(rmq[index][x], rmq[index][x + len - cls_power]);
        //cout << answer << endl;
        g << answer << endl;
    }
    delete[] rmq;
    delete[] powers_exp;
    delete[] closest_power;
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
