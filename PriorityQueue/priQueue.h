#pragma once
#include "priNode.h"


//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
    priNode<T>* head;
    int count;
public:
    priQueue() : head(nullptr) {}

    ~priQueue()
    {
        T tmp;
        int p;
        while (dequeue(tmp,p));
    }

    //insert the new node in its correct position according to its priority
    bool enqueue(const T& data, int priority)
    {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) 
        {
            
            newNode->setNext(head);
            head = newNode;
            count++;
            return true;
        }
       
        priNode<T>* current = head;        
        while (current->getNext() && priority <= current->getNext()->getPri())
        {
            current = current->getNext();
        }
        newNode->setNext( current->getNext());
        current->setNext( newNode);
        count++;
        return true;
    }

    bool dequeue(T& topEntry, int& pri) 
    {
        if (isEmpty())
        {
            topEntry = nullptr;
            return false;
        }
        int x = 0;
        topEntry = head->getItem(x);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        count--;
        return true;
    }

    bool peek(T& topEntry, int& pri) 
    {
        if (isEmpty()) {
            topEntry = nullptr;
            pri = -1;
            return false;
        }

        topEntry = head->getItem(pri);
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

   void print()
    {
       if (isEmpty())
       {
           cout << "[ ]";
           return;
       }
        priNode<T>* ptr;
        ptr = head;
        cout << "[ ";
        while (ptr)
        {
            int x = 0;
            cout << *(ptr->getItem(x));
            ptr =ptr->getNext();
        }
        cout << '\b' << '\b' << " ";
        cout << "]";
    }
   int GetCount()
   {
       return count;
   }

};
