#pragma once
#include "List\SLinkedList.h"

//templated version of Single linked list. T is still required to inherit from SLink
template <typename T>
class SList
{
public:
	SList() {}
	SList(const SList& other) = delete;
	SList& operator=(const SList& other) = delete;

	//Too risky to automatically delete every node.
	//Some nodes may not have been individually dynamically allocated.
	~SList() = default;

	void Insert(T* inNode, T* prevNode) { list.Insert(inNode, prevNode); }
	//O(n) operation. Try not to use much
	void Remove(T* inNode) { list.Remove(inNode); }

	void PushFront(T* inNode) { list.PushFront(inNode); }
	T* PopFront() { return list.PopFront(); }
	T* PeekFront() const { return list.PeekFront(); }

	ForwardIterator<T> GetIterator() const { return ForwardIterator<T>(list); }

	int Size() const { return list.Size(); }

	//This method will loop through and delete each node
	//This may be risky as some nodes may not have been dynamically allocated.
	void DeleteList() { list.DeleteList(); }

	template <typename Function>
	void Apply(Function& function)
	{
		SLink* root = list.GetRoot();
		SLink* link = root->GetNext();
		while (link != root)
		{
			T* element = (T*)link;
			function(*element);
			link = link->GetNext();
		}
	}

private:
	SLinkedList list;
};