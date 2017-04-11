#pragma once
#include "DLinkedList.h"

//templated version of Double linked list. T is still required to inherit from DLink
template <typename T>
class DList
{
public:
	DList() {}
	DList(DList&& o) : list(std::move(o.list)) {}
	DList& operator=(DList&& list) { *this = std::move(o.list); }

	DList(const DList&) = delete;
	DList& operator=(const DList&) = delete;

	//Too risky to automatically delete every node.
	//Some nodes may not have been individually dynamically allocated.
	~DList() {};

	void InsertAfter(T* inNode, T* prevNode){
		list.InsertAfter(inNode, prevNode);
	}

	//Removes inNode from the list. Safely ignores nullptr
	void Remove(T* inNode){
		list.Remove(inNode);
	}

	void PushFront(T* inNode){
		list.PushFront(inNode);
	}

	void PushBack(T* inNode) {
		list.PushBack(inNode); 
	}

	T* PopFront() { return (T*)list.PopFront(); }
	T* PopBack() { return (T*)list.PopBack(); }
	T* PeekFront() const { return (T*)list.PeekFront(); }
	T* PeekBack() const { return (T*)list.PeekBack(); }

	//Removes all nodes from list but does not delete any memory
	void Clear() { list.Clear(); }

	//This method will loop through and delete each node
	//This may be risky as some nodes may not have been dynamically allocated.
	void DeleteList() { list.DeleteList(); }

	ForwardIterator<T> GetIterator() { return ForwardIterator<T>(list); };
	ReverseIterator<T> GetReverseIterator() { return ReverseIterator<T>(list); };

	int Size() const { return list.Size(); }
	bool IsEmpty() const { return list.IsEmpty(); }

	template <typename Function>
	void Apply(Function& function)
	{
		DLink* root = list.GetRoot();
		DLink* link = root->GetNext();
		while (link != root)
		{
			T* element = (T*)link;
			function(*element);
			link = link->GetNext();
		}
	}

private:
	DLinkedList list;
};