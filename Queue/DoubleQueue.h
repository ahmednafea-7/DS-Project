
/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers,
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				The Node: item of type T and a "next" pointer
					-------------
					| item| next | --->
					-------------
General Queue case:

				 frontPtr																backPtr
					\											   						/
					 \											  					   /
					------------- 	  ------------- 	  ------------- 	  -------------
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------

Empty Case:

				 frontptr	 backptr
						\	 /
						 \	/
					---- NULL ------

*/

#ifndef Double_Queue 
#define Double_Queue


#include "../Queue/Node.h"
#include "../Queue/QueueADT.h"

template <typename T>
class DoubleQueue :public QueueADT<T>
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	DoubleQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry) {};
	bool dequeue(T& frntEntry, T& bckEntry);
	bool peek(T& frntEntry)  const;
	void print();
	~DoubleQueue();

};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
DoubleQueue<T>::DoubleQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool DoubleQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DoubleQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	return true;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DoubleQueue<T>::dequeue(T& frntEntry, T& bckEntry)
{
	if ((isEmpty()) || (frontptr == backptr))
		return false;
	else {
		Node<T>* nodeToDeletePtr = frontPtr;
		frntEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();

		Node<T>* nodeToDeletePtr1 = backPtr;
		bckEntry = bckPtr->getItem();
		Node<T>* Temp = frontPtr;
		while (Temp->getNext() != backPtr)
			Temp = Temp->getNext();
		backPtr = Temp;
		// Queue is not empty; remove front and back
	}


	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;
	delete nodeToDeletePtr1;


	return true;
}



/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/

template <typename T>
bool DoubleQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
DoubleQueue<T>::~DoubleQueue()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor
	cout << "\nStarting LinkedQueue destructor...";
	cout << "\nFreeing all nodes in the queue...";

	//Free all nodes in the queue
	T temp;
	while (dequeue(temp));

	cout << "\n Is LinkedQueue Empty now?? ==> " << boolalpha << isEmpty();
	cout << "\nEnding LinkedQueue destructor..." << endl;
}
template <typename T>
void DoubleQueue<T>::print()
{
	Node<T>* ptr;
	ptr = frontptr;
	while (ptr)
	{
		cout << ptr->getItem();
		ptr = ptr->getnext();
	}
}

#endif