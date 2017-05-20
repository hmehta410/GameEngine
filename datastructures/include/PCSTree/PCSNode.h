#pragma once
#define PCSNODE_VERSION 3.0

#include "List\Link.h"

class PCSNode : public DLink
{
public:
	// constructor
	PCSNode() : parent(nullptr), child(nullptr), 
		nextSibling(nullptr), prevSibling(nullptr), depth(-1) {}

	PCSNode *GetParent() const { return parent; }
	PCSNode *GetChild() const { return child; }
	PCSNode *GetNextSibling() const { return nextSibling; }
	PCSNode *GetPrevSibling() const { return prevSibling; }
	PCSNode *GetNext() const { return (PCSNode*)DLink::GetNext(); }
	PCSNode *GetPrev() const { return (PCSNode*)DLink::GetPrev(); }

	int GetDepth() const { return depth; }

private:
	// accessors
	void setParent(PCSNode* in) { parent = in; }
	void setChild(PCSNode* in) { child = in; }
	void setNextSibling(PCSNode* in) { nextSibling = in; }
	void setPrevSibling(PCSNode* in) { prevSibling = in; }
	void SetNext(PCSNode* in) { DLink::SetNext(in); }
	void SetPrev(PCSNode* in) { DLink::SetPrev(in); }
	void setDepth(int i) { depth = i; }

	void* GetContainer() const { return DLink::GetContainer(); }
	void SetContainer(void* aContainer) { DLink::SetContainer(aContainer); }

	//member variables
	PCSNode *parent;
	PCSNode *child;
	PCSNode *nextSibling;
	PCSNode *prevSibling;
	//inherited member variables
		//SLink *next;
		//DLink *prev;
		//void* container;

	int depth;

	friend class PCSTree;
};
