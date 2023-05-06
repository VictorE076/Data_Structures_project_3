// Deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
//ifstream f("deque.in.txt");
//ofstream g("deque.out.txt");
ifstream f("deque.in");
ofstream g("deque.out");

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
    Deque dq;
    int n, k;
    int x;
    long long sum = 0;
    f >> n >> k;
    for (int i = 0; i < n; i++)
    {
        f >> x;
        while (dq.get_size() && dq.back_value() > x)
        {
            dq.pop_back();
        }
        dq.push_back(x, i);
        while (dq.get_size() && dq.front_index() <= i - k)
        {
            dq.pop_front();
        }
        if (i < k - 1)
            continue;
        sum += dq.front_value();
    }
    //cout << sum;
    g << sum;
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
