// Vila2_Infoarena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
//ifstream f("vila2.in.txt");
//ofstream g("vila2.out.txt");
ifstream f("vila2.in");
ofstream g("vila2.out");
int modd(int a, int b)
{
    if (a > b)
        return a - b;
    return b - a;
}
//////
//////
class Node
{
public:
    int value;
    int index;
    Node* next;
    Node* prev;

public:
    Node() = default;
    Node(const int value, const int index)
    {
        this->value = value;
        this->index = index;
        prev = NULL;
        next = NULL;
    }
};
class Deque : private Node
{
private:
    unsigned size;
    Node* begin_;
    Node* end_;

public:
    Deque()
    {
        size = 0;
        begin_ = NULL;
        end_ = NULL;
    }
    //////
    void push_back(const int num, const int ind)
    {
        Node* new_node = new Node(num, ind);
        if (begin_ == NULL)
        {
            begin_ = new_node;
        }
        else
        {
            end_->next = new_node;
            new_node->prev = end_;
        }
        end_ = new_node;
        size++;
    }
    void pop_back()
    {
        if (this->size == 1)
        {
            Node* p = begin_;
            begin_ = NULL;
            delete p;
            size--;
        }
        else
        if (end_ != NULL)
        {
            Node* py = end_;
            end_ = end_->prev;
            end_->next = NULL;
            delete py;
            size--;
        }
    }
    //
    void push_front(const int num, const int ind)
    {
        Node* new_node = new Node(num, ind);
        if (begin_ == NULL)
        {
            end_ = new_node;
        }
        else
        {
            new_node->next = begin_;
            begin_->prev = new_node;
        }
        begin_ = new_node;
        size++;
    }
    void pop_front()
    {
        if (this->size == 1)
        {
            Node* p = begin_;
            begin_ = NULL;
            delete p;
            size--;
        }
        else
        if (end_ != NULL)
        {
            Node* py = begin_;
            begin_ = begin_->next;
            begin_->prev = NULL;
            delete py;
            size--;
        }
    }
    //////
    unsigned get_size()
    {
        return this->size;
    }
    int back_index()
    {
        return this->end_->index;
    }
    int front_index()
    {
        return this->begin_->index;
    }
    int back_value()
    {
        return this->end_->value;
    }
    int front_value()
    {
        return this->begin_->value;
    }
    ////// 
};
int main()
{
    int global_max = 0;
    int n, k;
    Deque dq_max;
    Deque dq_min;
    f >> n >> k;
    int x;
    for (int i = 0; i < n; i++)
    {
        f >> x;
        cout << x << " ";
        while (dq_max.get_size() > 0 && dq_max.back_value() < x)
        {
            dq_max.pop_back();
        }
        while (dq_min.get_size() > 0 && dq_min.back_value() > x)
        {
            dq_min.pop_back();
        }
        dq_max.push_back(x, i);
        dq_min.push_back(x, i);
        while (dq_max.get_size() > 0 && i - k > dq_max.front_index())
        {
            dq_max.pop_front();
        }
        while (dq_min.get_size() > 0 && i - k > dq_min.front_index())
        {
            dq_min.pop_front();
        }
        if (dq_max.get_size() > 0 && dq_min.get_size() > 0)
        {
            if (modd(dq_max.front_value(), dq_min.front_value()) > global_max)
                global_max = modd(dq_max.front_value(), dq_min.front_value());
        }
    }
    //cout << endl;
    //cout << global_max;
    g << global_max;
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
