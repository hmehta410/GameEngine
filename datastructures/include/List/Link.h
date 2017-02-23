#pragma once

//Base class for any linked data structure. It only requires that it knows its 
//own container. It will mainly be used as a pure address for comparison to see
//if the link is currently residing in another container, is free, or is already
//part of the container it's being added to.
class Link
{
public:
	Link() : container(nullptr) {}
	virtual ~Link() = default;

	void* GetContainer() const { return container; }

protected:
	void SetContainer(void* container) { this->container = container; }

private:
	void* container;
};

//Used for singly linked lists
class SLink : public Link
{
public:
	/*
	setting next equal to this might seem to create a weird infinite loop if used 
	alone but when used as the root of a circular list I can add a node by saying
	newNode.next = root.next; and since root.next == root for an empty list, 
	everything works out without having to check for nullptrs everywhere.
	*/
	SLink() : next(this) {}

protected:
	SLink* GetNext() const { return next; }
	void SetNext(SLink* link) { next = link; }

private:
	SLink* next;
	friend class LinkedIterator;
	friend class SList;
};

//used for doubly linked lists
class DLink : public SLink
{
public:
	DLink() : prev(this) {}

protected:
	DLink* prev;

	DLink* GetPrev() const { return prev; }
	void SetPrev(DLink* link) { prev = link; }

	//hide SLink's version to help with casting
	DLink* GetNext() const { return (DLink*)SLink::GetNext(); }

private:
	friend class LinkedReverseIterator;
	friend class DList;
};
