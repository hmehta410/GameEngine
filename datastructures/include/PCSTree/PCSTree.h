#ifndef PCSTREE_H
#define PCSTREE_H

#include "PCSSerializer.h"
#include "PCSNode.h"
#include "List\LinkedIterator.h"

// forward declare
class PCSNode;

// PCSTree class 
class PCSTree
{
public:
	PCSTree();
	PCSTree(PCSTree&& in);
	PCSTree(const PCSTree &in) = delete;
	PCSTree& operator=(PCSTree&& in);
	PCSTree & operator=(const PCSTree &in) = delete;
	~PCSTree();
	
	LinkedIterator GetIterator() { return LinkedIterator(*this); };
	LinkedReverseIterator GetReverseIterator() { return LinkedReverseIterator(*this); };
	
	void Insert(PCSNode * const inNode, PCSNode * const parent = nullptr);
	void Remove(PCSNode * const inNode);
	PCSTree Split(PCSNode* inNode);
	void DeleteSubtree(PCSNode * const inNode);

	void DeleteTree();
	
	PCSSerialNode Serialize(const PCSSerializer* serializer);
	void Deserialize(const char* buffer_in, const PCSSerializer* serializer);

	const PCSNode* GetRoot() const { return &root; }
	int GetDepth() const;
	int GetSize() const { return numNodes; }

private:
   // Data   
	PCSNode root;
	int numNodes;

	void RecursiveRemove(PCSNode* inNode); 
	void RecursiveDelete(PCSNode* inNode);
	int GetDepth(PCSNode* inNode) const;
	void RecursiveSerialize(PCSNode* node, const PCSSerializer* serializer, PCSSerialNode* list, int index);
	int RecursiveDeserialize(const char* buffer, PCSNode* parent, const PCSSerializer* serializer);
};



#endif