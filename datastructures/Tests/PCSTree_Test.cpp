//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include <string.h>
#include "catch.hpp"
#include "PCSTree\PCSTree.h"
#include "PCSTree\PCSNode.h"

// Modifying any Unit Test to alter the outcome results is also an Academic Integrity Violation

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_CASE("constructor", "PCSTree_group")
{
	PCSTree tree;

	REQUIRE(tree.GetDepth() == 0);
	REQUIRE(tree.GetSize() == 0);
}

TEST_CASE("addNodeRoot", "PCSTree_group")
{
	PCSTree tree;
	
	PCSNode nodeRoot;

	REQUIRE(nodeRoot.GetChild() == 0);
	REQUIRE(nodeRoot.GetParent() == 0);
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	
	tree.insert(&nodeRoot, nullptr);

	REQUIRE(nodeRoot.GetChild() == 0);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);	
 
	REQUIRE(tree.GetDepth() == 1);
	REQUIRE(tree.GetSize() == 1);
}

TEST_CASE("addNodeRootA", "PCSTree_group")
{
	PCSTree tree;
	
	PCSNode nodeRoot;
	PCSNode nodeA;

	REQUIRE(nodeRoot.GetChild() == 0);
	REQUIRE(nodeRoot.GetParent() == 0);
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	
	tree.insert(&nodeRoot, nullptr);

	
  	REQUIRE(tree.GetDepth() == 1);
	REQUIRE(tree.GetSize() == 1);

	tree.insert(&nodeA, &nodeRoot);

	
  	REQUIRE(tree.GetDepth() == 2);
	REQUIRE(tree.GetSize() == 2);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);
}

TEST_CASE("addNodeRootAD", "PCSTree_group")
{
	PCSTree tree;
	
	
	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeD;

	REQUIRE(nodeRoot.GetChild() == 0);
	REQUIRE(nodeRoot.GetParent() == 0);
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	
	tree.insert(&nodeRoot, nullptr);
	
  	REQUIRE(tree.GetDepth() == 1);
	REQUIRE(tree.GetSize() == 1);

	tree.insert(&nodeA, &nodeRoot);

	
  	REQUIRE(tree.GetDepth() == 2);
	REQUIRE(tree.GetSize() == 2);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	tree.insert(&nodeD, &nodeA);

	
  	REQUIRE(tree.GetDepth() == 3);
	REQUIRE(tree.GetSize() == 3);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);
}

TEST_CASE("addNodeRootADF", "PCSTree_group")
{
	PCSTree tree;
	
	
	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeD;
	PCSNode nodeF;

	REQUIRE(nodeRoot.GetChild() == 0);
	REQUIRE(nodeRoot.GetParent() == 0);
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	
	tree.insert(&nodeRoot, nullptr);

	
  	REQUIRE(tree.GetDepth() == 1);
	REQUIRE(tree.GetSize() == 1);

	tree.insert(&nodeA, &nodeRoot);

	
  	REQUIRE(tree.GetDepth() == 2);
	REQUIRE(tree.GetSize() == 2);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	tree.insert(&nodeD, &nodeA);

	
  	REQUIRE(tree.GetDepth() == 3);
	REQUIRE(tree.GetSize() == 3);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	tree.insert(&nodeF, &nodeD);

	
  	REQUIRE(tree.GetDepth() == 4);
	REQUIRE(tree.GetSize() == 4);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);
}

TEST_CASE("addNodeRootADFH", "PCSTree_group")
{
	PCSTree tree;
	
	
	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeD;
	PCSNode nodeF;
	PCSNode nodeH;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeH, &nodeF);

	
 
 
	REQUIRE(tree.GetDepth() == 5);
	REQUIRE(tree.GetSize() == 5);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);
}

