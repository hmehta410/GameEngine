#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <vector>

#include "PCSTree.h"
#include "PCSNode.h"
#include "PCSSerializer.h"


PCSTree::PCSTree() : root(), numNodes(0)
{
}

PCSTree::PCSTree(PCSTree&& in) : root(in.root), numNodes(in.numNodes)
{
	in.root.setChild(nullptr);
}

PCSTree& PCSTree::operator=(PCSTree&& in)
{
	if (&in != this)
	{
		this->root = in.root;
		this->numNodes = in.numNodes;
		in.root.setChild(nullptr);
	}
	return *this;
}

PCSTree::~PCSTree()
{
}

void PCSTree::Insert(PCSNode *inNode, PCSNode *parent)
{
	assert(inNode != nullptr);
	assert(inNode->GetContainer() == nullptr);

	if (parent == nullptr)
	{
		parent = &root;
	}
	else
	{
		assert(parent->GetContainer() == this);
	}
	inNode->parent = parent;

	numNodes++;

	PCSNode* nextSibling = parent->GetChild();
	inNode->setNextSibling(nextSibling);
	parent->setChild(inNode);
	if (nextSibling != 0)
	{
		nextSibling->setPrevSibling(inNode);
	}

	inNode->SetPrev(parent);

	PCSNode* next = parent->GetNext();
	inNode->SetNext(next);
	next->SetPrev(inNode);

	parent->SetNext(inNode);
	inNode->SetContainer(this);

	inNode->depth = parent->depth + 1;
}

void PCSTree::RecursiveRemove(PCSNode* inNode)
{
	if (inNode == nullptr)
	{
		return;
	}

	assert(inNode->GetContainer() == this);
	PCSNode* child = inNode->GetChild();
	PCSNode* next = inNode->GetNextSibling();
	PCSNode* forward = inNode->GetNext();
	PCSNode* reverse = inNode->GetPrev();

	if (forward != nullptr)
	{
		forward->SetPrev(reverse);
	}
	else
	{
		this->root.SetPrev(reverse);
	}
	
	if (reverse != nullptr)
	{
		reverse->SetNext(forward);
	}
	else
	{
		this->root.SetNext(forward);
	}

	inNode->setChild(0);
	inNode->setNextSibling(0);
	inNode->setPrevSibling(0);
	inNode->setParent(0);
	inNode->SetNext(0);
	inNode->SetPrev(0);

	RecursiveRemove(child);
	RecursiveRemove(next);
	inNode->SetContainer(nullptr);

	this->numNodes--;
}

void PCSTree::RecursiveDelete(PCSNode* inNode)
{
	RecursiveRemove(inNode);
	delete inNode;
}

void PCSTree::Remove(PCSNode * const inNode)
{
	if (inNode == nullptr){
		return;
	}
	assert(inNode->GetContainer() == this);

	PCSNode* nextSibling = inNode->GetNextSibling();
	PCSNode* prevSibling = inNode->GetPrevSibling();
	PCSNode* parent = inNode->GetParent();
	PCSNode* next = inNode->GetNext();
	PCSNode* prev = inNode->GetPrev();

	next->SetPrev(prev);
	inNode->SetNext(0);

	prev->SetNext(next);
	inNode->SetPrev(0);

	if (nextSibling != 0)
	{
		nextSibling->setPrevSibling(prevSibling);
		inNode->setNextSibling(0);
	}
	if (prevSibling != 0)
	{
		prevSibling->setNextSibling(nextSibling);
		inNode->setPrevSibling(0);
	}
	else
	{
		parent->setChild(nextSibling);
	}

	inNode->setParent(0);

	RecursiveRemove(inNode->GetChild());
	inNode->setChild(0);
	inNode->SetContainer(nullptr);

	inNode->setDepth(-1);

	this->numNodes--;
}

PCSTree PCSTree::Split(PCSNode* inNode)
{
	inNode;
	assert(false); //function not implemented
	return PCSTree();
}

