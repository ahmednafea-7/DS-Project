#pragma once
#define MAX 200
#include <ctime>
#include <cstdlib>
#include <ostream>
#include <iostream>
template <class T>
class Array {
	T* items[MAX];
	int length;
	int GenerateRandomIndex(int max);
public:
	Array();
	bool insertitem(const T&);
	bool ejectitem(T&);
	int getCount() const;
	bool isEmpty();
	void print();
};
//template<typename T>
//inline Array<T>::Array() :length(0)
//{
//}
template<typename T>
inline Array<T>::Array() :length(0)
{
	srand((int)time(0));
}

template<typename T>
inline int Array<T>::GenerateRandomIndex(int max)
{
	return (rand() % max);
}

template<typename T>
inline bool Array<T>::isEmpty()
{
	return length == 0;
}

template<typename T>
inline bool Array<T>::insertitem(const T& item)
{
	if (length == MAX)
		return false; // full array 

	items[length++] = item; // Add the item to the array and increase the counter
	return true; // Item inserted successfully
}

template<typename T>
inline bool Array<T>::ejectitem(T& item)
{
	if (length == 0)
		return false; // no items 

	int randomIndex = GenerateRandomIndex(length - 1);
	T* deleteMe = items[randomIndex];
	item = *items[randomIndex];
	items[randomIndex] = items[length - 1];
	length--;
	delete deleteMe;
	return true;
}
template<typename T>
inline void Array<T>::print()
{
	if (isEmpty())
		return;
	for (int i = 0; i < length - 1; i++)
		std::cout << *items[i] << ",";

	std::cout << *items[length - 1];
}
template<typename T>
inline int Array<T>::getCount() const
{
	return length;
}