TEST_CASE("addNodeRootAB", "PCSTree_group")
{
	PCSTree tree;
	
	
	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;

	
	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeB, &nodeRoot);

	
 
 
	REQUIRE(tree.GetDepth() == 2);
	REQUIRE(tree.GetSize() == 2);

	REQUIRE(nodeRoot.GetChild() == &nodeB);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	tree.insert(&nodeA, &nodeRoot);

	REQUIRE(tree.GetDepth() == 2);
	REQUIRE(tree.GetSize() == 3);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);
}

TEST_CASE("addNodeRootABC", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);

	
 
 
	REQUIRE(tree.GetDepth() == 2);
	REQUIRE(tree.GetSize() == 2);

	REQUIRE(nodeRoot.GetChild() == &nodeC);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	tree.insert(&nodeB, &nodeRoot);

	
 
 
	REQUIRE(tree.GetDepth() == 2);
	REQUIRE(tree.GetSize() == 3);

	REQUIRE(nodeRoot.GetChild() == &nodeB);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	tree.insert(&nodeA, &nodeRoot);

	
 
 
	REQUIRE(tree.GetDepth() == 2);
	REQUIRE(tree.GetSize() == 4);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);
}

TEST_CASE("addNodeRootABCDEI", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);

	
 
 
	REQUIRE(tree.GetDepth() == 3);
	REQUIRE(tree.GetSize() == 7);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);
}

TEST_CASE("addNodeRootABCDEIKL", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);

	
 
 
	REQUIRE(tree.GetDepth() == 3);
	REQUIRE(tree.GetSize() == 9);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);
}

TEST_CASE("addNodeRootABCDEIKLR", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);

	
 
 
	REQUIRE(tree.GetDepth() == 3);
	REQUIRE(tree.GetSize() == 10);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);
}

TEST_CASE("addNodeRootABCDEIKLRF", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);

	
 
 
	REQUIRE(tree.GetDepth() == 4);
	REQUIRE(tree.GetSize() == 11);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);
}

TEST_CASE("addNodeRootABCDEIKLRFGJ", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);

	
 
 
	REQUIRE(tree.GetDepth() == 4);
	REQUIRE(tree.GetSize() == 13);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);
}

TEST_CASE("addNodeRootABCDEIKLRFGJMN", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);

	
 
 
	REQUIRE(tree.GetDepth() == 4);
	REQUIRE(tree.GetSize() == 15);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);
}

TEST_CASE("addNodeRootABCDEIKLRFGJMNOPQ", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);

	
 
 
	REQUIRE(tree.GetDepth() == 4);
	REQUIRE(tree.GetSize() == 18);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);
}

TEST_CASE("addNodeRootABCDEIKLRFGJMNOPQH", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);

	
 
 
	REQUIRE(tree.GetDepth() == 5);
	REQUIRE(tree.GetSize() == 19);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);
}

TEST_CASE("addNodeRootABCDEIKLRFGJMNOPQHS", "PCSTree_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);

	
 
 
	REQUIRE(tree.GetDepth() == 5);
	REQUIRE(tree.GetSize() == 20);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);
}

TEST_CASE("addNodeRootABCDEIKLRFGJMNOPQHSTUVW", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveW", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove W
	tree.remove(&nodeW);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);
}

TEST_CASE("fullTree_RemoveV", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove V
	tree.remove(&nodeV);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeW);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeU);
}

TEST_CASE("fullTree_RemoveU", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove U
	tree.remove(&nodeU);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeV);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeT);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveT", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove T
	tree.remove(&nodeT);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeU);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveH", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove H
	tree.remove(&nodeH);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveQ", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove Q
	tree.remove(&nodeQ);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == 0);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == 0);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == 0);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveO", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove O
	tree.remove(&nodeO);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeP);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == 0);
	REQUIRE(nodeO.GetNextSibling() == 0);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == 0);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveK", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove K
	tree.remove(&nodeK);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeL);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveM", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove M
	tree.remove(&nodeM);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeN);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveN", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove N
	tree.remove(&nodeN);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveJ", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove J
	tree.remove(&nodeJ);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveG", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove G
	tree.remove(&nodeG);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeJ);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveE", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove E
	tree.remove(&nodeE);

	
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 23);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeI);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeD);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveF", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove F
	tree.remove(&nodeF);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 22);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveD", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);
	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove D
	tree.remove(&nodeD);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 21);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeE);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveI", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);


	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);
	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove I
	tree.remove(&nodeI);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 21);
	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveL", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);


	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove L
	tree.remove(&nodeL);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 21);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveS", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
	// Remove S
	tree.remove(&nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 5);
	REQUIRE(tree.GetSize() == 19);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);
}

