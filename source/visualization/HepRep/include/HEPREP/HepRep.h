//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef HEPREP_HEPREP_H
#define HEPREP_HEPREP_H 1

// Copyright 2000-2002, FreeHEP.

#include <string>
#include <vector>

// Include all other HepRep header files here for convenience
#include "HEPREP/HepRepAction.h"
#include "HEPREP/HepRepAttDef.h"
#include "HEPREP/HepRepAttribute.h"
#include "HEPREP/HepRepAttValue.h"
#include "HEPREP/HepRepConstants.h"
#include "HEPREP/HepRepDefinition.h"
#include "HEPREP/HepRepFactory.h"
#include "HEPREP/HepRepInstance.h"
#include "HEPREP/HepRepInstanceTree.h"
#include "HEPREP/HepRepIterator.h"
#include "HEPREP/HepRepIteratorListener.h"
#include "HEPREP/HepRepPoint.h"
#include "HEPREP/HepRepSelectFilter.h"
#include "HEPREP/HepRepTreeID.h"
#include "HEPREP/HepRepType.h"
#include "HEPREP/HepRepTypeTree.h"
#include "HEPREP/HepRepWriter.h"

namespace HEPREP {

class HepRepAction;
class HepRepInstanceTree;
class HepRepSelectFilter;
class HepRepType;
class HepRepTypeTree;

/**
 * The HepRep interface.
 *
 * Any of these methods may throw a UnsupportedOperationException in Java.
 *
 * This interface is NOT final yet.
 *
 * @author Mark Donszelmann
 */
class HepRep {

public: 
    /// Destructor.
    virtual ~HepRep() { /* nop */; }

    /**
     * Add a layer to the list of layers in this heprep.
     * The layer is added to the back of the list.
     *
     * @param layer name of layer to be added to the back of the list.
     */
    virtual bool addLayer(std::string layer) = 0;

    /**
     * Returns the list of layers.
     *
     * @return the known layer names, in the order back-to-front.
     */
    virtual std::vector<std::string>  * getLayerOrder() = 0;

    /**
     * Add a typetree to this heprep.
     *
     * @param typeTree to be added.
     * @return false only if the tree is written immediately to some stream.
     */
    virtual bool addTypeTree(HepRepTypeTree * typeTree) = 0;

    /**
     * Remove a typetree from this heprep.
     *
     * @param typeTree to be removed.
     */
    virtual void removeTypeTree(HepRepTypeTree * typeTree) = 0;

    /**
     * Returns the collection of all typetrees of this heprep.
     *
     * @return collection of HepRepTypeTrees.
     */
    virtual std::vector<HepRepTypeTree *>  * getTypeTrees() = 0;

    /**
     * Returns a named and versioned typetree.
     *
     * @param name name of the typetree.
     * @param version version of the typetree.
     * @return named and versioned HepRepTypeTree.
     */
    virtual HepRepTypeTree * getTypeTree(std::string name, std::string version) = 0;

    /**
     * Searches for a named type in any of the typetrees.
     * The first occurrence found is returned.
     *
     * @param name name of type.
     * @return named HepRepType.
     */
    virtual HepRepType * getType(std::string name) = 0;

    /**
     * Adds an instancetree to this heprep.
     *
     * @param instanceTree to be added.
     * @return false only if the tree is written immediately to some stream.
     */
    virtual bool addInstanceTree(HepRepInstanceTree * instanceTree) = 0;

    /**
     * Remove an instanectree from this heprep.
     *
     * @param instanceTree to be removed.
     */
    virtual void removeInstanceTree(HepRepInstanceTree * instanceTree) = 0;

    /**
     * Returns a collection of instancetrees.
     *
     * @return collection of HepRepInstanceTrees.
     */
    virtual std::vector<HepRepInstanceTree *>  * getInstanceTrees() = 0;

    /**
     * Returns a named and versioned instancetree.
     * FIXME: doc is incorrect here, should only return TOP of the tree. Filling
     * in should be done by getInstances calls.
     * <p>
     * This tree needs to be added to the heprep afterwards.
     *
     * @param name name of the instancetree.
     * @param version version of the instancetree.
     * @return HepRepIntanceTree
     */
    virtual HepRepInstanceTree * getInstanceTreeTop(std::string name, std::string version) = 0;

    /**
     * Returns a named and versioned instancetree for a list of typenames.
     * <p>
     * This tree needs to be added to the heprep afterwards.
     *
     * @param name name of the instancetree.
     * @param version version of the instancetree.
     * @param typeNames a list of typenames for which we need instancetrees.
     * @return HepRepIntanceTree
     */
    virtual HepRepInstanceTree * getInstances(std::string name, std::string version, std::vector<std::string>  typeNames) = 0;

    /**
     * Returns a named and versioned instancetree for a list of typenames
     * after executing some action and for specific filters.
     *
     * This tree needs to be added to the heprep afterwards.
     * <p>
     * The inversion effect of invertAtts depends on the values of
     * GetDrawAtts and GetNonDrawAtts as follows:
     * <UL>
     * <LI>GetDrawAtts	GetNonDrawAtts	effect of InvertAtts
     * <LI>FALSE		FALSE			all Attributes specified will be downloaded
     * <LI>TRUE		    FALSE			Draw Attributes specified will be omitted, NonDraw Attributes specified will be included
     * <LI>FALSE		TRUE			Draw Attributes specified will be included, NonDraw Attributes specified will be omitted
     * <LI>TRUE		    TRUE			all Attributes specified will be omitted
     * </UL>
     *
     * @param name name of the instancetree.
     * @param version version of the instancetree.
     * @param typeNames a list of typenames for which we need instancetrees.
     * @param actions execute this list of actions before returning.
     * @param getPoints include the HepRepPoints in the instance tree.
     * @param getDrawAtts include the Draw attributes in the instance tree.
     * @param getNonDrawAtts include the Non-Draw attributes in the instance tree.
     * @param invertAtts list of attributes to be included or not depending on getDrawAtts and getNonDrawAtts.
     * @return HepRepIntanceTree
     */
    virtual HepRepInstanceTree * getInstancesAfterAction(std::string name, std::string version, std::vector<std::string>  typeNames, std::vector<HepRepAction *>  actions, bool getPoints, bool getDrawAtts, bool getNonDrawAtts, std::vector<std::string>  invertAtts) = 0;

    /**
     * Returns last exception thrown and clears it. Useful for implementations without
     * exception handling.
     *
     * @return last exception and clears it.
     */
    virtual std::string checkForException() = 0;

    /**
     * Returns a deep copy of the heprep, with all its attached trees, where
     * instances are filtered using a HepRepSelectFilter.
     *
     * @param filter to be used for filtering instances.
     * @return copy of heprep.
     */
    virtual HepRep * copy(HepRepSelectFilter * filter = NULL) = 0;
}; // class
}; // namespace HEPREP
#endif /* ifndef HEPREP_HEPREP_H */