void PCSTree::DeleteSubtree(PCSNode * const inNode)
{
	if (inNode == nullptr){
		return;
	}
	assert(inNode->GetContainer() == this);

	PCSNode* nextSibling = inNode->GetNextSibling();
	PCSNode* prevSibling = inNode->GetPrevSibling();
	PCSNode* parent = inNode->GetParent();
	PCSNode* next = inNode->GetNext();
	PCSNode* prev = inNode->GetPrev();

	next->SetPrev(prev);
	inNode->SetNext(0);

	prev->SetNext(next);
	inNode->SetPrev(0);


	if (nextSibling != 0)
	{
		nextSibling->setPrevSibling(prevSibling);
		inNode->setNextSibling(0);
	}
	if (prevSibling != 0)
	{
		prevSibling->setNextSibling(nextSibling);
		inNode->setPrevSibling(0);
	}
	else
	{
		parent->setChild(nextSibling);
	}

	inNode->setParent(0);

	RecursiveDelete(inNode->GetChild());
	inNode->setChild(0);
	inNode->SetContainer(nullptr);

	inNode->setDepth(-1);

	this->numNodes--;

	delete inNode;
}

void PCSTree::DeleteTree()
{
	LinkedIterator it = this->GetIterator();

	for (Link* link = it.First(); !it.IsDone(); link = it.Next())
	{
		delete link;
	}

	this->root.setChild(nullptr);
}

int PCSTree::GetDepth(PCSNode* inNode) const
{
	if (nullptr == inNode)
	{
		return 0;
	}

	int child = 1 + GetDepth(inNode->child);
	int sibling = GetDepth(inNode->nextSibling);

	return (child > sibling ? child : sibling);
}

int PCSTree::GetDepth() const
{
	return this->GetDepth(root.child);
}

//SERIALIZATION
void PCSTree::RecursiveSerialize(PCSNode* node, const PCSSerializer* serializer, PCSSerialNode* list, int index)
{
	list[index] = serializer->serialize(node);
	
	//loop to last child so that we can add nodes in reverse order
	PCSNode* child = node->GetChild();
	if (child != nullptr)
	{
		while (child->GetNextSibling() != nullptr)
		{
			child = child->GetNextSibling();
		}

		//start recursively adding children
		while (child != nullptr)
		{
			RecursiveSerialize(child, serializer, list, index+1);
			child = child->GetPrevSibling();
		}
	}
}

//same as PCSSerialNode except without a buffer ptr.
//made for easier memcpy
struct HelperSerialNode
{
	int size;
	int num_children;
	HelperSerialNode(PCSSerialNode& node) 
		: size(node.size), num_children(node.num_children)
	{}
};

PCSSerialNode PCSTree::Serialize(const PCSSerializer* serializer)
{
	PCSSerialNode* list = new PCSSerialNode[this->numNodes];
	RecursiveSerialize(&this->root, serializer, list, 0);

	//calculate total size for out_buffer;
	int total_size = sizeof(HelperSerialNode) * this->numNodes;
	for (int i = 0; i < this->numNodes; i++)
	{
		total_size += list[i].size;
	}

	//turn list into large buffer
	char *buffer = new char[total_size]; //this will probably leak
	int offset = 0;
	for (int i = 0; i < this->numNodes; i++)
	{
		PCSSerialNode& node = list[i];
		HelperSerialNode helper(node);
		
		memcpy(buffer + offset, &helper, sizeof(helper));
		offset += sizeof(HelperSerialNode);

		memcpy(buffer + offset, node.buffer, node.size);
		offset += node.size;
		
		delete[] node.buffer; //don't forget to cleanup;
	}

	delete[] list;

	PCSSerialNode serialNode;
	serialNode.num_children = 0;
	serialNode.buffer = buffer;
	serialNode.size = total_size;
	return serialNode;
}

int PCSTree::RecursiveDeserialize(const char* buffer, PCSNode* parent, const PCSSerializer* serializer)
{
	PCSSerialNode header;
	memcpy(&header, buffer, sizeof(HelperSerialNode));
	int offset = sizeof(HelperSerialNode);
	header.buffer = buffer + offset;
	offset += header.size;

	PCSNode *node = serializer->deserialize(header); //where deserialization actually happens

	Insert(node, parent); //insert into tree

	for (int i = 0; i < header.num_children; i++)
	{
		offset += RecursiveDeserialize(buffer + offset, node, serializer);
	}

	return offset;
}

void PCSTree::Deserialize(const char* buffer_in, const PCSSerializer* serializer)
{
	RecursiveDeserialize(buffer_in, nullptr, serializer);
}

