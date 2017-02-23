#include "List\DList.h"
#include <assert.h>
#include <utility>

DList::DList()
	: root(), size(0)
{
}

DList::DList(DList&& list)
{
	*this = std::move(list);
}

DList& DList::operator=(DList&& list)
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

void DList::InsertAfter(DLink* inNode, DLink* prevNode)
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

void DList::PushFront(DLink* inNode)
{
	assert(inNode->GetContainer() == nullptr);

	this->root.GetNext()->SetPrev(inNode);
	inNode->SetNext(root.GetNext());
	inNode->SetPrev(&root);
	this->root.SetNext(inNode);
	inNode->SetContainer(this);

	this->size++;
}

void DList::PushBack(DLink* inNode)
{
	assert(inNode->GetContainer() == nullptr);

	this->root.GetPrev()->SetNext(inNode);
	inNode->SetPrev(this->root.GetPrev());
	inNode->SetNext(&this->root);
	this->root.SetPrev(inNode);
	inNode->SetContainer(this);

	this->size++;
}

DLink* DList::PeekFront() const
{
	if (this->IsEmpty())
	{
		return nullptr;
	}

	return this->root.GetNext();
}

DLink* DList::PopFront()
{
	DLink* link = this->PeekFront();

	this->Remove(link);

	return link;
}

DLink* DList::PeekBack() const
{
	if (this->IsEmpty())
	{
		return nullptr;
	}

	return this->root.GetPrev();
}

DLink* DList::PopBack()
{
	DLink* link = this->PeekBack();

	this->Remove(link);

	return link;
}

void DList::Remove(DLink* inNode)
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

void DList::Clear()
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

void DList::DeleteList()
{
	LinkedIterator it = this->GetIterator();
	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		delete link;
	}

	this->ResetToDefaultState();
}

void DList::ResetToDefaultState()
{
	size = 0;
	root.SetNext(&root);
	root.SetPrev(&root);
}