TEST_CASE("fullTree_RemoveP", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);
	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove P
	tree.remove(&nodeP);

	

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeQ);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == 0);
	REQUIRE(nodeP.GetNextSibling() == 0);
	REQUIRE(nodeP.GetPrevSibling() == 0);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeO);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);
}

TEST_CASE("fullTree_RemoveR", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove R
	tree.remove(&nodeR);

	

 
 
	REQUIRE(tree.GetDepth() == 5);
	REQUIRE(tree.GetSize() == 15);
	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == 0);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == 0);
	REQUIRE(nodeO.GetNextSibling() == 0);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == 0);
	REQUIRE(nodeP.GetNextSibling() == 0);
	REQUIRE(nodeP.GetPrevSibling() == 0);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == 0);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == 0);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);
}

TEST_CASE("fullTree_RemoveC", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);
	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove C
	tree.remove(&nodeC);

	

 
 
	REQUIRE(tree.GetDepth() == 5);
	REQUIRE(tree.GetSize() == 14);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == 0);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == 0);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == 0);
	REQUIRE(nodeO.GetNextSibling() == 0);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == 0);
	REQUIRE(nodeP.GetNextSibling() == 0);
	REQUIRE(nodeP.GetPrevSibling() == 0);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == 0);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == 0);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);
}

TEST_CASE("fullTree_RemoveB", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);
	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove B
	tree.remove(&nodeB);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 19);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeC);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == 0);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeA);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveA", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// Remove A
	tree.remove(&nodeA);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 16);

	REQUIRE(nodeRoot.GetChild() == &nodeB);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == 0);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);
}

TEST_CASE("fullTree_RemoveRoot", "PCSTree_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;
	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// RemoveROOT
	tree.remove(&nodeRoot);
	

 
 
	REQUIRE(tree.GetDepth() == 0);
	REQUIRE(tree.GetSize() == 0);

	REQUIRE(nodeRoot.GetChild() == 0);
	REQUIRE(nodeRoot.GetParent() == 0);
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == 0);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == 0);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == 0);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == 0);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == 0);
	REQUIRE(nodeO.GetNextSibling() == 0);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == 0);
	REQUIRE(nodeP.GetNextSibling() == 0);
	REQUIRE(nodeP.GetPrevSibling() == 0);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == 0);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == 0);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);
}

TEST_CASE("fullTree_printTree", "PCSNode_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	// print the entire tree
	//tree.printTree();

}

TEST_CASE("fullTree_CheckLevels_C_children", "PCSNode_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	tree.remove(&nodeA);
	tree.remove(&nodeB);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 11);

	REQUIRE(nodeRoot.GetChild() == &nodeC);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == 0);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == 0);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

}

TEST_CASE("fullTree_CheckLevels_C_children_remove_TUVW", "PCSNode_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);
	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);


	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeT);
	tree.remove(&nodeU);
	tree.remove(&nodeV);
	tree.remove(&nodeW);

	

 
 
	REQUIRE(tree.GetDepth() == 5);
	REQUIRE(tree.GetSize() == 7);

	REQUIRE(nodeRoot.GetChild() == &nodeC);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == 0);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == 0);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);

}

TEST_CASE("fullTree_CheckLevels_C_children_remove_S", "PCSNode_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 4);
	REQUIRE(tree.GetSize() == 6);

	REQUIRE(nodeRoot.GetChild() == &nodeC);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == 0);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == 0);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);


}

