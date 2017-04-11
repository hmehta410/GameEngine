#pragma once
#include "PCSTree/PCSTree.h"

//templated version of PCSTree. T is still required to inherit from PCSNode
template <typename T>
class Tree
{
public:
	Tree() {};
	Tree(Tree&& in);
	Tree(const Tree &in) = delete;
	Tree& operator=(Tree&& in);
	Tree & operator=(const Tree &in) = delete;

	ForwardIterator<T> GetIterator() { return ForwardIterator<T>(tree); };
	ReverseIterator<T> GetReverseIterator() { return ReverseIterator<T>(tree); };

	void Insert(T * const inNode, T * const parent = nullptr)
	{
		tree.Insert(inNode, parent);
	}

	void Remove(T * const inNode) { tree.Remove(inNode); }
	Tree<T> Split(T* inNode) { return tree.Split(inNode); }
	void DeleteSubtree(T * const inNode) { tree.DeleteSubtree(inNode); }

	void DeleteTree() { tree.DeleteTree(); }

	PCSSerialNode Serialize(const PCSSerializer* serializer) { 
		return tree.Serialize(serializer); 
	}
	void Deserialize(const char* buffer_in, const PCSSerializer* serializer) { 
		tree.Deserialize(serializer); 
	}

	template <typename Function>
	void Apply(Function& function)
	{	
		LinkedIterator it  = GetIterator();
		for (Link* link = it.First(); !it.IsDone(); link = it.Next())
		{
			T* element = (T*)link;
			function(*element);
		}
	}

	const PCSNode* GetRoot() const { return tree.GetRoot(); }
	int GetDepth() const {	return tree.GetDepth(); }
	int GetSize() const { return tree.GetSize(); }
private:
	PCSTree tree;
};