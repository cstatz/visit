// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                                VTMParser.C                                //
// ************************************************************************* //

#include <VTMParser.h>
#include <vtkXMLDataElement.h>
#include <vtkXMLDataParser.h>

#include <FileFunctions.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

// ****************************************************************************
//  Method: VTMParser constructor
//
//  Programmer: Kathleen Biagas
//  Creation:   August 12, 2015
//
// ****************************************************************************

VTMParser::VTMParser() : fileName(), baseDir(), blockExtension(),
  blockFileNames(), groupPieceName(), groupNames(),
  blockPieceName(), blockNames(), groupIds(), blockName(), errorMessage()
{
    parser = NULL;
    nGroups = 0;
}


// ****************************************************************************
//  Method: VTMParser destructor
//
//  Programmer: Kathleen Biagas
//  Creation:   August 12, 2015
//
// ****************************************************************************

VTMParser::~VTMParser()
{
    groupIds.clear();
    blockNames.clear();
    groupNames.clear();
    blockFileNames.clear();
    if (parser)
    {
        parser->Delete();
        parser = NULL;
    }
}


// ****************************************************************************
//  Method: VTMParser::SetFileName
//
//  Purpose:
//    Set's the file that will be parsed.
//
//  Arguments:
//    fn        The file name.
//
//  Programmer: Kathleen Biagas
//  Creation:   August 12, 2015
//
// ****************************************************************************

void
VTMParser::SetFileName(const char *fn)
{
    fileName = fn;
    baseDir = FileFunctions::Dirname(fileName);
}


// ****************************************************************************
//  Method: VTMParser::GetBlockFileName
//
//  Return:
//      The file name for the block at given index.
//
//  Arguments:
//      index   The block index.
//
//  Programmer: Kathleen Biagas
//  Creation:   August 12, 2015
//
// ****************************************************************************

string &
VTMParser::GetBlockFileName(int index)
{
    blockName.clear();
    if(index >=0 && index < (int)blockFileNames.size())
    {
        blockName = baseDir + VISIT_SLASH_STRING + blockFileNames[index];
    }
    return blockName;
}


// ****************************************************************************
//  Method: VTMParser::GetNumberOfBlocks
//
//  Return:  The number of blocks.
//
//  Programmer: Kathleen Biagas
//  Creation:   August 12, 2015
//
// ****************************************************************************

int
VTMParser::GetNumberOfBlocks()
{
    return (int)blockFileNames.size();
}


// ****************************************************************************
//  Method: VTMParser::Parse
//
//  Purpose:
//    Parses the 'vtm' file for DataSet file names, and other information
//    that VisIt might want like block and group names.
//
//  Note:
//     A lot of error checking here, perhaps more than is truly needed.
//
//  Programmer: Kathleen Biagas
//  Creation:   August 12, 2015
//
// ****************************************************************************

bool
VTMParser::Parse()
{
    if(parser == NULL)
       parser = vtkXMLDataParser::New();

    parser->SetFileName(fileName.c_str());
    if (!parser->Parse())
    {
        errorMessage = "Error parsing file: " + fileName;
        return false;
    }

    vtkXMLDataElement *root = parser->GetRootElement();
    if (!root)
    {
        errorMessage = "Error retrieving RootElement after parsing file.";
        return false;
    }
    string rootName(root->GetName());
    if (rootName != "VTKFile")
    {
        errorMessage = fileName + "does not contain 'VTKFile' tag.";
        return false;
    }

    string dsType = root->GetAttribute("type");
    if (dsType != "vtkMultiBlockDataSet")
    {
        errorMessage = string("VTKFile type: ") +
                      dsType + string(" currently not supported.");
        return false;
    }

    vtkXMLDataElement *mbdsNode = root->GetNestedElement(0);
    if (mbdsNode->GetName() != dsType)
    {
        errorMessage = "First nested element doesn't match " + dsType;
        return false;
    }

    int n = mbdsNode->GetNumberOfNestedElements();

    // Loop over nested attributes, assuming each represents a 'group'.
    // Only top-level groups are accounted for with this code, sub-groups
    // are ignored.  (VTK's many_blocks.vtm example has sub-groups).
    vector<int> nBlocksPerGroup;
    for (int i = 0; i < n; ++i)
    {
        int nb = 0;
        vtkXMLDataElement *el = mbdsNode->GetNestedElement(i);
        ParseForDS(el, nb);
        if (el->GetAttribute("name") != NULL)
        {
            groupNames.push_back(el->GetAttribute("name"));
        }

        // associate each block with this group, via groupIds.
        for (int j = 0; j < nb; ++j)
            groupIds.push_back(i);
        string elName(el->GetName());

        if (elName  != "DataSet")
            groupPieceName = elName;
        nBlocksPerGroup.push_back(nb);
    }
    nGroups = (int)nBlocksPerGroup.size();

    // Sanity checks in case some blocks or datasets didn't have a 'name'
    // attribute
    if (nGroups == 1 || (int)groupNames.size() != nGroups)
        groupNames.clear();

    if(blockFileNames.size() != blockNames.size())
        blockNames.clear();

    // No guarantee that there is a separate name (or Title) for groups,
    // or blocks for that matter. If group and piece name are the same,
    // give groupPieceName a generic name.
    if (!groupPieceName.empty() &&
        !blockPieceName.empty() &&
        groupPieceName == blockPieceName)
    {
        groupPieceName = "Group";
    }
    return true;
}


// ****************************************************************************
//  Method: VTMParser::ParseForDS
//
//  Purpose:
//    Recursively checks the passed vtkXMLDataElement for 'DataSet' tag.
//    Retrieves and stores 'file' and 'name' attributes.
//
//  Programmer: Kathleen Biagas
//  Creation:   August 12, 2015
//
//  Modifications:
//    Kathleen Biagas, Thu Sep 19 14:11:28 PDT 2019
//    Don't process the 'DataSet' tag if it doesn't have a 'file' attribute.
//
// ****************************************************************************

void
VTMParser::ParseForDS(vtkXMLDataElement *de, int &n)
{
    string name(de->GetName());
    if (name == "DataSet")
    {
        if (de->GetAttribute("file"))
        {
            n++;
            string bfn(de->GetAttribute("file"));
            if (blockExtension.empty())
            {
                size_t pos = bfn.find_last_of('.');
                if (pos == std::string::npos)
                    blockExtension = "none";
                else
                    blockExtension = bfn.substr(pos+1);
            }
            blockFileNames.push_back(bfn);
            if (de->GetAttribute("name") != NULL)
            {
                blockNames.push_back(string(de->GetAttribute("name")));
            }
            if (blockPieceName.empty())
            {
                vtkXMLDataElement *parent = de->GetParent();
                if(parent)
                {
                    blockPieceName = parent->GetName();
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < de->GetNumberOfNestedElements(); ++i)
            ParseForDS(de->GetNestedElement(i), n);
    }
}