TEST_CASE("fullTree_CheckLevels_C_children_remove_OPQ", "PCSNode_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	
	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeO);
	tree.remove(&nodeP);
	tree.remove(&nodeQ);

	

 
 
	REQUIRE(tree.GetDepth() == 3);
	REQUIRE(tree.GetSize() == 3);

	REQUIRE(nodeRoot.GetChild() == &nodeC);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == 0);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == 0);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == 0);
	REQUIRE(nodeO.GetNextSibling() == 0);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == 0);
	REQUIRE(nodeP.GetNextSibling() == 0);
	REQUIRE(nodeP.GetPrevSibling() == 0);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == 0);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == 0);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);

}

TEST_CASE("fullTree_CheckLevels_C_children_remove_R", "PCSNode_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeR);

	

 
 
	REQUIRE(tree.GetDepth() == 2);
	REQUIRE(tree.GetSize() == 2);

	REQUIRE(nodeRoot.GetChild() == &nodeC);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == 0);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == 0);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == 0);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == 0);
	REQUIRE(nodeO.GetNextSibling() == 0);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == 0);
	REQUIRE(nodeP.GetNextSibling() == 0);
	REQUIRE(nodeP.GetPrevSibling() == 0);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == 0);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == 0);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);

}

TEST_CASE("fullTree_CheckLevels_C_children_remove_C", "PCSNode_group")
{
	PCSTree tree;
	
	

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	

 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);


	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeC);

	

 
 
	REQUIRE(tree.GetDepth() == 1);
	REQUIRE(tree.GetSize() == 1);

	REQUIRE(nodeRoot.GetChild() == 0);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == 0);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == 0);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == 0);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == 0);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == 0);
	REQUIRE(nodeO.GetNextSibling() == 0);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == 0);
	REQUIRE(nodeP.GetNextSibling() == 0);
	REQUIRE(nodeP.GetPrevSibling() == 0);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == 0);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == 0);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);
}

