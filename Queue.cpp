// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;
//ifstream f("queue.in.txt");
//ofstream g("queue.out.txt");
ifstream f("queue.in");
ofstream g("queue.out");

int to_num(char s[30])
{
	if (s[1] == 'o')
		return -1;
	int nr = 0;
	int c = 10;
	while (c < 30 && isdigit(s[c]))
	{
		nr = nr * 10 + ((int)s[c] - (int)'0');
		c++;
	}
	return nr;
}
void read_(int num)
{
	g << "read(" << num << ") ";
}
void write_(int num)
{
	g << "write(" << num << ") ";
}
void push_(int choice, int num)
{
	g << "push(" << choice << "," << num << ") ";
}
void pop_(int choice)
{
	g << "pop(" << choice << ") ";
}
int main()
{
	stack<int> st1, st2;
	int n;
	char str[30];
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> str;
		int x = to_num(str);
		if (x >= 0)
		{
			st1.push(x);
			read_(x);
			push_(1, x);
		}
		else
		{
			if (!st2.empty())
			{
				int temp = st2.top();
				st2.pop();
				pop_(2);
				write_(temp);
				//cout << temp << endl;
			}
			else
			{
				int temp = -1;
				while (!st1.empty())
				{
					temp = st1.top();
					st1.pop();
					pop_(1);
					if (st1.empty())
					{
						write_(temp);
					}
					else
					{
						st2.push(temp);
						push_(2, temp);
					}
					//cout << temp << endl;
				}
			}
		}
		g << endl;
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
