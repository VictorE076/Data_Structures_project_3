// Hashuri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//ifstream f("hashuri.in.txt");
//ofstream g("hashuri.out.txt");
ifstream f("hashuri.in");
ofstream g("hashuri.out");

const int prime = 666013; // numar prim 
unsigned my_hash_func(const unsigned x)
{
    return x % prime; // Division method with prime numbers
}
int find_value(vector<unsigned> *mp, const int index, const unsigned x)
{
    unsigned sz = mp[index].size();
    for (unsigned i = 0; i < sz; i++)
    {
        if (mp[index][i] == x)
            return i;
    }
    return -1;
}
int main()
{
    vector<unsigned> *hash_map;
    hash_map = new vector<unsigned>[prime];
    unsigned n, op, x;
    f >> n;
    for (unsigned i = 0; i < n; i++)
    {
        f >> op >> x;
        unsigned hashing = my_hash_func(x);
        int found = find_value(hash_map, hashing, x);
        if (op == 1)
        {
            if (found == -1)
                hash_map[hashing].push_back(x);
            continue;
        }
        if (op == 2)
        {
            if (found >= 0)
            {
                int current = found + 1;
                int sz = hash_map[hashing].size();
                while (current < sz)
                {
                    hash_map[hashing][current - 1] = hash_map[hashing][current];
                    current++;
                }
                hash_map[hashing].pop_back();
            }
            continue;
        }
        if (found >= 0)
        {
            //cout << 1 << endl;
            g << 1 << endl;
        }
        else
        {
            //cout << 0 << endl;
            g << 0 << endl;
        }
    }
    f.close();
    g.close();
    delete[] hash_map;
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
