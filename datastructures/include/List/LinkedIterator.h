#pragma once

#include "Link.h"

class SList;
class DList;
class PCSTree;

/*
Forward and Backwards iterators for Single and Double Linked lists and PCSTrees
*/
class LinkedIterator
{
public:
	LinkedIterator(const SList& list);
	LinkedIterator(const DList& list);
	LinkedIterator(const PCSTree& tree);

	//First() must be called before being allowed to iterate.
	inline Link *First() { return (Link*)PrivFirst(); }
	inline Link *Next() { return (Link*)PrivNext(); }
	inline const bool IsDone() const { return PrivIsDone(); }
	inline Link *CurrentItem() const { return (Link*)PrivCurrentItem(); }

protected:
	const Link* root;
	Link* first;
	Link* current;
	Link* next; //allows us to do things like delete current node without messing up iteration.


protected:
	LinkedIterator(const Link* root, Link* first, Link* current);

	virtual void* PrivFirst();
	virtual void* PrivNext();
	virtual bool PrivIsDone() const;
	virtual void* PrivCurrentItem() const;
};

class LinkedReverseIterator : public LinkedIterator
{
public:
	LinkedReverseIterator(const DList& list);
	LinkedReverseIterator(const PCSTree& tree);

protected:
	virtual void* PrivFirst() override;
	virtual void* PrivNext() override;
};