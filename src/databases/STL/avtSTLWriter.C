// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                              avtSTLWriter.C                               //
// ************************************************************************* //

#include <avtSTLWriter.h>

#include <vector>

#include <vtkAlgorithm.h>
#include <vtkAppendPolyData.h>
#include <vtkDataSet.h>
#include <vtkGeometryFilter.h>
#include <vtkDataSetWriter.h>
#include <vtkPolyDataReader.h>
#include <vtkPolyDataWriter.h>
#include <vtkCharArray.h>
#include <vtkPolyData.h>
#include <vtkSTLWriter.h>
#include <vtkTriangleFilter.h>

#include <avtDatabaseMetaData.h>
#include <DBOptionsAttributes.h>

#include <DebugStream.h>
#include <avtParallelContext.h>

using     std::string;
using     std::vector;


// ****************************************************************************
//  Method: avtSTLWriter constructor
//
//  Programmer: jfavre -- generated by xml2avt
//  Creation:   Fri Jan 27 14:13:01 PST 2012
//
//  Modifications:
//    Brad Whitlock, Fri Jan 27 09:56:06 PST 2012
//    Added polydatas.
//
// ****************************************************************************

avtSTLWriter::avtSTLWriter(const DBOptionsAttributes *atts) : avtDatabaseWriter()
{
    doBinary = atts->GetBool("Binary format");
}

// ****************************************************************************
//  Method: avtSTLWriter::OpenFile
//
//  Purpose:
//      Does no actual work.  Just records the stem name for the files.
//
//  Programmer: jfavre -- generated by xml2avt
//  Creation:   Fri Jan 27 14:13:01 PST 2012
//
// ****************************************************************************

void
avtSTLWriter::OpenFile(const string &stemname, int numblocks)
{
    stem = stemname;
}

// ****************************************************************************
//  Method: avtSTLWriter::WriteHeaders
//
//  Purpose:
//      Writes out a VisIt file to tie the STL files together.
//
//  Programmer: jfavre -- generated by xml2avt
//  Creation:   Fri Jan 27 14:13:01 PST 2012
//
// ****************************************************************************

void
avtSTLWriter::WriteHeaders(const avtDatabaseMetaData *md,
                           const vector<string> &scalars,
                           const vector<string> &vectors,
                           const vector<string> &materials)
{
    // WRITE OUT HEADER INFO
}

// ****************************************************************************
//  Method: avtSTLWriter::WriteChunk
//
//  Purpose:
//      This writes out one chunk of an avtDataset.
//
//  Programmer: jfavre -- generated by xml2avt
//  Creation:   Fri Jan 27 14:13:01 PST 2012
//
//  Modifications:
//    Brad Whitlock, Fri Jan 27 09:29:26 PST 2012
//    Save the polydata so we can combine it all into one dataset. We do any
//    conversion to polydata and then to triangles before saving the polydata.
//
//    Brad Whitlock, Tue Sep  8 17:04:07 PDT 2015
//    Rely on base class for geometry consolidation. This method will only
//    be called on group leaders.
//
// ****************************************************************************

void
avtSTLWriter::WriteChunk(vtkDataSet *ds, int chunk)
{
    std::string filename;
    if(writeContext.GroupSize() > 1)
    {
        char ext[20];
        snprintf(ext, 20, ".%d.stl", writeContext.GroupRank());
        filename = stem + ext;
    }
    else
        filename = stem + ".stl";

    vtkSTLWriter *writer = vtkSTLWriter::New();   
    writer->SetFileName(filename.c_str());
    if(doBinary)
        writer->SetFileTypeToBinary();

    writer->SetInputData(ds);
    writer->Update();
    writer->Delete();
}

// ****************************************************************************
//  Method: avtSTLWriter::CloseFile
//
//  Purpose:
//      Closes the file.  This does nothing in this case.
//
//  Programmer: jfavre -- generated by xml2avt
//  Creation:   Fri Jan 27 14:13:01 PST 2012
//
//  Modifications:
//  
// ****************************************************************************

void
avtSTLWriter::CloseFile(void)
{
}

// ****************************************************************************
// Method: avtSTLWriter::CreateTrianglePolyData
//
// Purpose:
//   Tell VisIt's export that we'll want triangles.
//
// Returns:    True
//
// Programmer: Brad Whitlock
// Creation:   Tue Sep  8 17:00:23 PDT 2015
//
// Modifications:
//
// ****************************************************************************

bool
avtSTLWriter::CreateTrianglePolyData() const
{
    return true;
}

// ****************************************************************************
//  Method: avtTecplotWriter::GetCombineMode
//
//  Purpose:
//     Provides a hint to the export mechanism to tell it how to combine data.
//
//  Note: We combine geometry because STL tools will want 1 file.
//
//  Programmer: Brad Whitlock
//  Creation:   Tue Sep  8 15:36:45 PDT 2015
//
// ****************************************************************************

avtDatabaseWriter::CombineMode
avtSTLWriter::GetCombineMode(const std::string &) const
{
    return CombineAll;
}
