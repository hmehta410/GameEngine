#pragma once
#include "ComponentHandleBase.h"
#include "List\Link.h"

/*
These two nodes will make up two corresponding lists : 
	DList dependants;
	DList requirements;

If node A (Graphics) depends on node B (Transform)
	then A is a dependant
	and B is a requirement
	
	node A will have an empty dependants list and one node in the requirement list.
	node B will have one node in the dependants list and an empty requirements list.

	Since node A has nobody depending on it, it can be deleted at the end of the 
		frame but it can't forget to tell node B to clear node A from its dependants list.
		Luckily we have the direct dependant node link in the requirement node. 
		So removal can be O(1)
*/

class DependantNode : public DLink
{
public:
	ComponentHandleBase* dependant;
};

class RequirementNode : public DLink
{
public:
	DependantNode dependantNode; //keeping the reference here merely helps with O(1) removal
	ComponentHandleBase* requirement;
};