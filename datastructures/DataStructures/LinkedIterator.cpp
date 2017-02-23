#include "List\LinkedIterator.h"
#include "List\SList.h"
#include "List\DList.h"
#include "List\Link.h"
#include "PCSTree.h"
#include <assert.h>

//FORWARD ITERATOR
LinkedIterator::LinkedIterator(const SList& list)
	: root(list.GetRoot()), first(list.GetRoot()->next), current(nullptr)
{
}

LinkedIterator::LinkedIterator(const DList& list)
	: root(list.GetRoot()), first(list.GetRoot()->next), current(nullptr)
{
}

LinkedIterator::LinkedIterator(const PCSTree& list)
	: LinkedIterator(list.GetRoot(), list.GetRoot()->next, nullptr)
{
}

LinkedIterator::LinkedIterator(const Link* root, Link* first, Link* current) : root(root), first(first), current(current)
{
}

void* LinkedIterator::PrivFirst()
{
	current = first;
	next = ((SLink*)current)->next;
	return current;
}

void* LinkedIterator::PrivNext()
{
	assert(!PrivIsDone());
	current = next;
	next = ((SLink*)current)->next;
	return current;
}

bool LinkedIterator::PrivIsDone() const
{
	return current == root;
}

void* LinkedIterator::PrivCurrentItem() const
{
	return current;
}


//REVERSE ITERATOR
LinkedReverseIterator::LinkedReverseIterator(const DList& list)
	: LinkedIterator(list.GetRoot(), list.GetRoot()->prev, nullptr)
{
}

LinkedReverseIterator::LinkedReverseIterator(const PCSTree& list)
	: LinkedIterator(list.GetRoot(), list.GetRoot()->prev, nullptr)
{
}

void* LinkedReverseIterator::PrivFirst()
{
	current = first;
	next = ((DLink*)current)->prev;
	return current;
}

void* LinkedReverseIterator::PrivNext()
{
	assert(!PrivIsDone());
	current = next;
	next = ((DLink*)current)->prev;
	return current;
}
