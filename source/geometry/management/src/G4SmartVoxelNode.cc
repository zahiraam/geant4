// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4SmartVoxelNode.cc,v 1.2 1999/12/15 14:49:53 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// Class G4SmartVoxelNode
//
// Implementation
//

#include "G4SmartVoxelNode.hh"

// Return true if contents equal
//
// Preconditions:
//
// Node contents were entered in the same order
G4bool G4SmartVoxelNode::operator == (const G4SmartVoxelNode& v) const
{
    G4int maxNode=GetNoContained();
    if (maxNode==v.GetNoContained())
	{
	    for (G4int node=0;node<maxNode;node++)
		{
		    if (GetVolume(node)!=v.GetVolume(node))
			{
			    return false;
			}
		}
	    return true;
	}
    return false;
}










