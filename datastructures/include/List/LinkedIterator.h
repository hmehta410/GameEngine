#pragma once

#include "Link.h"

class SLinkedList;
class DLinkedList;
class PCSTree;

/*
Forward and Backwards iterators for Single and Double Linked lists and PCSTrees
*/
class LinkedIterator
{
public:
	LinkedIterator(const SLinkedList& list);
	LinkedIterator(const DLinkedList& list);
	LinkedIterator(const PCSTree& tree);

	//First() must be called before being allowed to iterate.
	SLink *First();
	SLink *Next();
	bool IsDone() const;
	SLink *CurrentItem() const;

private:
	const SLink* root;
	SLink* first;
	SLink* current;
	SLink* next; //allows us to do things like delete current node without messing up iteration.
};

class LinkedReverseIterator
{
public:
	LinkedReverseIterator(const DLinkedList& list);
	LinkedReverseIterator(const PCSTree& tree);

	DLink *First();
	DLink *Next();
	bool IsDone() const;
	DLink *CurrentItem() const;

protected:
	const DLink* root;
	DLink* first;
	DLink* current;
	DLink* next; //allows us to do things like delete current node without messing up iteration.
};

template <typename T>
class ForwardIterator : private LinkedIterator
{
public:
	ForwardIterator(const SLinkedList& list) : LinkedIterator(list){}
	ForwardIterator(const DLinkedList& list) : LinkedIterator(list){}
	ForwardIterator(const PCSTree& tree) : LinkedIterator(tree){}

	T* First() { return (T*)LinkedIterator::First(); }
	T* Next() { return (T*)LinkedIterator::Next(); }
	bool IsDone() const { return LinkedIterator::IsDone(); }
	T* CurrentItem() const { return (T*)LinkedIterator::CurrentItem() }
};

template <typename T>
class ReverseIterator : private LinkedReverseIterator
{
public:
	ReverseIterator(const DLinkedList& list) : LinkedReverseIterator(list){}
	ReverseIterator(const PCSTree& tree) : LinkedReverseIterator(tree){}

	T* First() { return (T*)LinkedReverseIterator::First(); }
	T* Next() { return (T*)LinkedReverseIterator::Next(); }
	bool IsDone() const { return LinkedReverseIterator::IsDone(); }
	T* CurrentItem() const { return (T*)LinkedReverseIterator::CurrentItem() }
};