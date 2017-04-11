#pragma once

#include "List\Link.h"
#include "List\LinkedIterator.h"

//A custom double linked list that uses inheritance to turn elements into nodes 
//    rather than using nodes to contain elements. May not be suitable for all types
//	  but definitely helps with O(1) removal
class DLinkedList
{
public:
	DLinkedList();
	DLinkedList(DLinkedList&& list);
	DLinkedList& operator=(DLinkedList&& list);

	//some node types may or may not be copyable
	DLinkedList(const DLinkedList& other) = delete;
	DLinkedList& operator=(const DLinkedList& other) = delete;

	//Too risky to automatically delete every node.
	//Some nodes may not have been individually dynamically allocated.
	~DLinkedList() = default;
	
	//Inserts inNode after prevNode. If prevNode is null, inNode will be pushed to front
	void InsertAfter(DLink* inNode, DLink* prevNode);

	//Removes inNode from the list. Safely ignores nullptr
	void Remove(DLink* inNode);

	void PushFront(DLink* inNode);
	void PushBack(DLink* inNode);
	DLink* PopFront();
	DLink* PopBack();
	DLink* PeekFront() const;
	DLink* PeekBack() const;

	//Removes all nodes from list but does not delete any memory
	void Clear();

	//This method will loop through and delete each node
	//This may be risky as some nodes may not have been dynamically allocated.
	void DeleteList();

	//Iterators
	inline LinkedIterator GetIterator() const { return LinkedIterator(*this); }
	inline LinkedReverseIterator GetReverseIterator() const 
		{ return LinkedReverseIterator(*this); }

	//Accessors
	inline const DLink* GetRoot() const { return &root; }
	inline int Size() const { return size; }
	inline bool IsEmpty() const { return size == 0; }

private:
	//uses root to create a circular list with the end = root rather than nullptr
	DLink root;
	int size;

	//destructively set size and root back to initialized state.
	void ResetToDefaultState();
};

