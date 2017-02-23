#include "List\SList.h"
#include <assert.h>

SList::SList()
	: root(), size(0)
{
}

void SList::Insert(SLink* inNode, SLink* prevNode)
{
	assert(inNode->GetContainer() == nullptr);
	if (nullptr == prevNode)
	{
		PushFront(inNode);
	}
	else
	{
		inNode->SetNext(prevNode->GetNext());
		prevNode->SetNext(inNode);
		inNode->SetContainer(this);
		size++;
	}
}

void SList::PushFront(SLink* inNode)
{
	assert(inNode->GetContainer() == nullptr);
	inNode->SetNext(root.GetNext());
	root.SetNext(inNode);
	inNode->SetContainer(this);
	size++;
}

SLink* SList::PopFront()
{
	SLink* link = nullptr;
	
	if (size != 0)
	{
		link = root.GetNext();
		root.SetNext(root.GetNext()->GetNext());
		link->SetContainer(nullptr);
		size--;
	}
	
	return link;
}

void SList::Remove(SLink* inNode)
{
	assert(inNode->GetContainer() == this);

	LinkedIterator it = this->GetIterator();
	Link* prev = &root;
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		if (link == inNode)
		{
			((SLink*)prev)->SetNext(inNode->GetNext());
			((SLink*)link)->SetContainer(nullptr);
			size--;
			break;
		}
		prev = link;
	}
}

SLink* SList::PeekFront() const
{
	if (size != 0)
	{
		return root.GetNext();
	}
	return nullptr;
}

void SList::DeleteList()
{
	LinkedIterator it = this->GetIterator();
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		delete link;
	}
	
	//reset back to initial state
	this->size = 0;
	this->root.SetNext(&root);
}
