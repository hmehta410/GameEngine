#pragma once

#include "List\Link.h"
#include "List\LinkedIterator.h"

/*
A single linked list
*/
class SLinkedList
{
public:
	SLinkedList();
	SLinkedList(const SLinkedList& other) = delete;
	SLinkedList& operator=(const SLinkedList& other) = delete;

	//Too risky to automatically delete every node.
	//Some nodes may not have been individually dynamically allocated.
	~SLinkedList() = default;
	
	void Insert(SLink* inNode, SLink* prevNode);
	//O(n) operation. Try not to use much
	void Remove(SLink* inNode);

	void PushFront(SLink* inNode);
	SLink* PopFront();
	SLink* PeekFront() const;

	LinkedIterator GetIterator() const { return LinkedIterator(*this); }

	const SLink* GetRoot() const { return &root; }
	int Size() const { return size; }

	//This method will loop through and delete each node
	//This may be risky as some nodes may not have been dynamically allocated.
	void DeleteList();

private:
	//I use a root and create a circular list. End is found equal to root
	//instead of nullptr
	SLink root;
	int size;
};

