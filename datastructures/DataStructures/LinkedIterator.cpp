#include "List\LinkedIterator.h"
#include "List\SLinkedList.h"
#include "List\DLinkedList.h"
#include "List\Link.h"
#include "PCSTree.h"
#include <assert.h>

//FORWARD ITERATOR
LinkedIterator::LinkedIterator(const SLinkedList& list)
	: root(list.GetRoot()), first(list.GetRoot()->next), current(nullptr)
{
}

LinkedIterator::LinkedIterator(const DLinkedList& list)
	: root(list.GetRoot()), first(list.GetRoot()->next), current(nullptr)
{
}

LinkedIterator::LinkedIterator(const PCSTree& list)
	: root(list.GetRoot()), first(list.GetRoot()->next), current(nullptr)
{
}

SLink* LinkedIterator::First()
{
	current = first;
	next = ((SLink*)current)->next;
	return current;
}

SLink* LinkedIterator::Next()
{
	assert(!IsDone());
	current = next;
	next = ((SLink*)current)->next;
	return current;
}

bool LinkedIterator::IsDone() const
{
	return current == root;
}

SLink* LinkedIterator::CurrentItem() const
{
	return current;
}


//REVERSE ITERATOR
LinkedReverseIterator::LinkedReverseIterator(const DLinkedList& list)
	: root(list.GetRoot()), first(list.GetRoot()->prev), current(nullptr)
{
}

LinkedReverseIterator::LinkedReverseIterator(const PCSTree& list)
	: root(list.GetRoot()), first(list.GetRoot()->prev), current(nullptr)
{
}

DLink* LinkedReverseIterator::First()
{
	current = first;
	next = ((DLink*)current)->prev;
	return current;
}

DLink* LinkedReverseIterator::Next()
{
	assert(!IsDone());
	current = next;
	next = ((DLink*)current)->prev;
	return current;
}


bool LinkedReverseIterator::IsDone() const
{
	return current == root;
}

DLink* LinkedReverseIterator::CurrentItem() const
{
	return current;
}

