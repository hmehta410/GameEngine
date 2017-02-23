#ifndef PCS_SERIALIZER_H
#define PCS_SERIALIZER_H
#include "PCSNode.h"

struct PCSSerialNode
{
	int size; //size in bytes
	int num_children;
	const char* buffer;
};

class PCSSerializer
{
public:
	virtual PCSSerialNode serialize(PCSNode* node) const = 0;
	virtual PCSNode* deserialize(const PCSSerialNode& buffer) const = 0;
};

//Example Usage
//class GameObjectSerializer : public PCSSerializer
//{
//public:
//	virtual PCSSerialNode serialize(PCSNode* node) const override
//	{
//		node;
//		//return node->serialize(); //can use polymorphism to serialize different types of nodes
//	}
//
//	virtual PCSNode* deserialize(const PCSSerialNode& serialNode) const override
//	{		
//		//read header
//		GameObjectHeader header;
//		memcpy(&header, serialNode.buffer, sizeof(GameObjectHeader))
//
//		deserialize type
//		if(header.type == alien)
//		{
//			Alien al = new Alien();
//			al.deserialize(serialNode.buffer);
//			return al;
//		}
//		if(header.type == player)
//		{
//			Player player = new Player();
//			palyer.deserialize(serialNode.buffer);
//			return player;
//		}
//		
//	}
//};
#endif