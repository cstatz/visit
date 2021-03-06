// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <InverseGhostZoneAttributes.h>
#include <DataNode.h>

// ****************************************************************************
// Method: InverseGhostZoneAttributes::InverseGhostZoneAttributes
//
// Purpose:
//   Init utility for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void InverseGhostZoneAttributes::Init()
{
    requestGhostZones = true;
    showDuplicated = true;
    showEnhancedConnectivity = true;
    showReducedConnectivity = true;
    showAMRRefined = true;
    showExterior = true;
    showNotApplicable = true;

    InverseGhostZoneAttributes::SelectAll();
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::InverseGhostZoneAttributes
//
// Purpose:
//   Copy utility for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void InverseGhostZoneAttributes::Copy(const InverseGhostZoneAttributes &obj)
{
    requestGhostZones = obj.requestGhostZones;
    showDuplicated = obj.showDuplicated;
    showEnhancedConnectivity = obj.showEnhancedConnectivity;
    showReducedConnectivity = obj.showReducedConnectivity;
    showAMRRefined = obj.showAMRRefined;
    showExterior = obj.showExterior;
    showNotApplicable = obj.showNotApplicable;

    InverseGhostZoneAttributes::SelectAll();
}

// Type map format string
const char *InverseGhostZoneAttributes::TypeMapFormatString = INVERSEGHOSTZONEATTRIBUTES_TMFS;
const AttributeGroup::private_tmfs_t InverseGhostZoneAttributes::TmfsStruct = {INVERSEGHOSTZONEATTRIBUTES_TMFS};


// ****************************************************************************
// Method: InverseGhostZoneAttributes::InverseGhostZoneAttributes
//
// Purpose:
//   Default constructor for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

InverseGhostZoneAttributes::InverseGhostZoneAttributes() :
    AttributeSubject(InverseGhostZoneAttributes::TypeMapFormatString)
{
    InverseGhostZoneAttributes::Init();
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::InverseGhostZoneAttributes
//
// Purpose:
//   Constructor for the derived classes of InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

InverseGhostZoneAttributes::InverseGhostZoneAttributes(private_tmfs_t tmfs) :
    AttributeSubject(tmfs.tmfs)
{
    InverseGhostZoneAttributes::Init();
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::InverseGhostZoneAttributes
//
// Purpose:
//   Copy constructor for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

InverseGhostZoneAttributes::InverseGhostZoneAttributes(const InverseGhostZoneAttributes &obj) :
    AttributeSubject(InverseGhostZoneAttributes::TypeMapFormatString)
{
    InverseGhostZoneAttributes::Copy(obj);
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::InverseGhostZoneAttributes
//
// Purpose:
//   Copy constructor for derived classes of the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

InverseGhostZoneAttributes::InverseGhostZoneAttributes(const InverseGhostZoneAttributes &obj, private_tmfs_t tmfs) :
    AttributeSubject(tmfs.tmfs)
{
    InverseGhostZoneAttributes::Copy(obj);
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::~InverseGhostZoneAttributes
//
// Purpose:
//   Destructor for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

InverseGhostZoneAttributes::~InverseGhostZoneAttributes()
{
    // nothing here
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::operator =
//
// Purpose:
//   Assignment operator for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

InverseGhostZoneAttributes&
InverseGhostZoneAttributes::operator = (const InverseGhostZoneAttributes &obj)
{
    if (this == &obj) return *this;

    InverseGhostZoneAttributes::Copy(obj);

    return *this;
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::operator ==
//
// Purpose:
//   Comparison operator == for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
InverseGhostZoneAttributes::operator == (const InverseGhostZoneAttributes &obj) const
{
    // Create the return value
    return ((requestGhostZones == obj.requestGhostZones) &&
            (showDuplicated == obj.showDuplicated) &&
            (showEnhancedConnectivity == obj.showEnhancedConnectivity) &&
            (showReducedConnectivity == obj.showReducedConnectivity) &&
            (showAMRRefined == obj.showAMRRefined) &&
            (showExterior == obj.showExterior) &&
            (showNotApplicable == obj.showNotApplicable));
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::operator !=
//
// Purpose:
//   Comparison operator != for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
InverseGhostZoneAttributes::operator != (const InverseGhostZoneAttributes &obj) const
{
    return !(this->operator == (obj));
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::TypeName
//
// Purpose:
//   Type name method for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

const std::string
InverseGhostZoneAttributes::TypeName() const
{
    return "InverseGhostZoneAttributes";
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::CopyAttributes
//
// Purpose:
//   CopyAttributes method for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
InverseGhostZoneAttributes::CopyAttributes(const AttributeGroup *atts)
{
    if(TypeName() != atts->TypeName())
        return false;

    // Call assignment operator.
    const InverseGhostZoneAttributes *tmp = (const InverseGhostZoneAttributes *)atts;
    *this = *tmp;

    return true;
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::CreateCompatible
//
// Purpose:
//   CreateCompatible method for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

AttributeSubject *
InverseGhostZoneAttributes::CreateCompatible(const std::string &tname) const
{
    AttributeSubject *retval = 0;
    if(TypeName() == tname)
        retval = new InverseGhostZoneAttributes(*this);
    // Other cases could go here too.

    return retval;
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::NewInstance
//
// Purpose:
//   NewInstance method for the InverseGhostZoneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

AttributeSubject *
InverseGhostZoneAttributes::NewInstance(bool copy) const
{
    AttributeSubject *retval = 0;
    if(copy)
        retval = new InverseGhostZoneAttributes(*this);
    else
        retval = new InverseGhostZoneAttributes;

    return retval;
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::SelectAll
//
// Purpose:
//   Selects all attributes.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void
InverseGhostZoneAttributes::SelectAll()
{
    Select(ID_requestGhostZones,        (void *)&requestGhostZones);
    Select(ID_showDuplicated,           (void *)&showDuplicated);
    Select(ID_showEnhancedConnectivity, (void *)&showEnhancedConnectivity);
    Select(ID_showReducedConnectivity,  (void *)&showReducedConnectivity);
    Select(ID_showAMRRefined,           (void *)&showAMRRefined);
    Select(ID_showExterior,             (void *)&showExterior);
    Select(ID_showNotApplicable,        (void *)&showNotApplicable);
}

///////////////////////////////////////////////////////////////////////////////
// Persistence methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: InverseGhostZoneAttributes::CreateNode
//
// Purpose:
//   This method creates a DataNode representation of the object so it can be saved to a config file.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
InverseGhostZoneAttributes::CreateNode(DataNode *parentNode, bool completeSave, bool forceAdd)
{
    if(parentNode == 0)
        return false;

    InverseGhostZoneAttributes defaultObject;
    bool addToParent = false;
    // Create a node for InverseGhostZoneAttributes.
    DataNode *node = new DataNode("InverseGhostZoneAttributes");

    if(completeSave || !FieldsEqual(ID_requestGhostZones, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("requestGhostZones", requestGhostZones));
    }

    if(completeSave || !FieldsEqual(ID_showDuplicated, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("showDuplicated", showDuplicated));
    }

    if(completeSave || !FieldsEqual(ID_showEnhancedConnectivity, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("showEnhancedConnectivity", showEnhancedConnectivity));
    }

    if(completeSave || !FieldsEqual(ID_showReducedConnectivity, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("showReducedConnectivity", showReducedConnectivity));
    }

    if(completeSave || !FieldsEqual(ID_showAMRRefined, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("showAMRRefined", showAMRRefined));
    }

    if(completeSave || !FieldsEqual(ID_showExterior, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("showExterior", showExterior));
    }

    if(completeSave || !FieldsEqual(ID_showNotApplicable, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("showNotApplicable", showNotApplicable));
    }


    // Add the node to the parent node.
    if(addToParent || forceAdd)
        parentNode->AddNode(node);
    else
        delete node;

    return (addToParent || forceAdd);
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::SetFromNode
//
// Purpose:
//   This method sets attributes in this object from values in a DataNode representation of the object.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void
InverseGhostZoneAttributes::SetFromNode(DataNode *parentNode)
{
    if(parentNode == 0)
        return;

    DataNode *searchNode = parentNode->GetNode("InverseGhostZoneAttributes");
    if(searchNode == 0)
        return;

    DataNode *node;
    if((node = searchNode->GetNode("requestGhostZones")) != 0)
        SetRequestGhostZones(node->AsBool());
    if((node = searchNode->GetNode("showDuplicated")) != 0)
        SetShowDuplicated(node->AsBool());
    if((node = searchNode->GetNode("showEnhancedConnectivity")) != 0)
        SetShowEnhancedConnectivity(node->AsBool());
    if((node = searchNode->GetNode("showReducedConnectivity")) != 0)
        SetShowReducedConnectivity(node->AsBool());
    if((node = searchNode->GetNode("showAMRRefined")) != 0)
        SetShowAMRRefined(node->AsBool());
    if((node = searchNode->GetNode("showExterior")) != 0)
        SetShowExterior(node->AsBool());
    if((node = searchNode->GetNode("showNotApplicable")) != 0)
        SetShowNotApplicable(node->AsBool());
}

///////////////////////////////////////////////////////////////////////////////
// Set property methods
///////////////////////////////////////////////////////////////////////////////

void
InverseGhostZoneAttributes::SetRequestGhostZones(bool requestGhostZones_)
{
    requestGhostZones = requestGhostZones_;
    Select(ID_requestGhostZones, (void *)&requestGhostZones);
}

void
InverseGhostZoneAttributes::SetShowDuplicated(bool showDuplicated_)
{
    showDuplicated = showDuplicated_;
    Select(ID_showDuplicated, (void *)&showDuplicated);
}

void
InverseGhostZoneAttributes::SetShowEnhancedConnectivity(bool showEnhancedConnectivity_)
{
    showEnhancedConnectivity = showEnhancedConnectivity_;
    Select(ID_showEnhancedConnectivity, (void *)&showEnhancedConnectivity);
}

void
InverseGhostZoneAttributes::SetShowReducedConnectivity(bool showReducedConnectivity_)
{
    showReducedConnectivity = showReducedConnectivity_;
    Select(ID_showReducedConnectivity, (void *)&showReducedConnectivity);
}

void
InverseGhostZoneAttributes::SetShowAMRRefined(bool showAMRRefined_)
{
    showAMRRefined = showAMRRefined_;
    Select(ID_showAMRRefined, (void *)&showAMRRefined);
}

void
InverseGhostZoneAttributes::SetShowExterior(bool showExterior_)
{
    showExterior = showExterior_;
    Select(ID_showExterior, (void *)&showExterior);
}

void
InverseGhostZoneAttributes::SetShowNotApplicable(bool showNotApplicable_)
{
    showNotApplicable = showNotApplicable_;
    Select(ID_showNotApplicable, (void *)&showNotApplicable);
}

///////////////////////////////////////////////////////////////////////////////
// Get property methods
///////////////////////////////////////////////////////////////////////////////

bool
InverseGhostZoneAttributes::GetRequestGhostZones() const
{
    return requestGhostZones;
}

bool
InverseGhostZoneAttributes::GetShowDuplicated() const
{
    return showDuplicated;
}

bool
InverseGhostZoneAttributes::GetShowEnhancedConnectivity() const
{
    return showEnhancedConnectivity;
}

bool
InverseGhostZoneAttributes::GetShowReducedConnectivity() const
{
    return showReducedConnectivity;
}

bool
InverseGhostZoneAttributes::GetShowAMRRefined() const
{
    return showAMRRefined;
}

bool
InverseGhostZoneAttributes::GetShowExterior() const
{
    return showExterior;
}

bool
InverseGhostZoneAttributes::GetShowNotApplicable() const
{
    return showNotApplicable;
}

///////////////////////////////////////////////////////////////////////////////
// Keyframing methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: InverseGhostZoneAttributes::GetFieldName
//
// Purpose:
//   This method returns the name of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

std::string
InverseGhostZoneAttributes::GetFieldName(int index) const
{
    switch (index)
    {
    case ID_requestGhostZones:        return "requestGhostZones";
    case ID_showDuplicated:           return "showDuplicated";
    case ID_showEnhancedConnectivity: return "showEnhancedConnectivity";
    case ID_showReducedConnectivity:  return "showReducedConnectivity";
    case ID_showAMRRefined:           return "showAMRRefined";
    case ID_showExterior:             return "showExterior";
    case ID_showNotApplicable:        return "showNotApplicable";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::GetFieldType
//
// Purpose:
//   This method returns the type of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

AttributeGroup::FieldType
InverseGhostZoneAttributes::GetFieldType(int index) const
{
    switch (index)
    {
    case ID_requestGhostZones:        return FieldType_bool;
    case ID_showDuplicated:           return FieldType_bool;
    case ID_showEnhancedConnectivity: return FieldType_bool;
    case ID_showReducedConnectivity:  return FieldType_bool;
    case ID_showAMRRefined:           return FieldType_bool;
    case ID_showExterior:             return FieldType_bool;
    case ID_showNotApplicable:        return FieldType_bool;
    default:  return FieldType_unknown;
    }
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::GetFieldTypeName
//
// Purpose:
//   This method returns the name of a field type given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

std::string
InverseGhostZoneAttributes::GetFieldTypeName(int index) const
{
    switch (index)
    {
    case ID_requestGhostZones:        return "bool";
    case ID_showDuplicated:           return "bool";
    case ID_showEnhancedConnectivity: return "bool";
    case ID_showReducedConnectivity:  return "bool";
    case ID_showAMRRefined:           return "bool";
    case ID_showExterior:             return "bool";
    case ID_showNotApplicable:        return "bool";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: InverseGhostZoneAttributes::FieldsEqual
//
// Purpose:
//   This method compares two fields and return true if they are equal.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
InverseGhostZoneAttributes::FieldsEqual(int index_, const AttributeGroup *rhs) const
{
    const InverseGhostZoneAttributes &obj = *((const InverseGhostZoneAttributes*)rhs);
    bool retval = false;
    switch (index_)
    {
    case ID_requestGhostZones:
        {  // new scope
        retval = (requestGhostZones == obj.requestGhostZones);
        }
        break;
    case ID_showDuplicated:
        {  // new scope
        retval = (showDuplicated == obj.showDuplicated);
        }
        break;
    case ID_showEnhancedConnectivity:
        {  // new scope
        retval = (showEnhancedConnectivity == obj.showEnhancedConnectivity);
        }
        break;
    case ID_showReducedConnectivity:
        {  // new scope
        retval = (showReducedConnectivity == obj.showReducedConnectivity);
        }
        break;
    case ID_showAMRRefined:
        {  // new scope
        retval = (showAMRRefined == obj.showAMRRefined);
        }
        break;
    case ID_showExterior:
        {  // new scope
        retval = (showExterior == obj.showExterior);
        }
        break;
    case ID_showNotApplicable:
        {  // new scope
        retval = (showNotApplicable == obj.showNotApplicable);
        }
        break;
    default: retval = false;
    }

    return retval;
}

///////////////////////////////////////////////////////////////////////////////
// User-defined methods.
///////////////////////////////////////////////////////////////////////////////

