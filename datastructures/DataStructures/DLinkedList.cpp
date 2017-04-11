#include "List\DLinkedList.h"
#include <assert.h>
#include <utility>

DLinkedList::DLinkedList()
	: root(), size(0)
{
}

DLinkedList::DLinkedList(DLinkedList&& list)
{
	*this = std::move(list);
}

DLinkedList& DLinkedList::operator=(DLinkedList&& list)
{
	this->size = list.size;
	this->root = list.root;

	this->root.GetNext()->SetPrev(&this->root);
	this->root.GetPrev()->SetNext(&this->root);

	LinkedIterator it(*this);
	for (DLink* link = (DLink*)it.First(); !it.IsDone(); link = (DLink*)it.Next())
	{
		link->SetContainer(this);
	}
	return *this;
}

void DLinkedList::InsertAfter(DLink* inNode, DLink* prevNode)
{
	assert(inNode->GetContainer() == nullptr);

	if (prevNode == nullptr)
	{
		this->PushFront(inNode);
	}
	else
	{
		inNode->SetPrev(prevNode);
		inNode->SetNext(prevNode->GetNext());
		prevNode->GetNext()->SetPrev(inNode);
		prevNode->SetNext(inNode);
		inNode->SetContainer(this);

		this->size++;
	}
}

void DLinkedList::PushFront(DLink* inNode)
{
	assert(inNode->GetContainer() == nullptr);

	this->root.GetNext()->SetPrev(inNode);
	inNode->SetNext(root.GetNext());
	inNode->SetPrev(&root);
	this->root.SetNext(inNode);
	inNode->SetContainer(this);

	this->size++;
}

void DLinkedList::PushBack(DLink* inNode)
{
	assert(inNode->GetContainer() == nullptr);

	this->root.GetPrev()->SetNext(inNode);
	inNode->SetPrev(this->root.GetPrev());
	inNode->SetNext(&this->root);
	this->root.SetPrev(inNode);
	inNode->SetContainer(this);

	this->size++;
}

DLink* DLinkedList::PeekFront() const
{
	if (this->IsEmpty())
	{
		return nullptr;
	}

	return this->root.GetNext();
}

DLink* DLinkedList::PopFront()
{
	DLink* link = this->PeekFront();

	this->Remove(link);

	return link;
}

DLink* DLinkedList::PeekBack() const
{
	if (this->IsEmpty())
	{
		return nullptr;
	}

	return this->root.GetPrev();
}

DLink* DLinkedList::PopBack()
{
	DLink* link = this->PeekBack();

	this->Remove(link);

	return link;
}

void DLinkedList::Remove(DLink* inNode)
{
	if (inNode == nullptr)
	{
		return;
	}

	assert(inNode->GetContainer() == this);

	inNode->GetNext()->SetPrev(inNode->GetPrev());
	inNode->GetPrev()->SetNext(inNode->GetNext());

	inNode->SetNext(nullptr);
	inNode->SetPrev(nullptr);

	inNode->SetContainer(nullptr);
	this->size--;
}

void DLinkedList::Clear()
{
	LinkedIterator it = this->GetIterator();
	DLink* lastLink = nullptr;
	Link* link = it.First();
	while (!it.IsDone())
	{
		lastLink = (DLink*)link;
		link = it.Next();

		//the below three lines put each node back in its default state
		lastLink->SetContainer(nullptr);
		lastLink->SetNext(nullptr);
		lastLink->SetPrev(nullptr);
	}

	this->ResetToDefaultState();
}

void DLinkedList::DeleteList()
{
	LinkedIterator it = this->GetIterator();
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		delete link;
	}

	this->ResetToDefaultState();
}

void DLinkedList::ResetToDefaultState()
{
	size = 0;
	root.SetNext(&root);
	root.SetPrev(&root);
}