TEST_CASE("fullTree_CheckLevels_C_children_remove_root", "PCSNode_group")
{
	PCSTree tree;

	PCSNode nodeRoot;
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	PCSNode nodeE;
	PCSNode nodeI;
	PCSNode nodeK;
	PCSNode nodeL;
	PCSNode nodeR;
	PCSNode nodeF;
	PCSNode nodeG;
	PCSNode nodeJ;
	PCSNode nodeM;
	PCSNode nodeN;
	PCSNode nodeO;
	PCSNode nodeP;
	PCSNode nodeQ;
	PCSNode nodeH;
	PCSNode nodeS;
	PCSNode nodeT;
	PCSNode nodeU;
	PCSNode nodeV;
	PCSNode nodeW;

	

	tree.insert(&nodeRoot, nullptr);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);
 
 
	REQUIRE(tree.GetDepth() == 6);
	REQUIRE(tree.GetSize() == 24);

	REQUIRE(nodeRoot.GetChild() == &nodeA);
	REQUIRE(nodeRoot.GetParent() == tree.GetRoot());
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == &nodeD);
	REQUIRE(nodeA.GetParent() == &nodeRoot);
	REQUIRE(nodeA.GetNextSibling() == &nodeB);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == &nodeK);
	REQUIRE(nodeB.GetParent() == &nodeRoot);
	REQUIRE(nodeB.GetNextSibling() == &nodeC);
	REQUIRE(nodeB.GetPrevSibling() == &nodeA);

	REQUIRE(nodeC.GetChild() == &nodeR);
	REQUIRE(nodeC.GetParent() == &nodeRoot);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == &nodeB);

	REQUIRE(nodeD.GetChild() == &nodeF);
	REQUIRE(nodeD.GetParent() == &nodeA);
	REQUIRE(nodeD.GetNextSibling() == &nodeE);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == &nodeA);
	REQUIRE(nodeE.GetNextSibling() == &nodeI);
	REQUIRE(nodeE.GetPrevSibling() == &nodeD);

	REQUIRE(nodeI.GetChild() == &nodeG);
	REQUIRE(nodeI.GetParent() == &nodeA);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == &nodeE);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == &nodeB);
	REQUIRE(nodeK.GetNextSibling() == &nodeL);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == &nodeM);
	REQUIRE(nodeL.GetParent() == &nodeB);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == &nodeK);

	REQUIRE(nodeR.GetChild() == &nodeO);
	REQUIRE(nodeR.GetParent() == &nodeC);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == &nodeH);
	REQUIRE(nodeF.GetParent() == &nodeD);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == &nodeI);
	REQUIRE(nodeG.GetNextSibling() == &nodeJ);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == &nodeI);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == &nodeG);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == &nodeL);
	REQUIRE(nodeM.GetNextSibling() == &nodeN);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == &nodeL);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == &nodeM);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == &nodeR);
	REQUIRE(nodeO.GetNextSibling() == &nodeP);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == &nodeS);
	REQUIRE(nodeP.GetParent() == &nodeR);
	REQUIRE(nodeP.GetNextSibling() == &nodeQ);
	REQUIRE(nodeP.GetPrevSibling() == &nodeO);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == &nodeR);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == &nodeP);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == &nodeF);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == &nodeT);
	REQUIRE(nodeS.GetParent() == &nodeP);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == &nodeS);
	REQUIRE(nodeT.GetNextSibling() == &nodeU);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == &nodeS);
	REQUIRE(nodeU.GetNextSibling() == &nodeV);
	REQUIRE(nodeU.GetPrevSibling() == &nodeT);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == &nodeS);
	REQUIRE(nodeV.GetNextSibling() == &nodeW);
	REQUIRE(nodeV.GetPrevSibling() == &nodeU);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == &nodeS);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == &nodeV);

	tree.remove(&nodeRoot);
	

 
 
	REQUIRE(tree.GetDepth() == 0);
	REQUIRE(tree.GetSize() == 0);

	REQUIRE(nodeRoot.GetChild() == 0);
	REQUIRE(nodeRoot.GetParent() == 0);
	REQUIRE(nodeRoot.GetNextSibling() == 0);
	REQUIRE(nodeRoot.GetPrevSibling() == 0);

	REQUIRE(nodeA.GetChild() == 0);
	REQUIRE(nodeA.GetParent() == 0);
	REQUIRE(nodeA.GetNextSibling() == 0);
	REQUIRE(nodeA.GetPrevSibling() == 0);

	REQUIRE(nodeB.GetChild() == 0);
	REQUIRE(nodeB.GetParent() == 0);
	REQUIRE(nodeB.GetNextSibling() == 0);
	REQUIRE(nodeB.GetPrevSibling() == 0);

	REQUIRE(nodeC.GetChild() == 0);
	REQUIRE(nodeC.GetParent() == 0);
	REQUIRE(nodeC.GetNextSibling() == 0);
	REQUIRE(nodeC.GetPrevSibling() == 0);

	REQUIRE(nodeD.GetChild() == 0);
	REQUIRE(nodeD.GetParent() == 0);
	REQUIRE(nodeD.GetNextSibling() == 0);
	REQUIRE(nodeD.GetPrevSibling() == 0);

	REQUIRE(nodeE.GetChild() == 0);
	REQUIRE(nodeE.GetParent() == 0);
	REQUIRE(nodeE.GetNextSibling() == 0);
	REQUIRE(nodeE.GetPrevSibling() == 0);

	REQUIRE(nodeI.GetChild() == 0);
	REQUIRE(nodeI.GetParent() == 0);
	REQUIRE(nodeI.GetNextSibling() == 0);
	REQUIRE(nodeI.GetPrevSibling() == 0);

	REQUIRE(nodeK.GetChild() == 0);
	REQUIRE(nodeK.GetParent() == 0);
	REQUIRE(nodeK.GetNextSibling() == 0);
	REQUIRE(nodeK.GetPrevSibling() == 0);

	REQUIRE(nodeL.GetChild() == 0);
	REQUIRE(nodeL.GetParent() == 0);
	REQUIRE(nodeL.GetNextSibling() == 0);
	REQUIRE(nodeL.GetPrevSibling() == 0);

	REQUIRE(nodeR.GetChild() == 0);
	REQUIRE(nodeR.GetParent() == 0);
	REQUIRE(nodeR.GetNextSibling() == 0);
	REQUIRE(nodeR.GetPrevSibling() == 0);

	REQUIRE(nodeF.GetChild() == 0);
	REQUIRE(nodeF.GetParent() == 0);
	REQUIRE(nodeF.GetNextSibling() == 0);
	REQUIRE(nodeF.GetPrevSibling() == 0);

	REQUIRE(nodeG.GetChild() == 0);
	REQUIRE(nodeG.GetParent() == 0);
	REQUIRE(nodeG.GetNextSibling() == 0);
	REQUIRE(nodeG.GetPrevSibling() == 0);

	REQUIRE(nodeJ.GetChild() == 0);
	REQUIRE(nodeJ.GetParent() == 0);
	REQUIRE(nodeJ.GetNextSibling() == 0);
	REQUIRE(nodeJ.GetPrevSibling() == 0);

	REQUIRE(nodeM.GetChild() == 0);
	REQUIRE(nodeM.GetParent() == 0);
	REQUIRE(nodeM.GetNextSibling() == 0);
	REQUIRE(nodeM.GetPrevSibling() == 0);

	REQUIRE(nodeN.GetChild() == 0);
	REQUIRE(nodeN.GetParent() == 0);
	REQUIRE(nodeN.GetNextSibling() == 0);
	REQUIRE(nodeN.GetPrevSibling() == 0);

	REQUIRE(nodeO.GetChild() == 0);
	REQUIRE(nodeO.GetParent() == 0);
	REQUIRE(nodeO.GetNextSibling() == 0);
	REQUIRE(nodeO.GetPrevSibling() == 0);

	REQUIRE(nodeP.GetChild() == 0);
	REQUIRE(nodeP.GetParent() == 0);
	REQUIRE(nodeP.GetNextSibling() == 0);
	REQUIRE(nodeP.GetPrevSibling() == 0);

	REQUIRE(nodeQ.GetChild() == 0);
	REQUIRE(nodeQ.GetParent() == 0);
	REQUIRE(nodeQ.GetNextSibling() == 0);
	REQUIRE(nodeQ.GetPrevSibling() == 0);

	REQUIRE(nodeH.GetChild() == 0);
	REQUIRE(nodeH.GetParent() == 0);
	REQUIRE(nodeH.GetNextSibling() == 0);
	REQUIRE(nodeH.GetPrevSibling() == 0);

	REQUIRE(nodeS.GetChild() == 0);
	REQUIRE(nodeS.GetParent() == 0);
	REQUIRE(nodeS.GetNextSibling() == 0);
	REQUIRE(nodeS.GetPrevSibling() == 0);

	REQUIRE(nodeT.GetChild() == 0);
	REQUIRE(nodeT.GetParent() == 0);
	REQUIRE(nodeT.GetNextSibling() == 0);
	REQUIRE(nodeT.GetPrevSibling() == 0);

	REQUIRE(nodeU.GetChild() == 0);
	REQUIRE(nodeU.GetParent() == 0);
	REQUIRE(nodeU.GetNextSibling() == 0);
	REQUIRE(nodeU.GetPrevSibling() == 0);

	REQUIRE(nodeV.GetChild() == 0);
	REQUIRE(nodeV.GetParent() == 0);
	REQUIRE(nodeV.GetNextSibling() == 0);
	REQUIRE(nodeV.GetPrevSibling() == 0);

	REQUIRE(nodeW.GetChild() == 0);
	REQUIRE(nodeW.GetParent() == 0);
	REQUIRE(nodeW.GetNextSibling() == 0);
	REQUIRE(nodeW.GetPrevSibling() == 0);
}
