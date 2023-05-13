// Heapuri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//ifstream f("heapuri.in.txt");
//ofstream g("heapuri.out.txt");
ifstream f("heapuri.in");
ofstream g("heapuri.out");
struct values
{
    int val;
    int n_th;
    bool deleted;
    values() = delete;
    values(const int val, const int n_th, const bool deleted) : val(val), n_th(n_th), deleted(deleted){}
    ~values(){}
};
void insert_heap(vector<values>& hp, int* p, const int x, const int c)
{
    hp.push_back(values(x, c, false));
    int ind = hp.size();
    ind--;
    p[c] = ind;
    while (ind > 0)
    {
        if (hp[ind].val < hp[(ind - 1) >> 1].val)
        {
            swap(hp[ind], hp[(ind - 1) >> 1]);
            p[hp[ind].n_th] = ind;
            p[hp[(ind - 1) >> 1].n_th] = (ind - 1) >> 1;
        }
        else
            break;
        ind = (ind - 1) >> 1;
    }
}
void delete_root(vector<values>& hp, int* p)
{
    const int sz = hp.size() - 1;
    if (sz == -1)
        return;
    swap(hp[0], hp[sz]);
    hp.pop_back();
    p[hp[0].n_th] = 0;
    int current = 0;
    bool flag = true;
    while (flag)
    {
        int minpos = current;
        int left = (current << 1) + 1;
        int right = (current << 1) + 2;
        if (left < sz && hp[left].val < hp[minpos].val)
            minpos = left;
        if (right < sz && hp[right].val < hp[minpos].val)
            minpos = right;
        if (minpos == current)
            flag = false;
        else
        {
            swap(hp[current], hp[minpos]);
            p[hp[current].n_th] = current;
            p[hp[minpos].n_th] = minpos;
            current = minpos;
        }
    }
}
int main()
{
    int* pos;
    vector<values> heap;
    int n, op, x;
    f >> n;
    pos = new int[n];
    for (int i = 0; i < n; i++)
    {
        pos[i] = -1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        f >> op;
        if (op == 3)
        {  
            while (!heap.empty() && heap[0].deleted)
            {
                delete_root(heap, pos);
            }
            if (!heap.empty())
            {
                //cout << heap[0].val << endl;
                g << heap[0].val << endl;
            }
            continue;
        }
        f >> x;
        if (op == 1)
        {
            insert_heap(heap, pos, x, count);
            count++;
            continue;
        }
        if (pos[x - 1] >= 0 && heap[pos[x - 1]].deleted == false)
            heap[pos[x - 1]].deleted = true;
    }
    delete[] pos;
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
