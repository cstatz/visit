// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                            avtLookupTable.C                               //
// ************************************************************************* //

#include <avtLookupTable.h>

#include <avtColorTables.h>
#include <vtkLookupTable.h>
#include <vtkLogLookupTable.h>
#include <vtkSkewLookupTable.h>

#include <InvalidColortableException.h>

#define INV_255 0.0039215686274509803377

// ****************************************************************************
//  Method: avtLookupTable constructor
//
//  Programmer: Kathleen Bonnell 
//  Creation:   August 27, 2001 
//
// ****************************************************************************

avtLookupTable::avtLookupTable()
{
    //
    //  Build a basic 'hot' lut, in case user does not want to set
    //  colors separately.  VTK's default size is 256 colors.
    //  The default range for scalars mapped through the table is (0, 1).
    // 
    stdLUT  = vtkLookupTable::New();    
    stdLUT->SetHueRange(0.6667, 0);
    stdLUT->Build();

    logLUT  = vtkLogLookupTable::New();    
    logLUT->SetHueRange(0.6667, 0);
    logLUT->Build();

    skewLUT = vtkSkewLookupTable::New();    
    skewLUT->SetHueRange(0.6667, 0);
    skewLUT->Build();
}


// ****************************************************************************
//  Method: avtLookupTable destructor
//
//  Programmer: Kathleen Bonnell 
//  Creation:   August 27, 2001 
//
// ****************************************************************************

avtLookupTable::~avtLookupTable()
{
    stdLUT->Delete();
    stdLUT = NULL;

    logLUT->Delete();
    logLUT = NULL;

    skewLUT->Delete();
    skewLUT = NULL;
}


// ****************************************************************************
//  Method: avtLookupTable::SetSkewFactor
//
//  Purpose:
//      Sets the skew factor for the skew LUT. 
//
//  Arguments:
//      s      The skew factor. 
//
//  Programmer: Kathleen Bonnell 
//  Creation:   August 27, 2001 
//
// ****************************************************************************

void
avtLookupTable::SetSkewFactor(const double s)
{
    skewLUT->SetSkewFactor(s);
}


// ****************************************************************************
// Method: avtVariableMapper::SetLUTColors
//
// Purpose: 
//   Sets the specified colors into each type of lookup table. 
//
// Arguments:
//   colors  : An array of rgb triples stored as unsigned chars.
//   nColors : The number of colors in the colors array.
//
// Programmer: Brad Whitlock
// Creation:   Fri Jun 15 11:35:13 PDT 2001
//
// Modifications:
//
//   Kathleen Bonnell, Mon Aug 27 12:42:00 PDT 2001
//   Moved from all avtXXXMapper classes.  Removed call to lut->SetHueRange 
//   and lut->SetRange.  Use instead lut->SetNumberOfTableValues.
//   
// ****************************************************************************

void
avtLookupTable::SetLUTColors(const unsigned char *colors, int nColors)
{
    // Rebuild the lut with the new color table.
    stdLUT->SetNumberOfTableValues(nColors);
    logLUT->SetNumberOfTableValues(nColors);
    skewLUT->SetNumberOfTableValues(nColors);

    const unsigned char *cptr = colors;
    for(int i = 0; i < nColors; ++i)
    {
        double r = double(cptr[0]) * INV_255;
        double g = double(cptr[1]) * INV_255;
        double b = double(cptr[2]) * INV_255;
        stdLUT->SetTableValue(i, r, g, b, 1.);
        logLUT->SetTableValue(i, r, g, b, 1.);
        skewLUT->SetTableValue(i, r, g, b, 1.);
        cptr += 3;
    }
}

// ****************************************************************************
//  Method:  avtLookupTable::SetLUTColorsAndOpacity
//
//  Purpose:
//    Like SetLUTColorsWithOpacity, but takes a 3-component color
//    and a separate list of alpha values.
//
//  Arguments:
//    colors     3-component rgb triples
//    alphas     1-component alpha values
//    nColors    the number of colors in the array
//
//  Programmer:  Jeremy Meredith
//  Creation:    February 20, 2009
//
// ****************************************************************************

void
avtLookupTable::SetLUTColorsAndOpacity(const unsigned char *colors,
                                       const unsigned char *alphas,
                                       int nColors)
{
    // Rebuild the lut with the new color table.
    stdLUT->SetNumberOfTableValues(nColors);
    logLUT->SetNumberOfTableValues(nColors);
    skewLUT->SetNumberOfTableValues(nColors);

    const unsigned char *cptr = colors;
    for(int i = 0; i < nColors; ++i)
    {
        double r = double(cptr[0]) * INV_255;
        double g = double(cptr[1]) * INV_255;
        double b = double(cptr[2]) * INV_255;
        double a = double(alphas[i]) * INV_255;
        stdLUT->SetTableValue(i, r, g, b, a);
        logLUT->SetTableValue(i, r, g, b, a);
        skewLUT->SetTableValue(i, r, g, b, a);
        cptr += 3;
    }
}


// ****************************************************************************
// Method: avtVariableMapper::SetLUTColorsWithOpacity
//
// Purpose: 
//   Sets the specified colors into each type of lookup table. 
//
// Arguments:
//   colors  : An array of rgb triples stored as unsigned chars.
//   nColors : The number of colors in the colors array.
//
// Programmer: Brad Whitlock
// Creation:   Fri Jun 15 11:35:13 PDT 2001
//
// Modifications:
//
//   Kathleen Bonnell, Mon Aug 27 12:42:00 PDT 2001
//   Modified from Brad's original method to include opacity.  
//   
// ****************************************************************************

void
avtLookupTable::SetLUTColorsWithOpacity(const unsigned char *colors, 
                                        int nColors)
{
    // Rebuild the lut with the new color table.
    stdLUT->SetNumberOfTableValues(nColors);
    logLUT->SetNumberOfTableValues(nColors);
    skewLUT->SetNumberOfTableValues(nColors);

    const unsigned char *cptr = colors;
    for(int i = 0; i < nColors; ++i)
    {
        double r = (double) cptr[0] * INV_255 ;
        double g = (double) cptr[1] * INV_255 ;
        double b = (double) cptr[2] * INV_255 ;
        double a = (double) cptr[3] * INV_255 ;

        stdLUT->SetTableValue(i, r, g, b, a);
        logLUT->SetTableValue(i, r, g, b, a);
        skewLUT->SetTableValue(i, r, g, b, a);
        cptr += 4;
    }
}


// ****************************************************************************
// Method: avtVariableMapper::GetNumberOfColors
//
// Purpose: 
//   Retrieves the number of colors currently in the luts. 
//
// Returns: 
//   The number of colors. 
//
// Programmer: Kathleen Bonnell 
// Creation:   August 28, 2001 
//
// ****************************************************************************

int
avtLookupTable::GetNumberOfColors()
{
    return stdLUT->GetNumberOfColors();
}


// ****************************************************************************
// Method: avtLookupTable::SetColorTable
//
// Purpose: 
//   Sets the color table for the lookup table.
//
// Arguments:
//   ctName : The name of the color table to use.
//
// Returns:    Returns true if the color table is updated.
//
// Programmer: Brad Whitlock
// Creation:   Thu Jun 14 16:52:49 PST 2001
//
// Modifications:
//    Jeremy Meredith, Thu Aug 23 14:11:40 PDT 2001
//    Made it use the color table name "Default" instead of the boolean flag.
//
//    Kathleen Bonnell, Fri Aug 31 10:36:49 PDT 2001
//    Moved from avtXXXPlot.C.  Added 'validName' for plots to
//    send along.
//
//    Brad Whitlock, Wed Nov 20 14:23:47 PST 2002
//    I changed it so it conforms to the new interface for avtColortTables.
//    It gets the default continuous colortable if it is supposed to use
//    the default. If it cannot get the default continuous colortable, it
//    tries to get the default discrete colortable.
//
//    Brad Whitlock, Fri Apr 25 12:26:40 PDT 2003
//    I made it throw InvalidColortableException.
//
//    Jeremy Meredith, Thu Aug  7 14:38:16 EDT 2008
//    Use true string comparison (instead of undefined pointer comparison).
//
//    Jeremy Meredith, Fri Aug  8 10:26:38 EDT 2008
//    Check for NULL ctName before doing a comparison, not afterwards....
//
//    Jeremy Meredith, Fri Feb 20 15:01:03 EST 2009
//    Added ability to also set the LUT colors with opacities from the
//    color table (if requested by the caller in the new argument).
//
//    Kathleen Bonnell, Mon Jan 17 17:38:40 MST 2011
//    Added invert argument.
//
//    Kathleen Biagas, Tue Apr 12 10:02:22 MST 2016
//    Don't attempt to retrieve alphas values if ctName is NULL.
//
// ****************************************************************************

bool
avtLookupTable::SetColorTable(const char *ctName, bool validName,
                              bool useOpacities,
                              bool invert,
                              double rampOpacity)
{
    avtColorTables *ct = avtColorTables::Instance();
    const unsigned char *c = NULL;

    // Figure out the circumstances in which we should use the default
    // color table.
    if(ctName == NULL || std::string(ctName) == "Default")
    {
      // Use the default continuous color table.
      const char *dct = ct->GetDefaultContinuousColorTable().c_str();

      // No continuous table so use the default discrete color table.
      if(dct == 0)
        dct = ct->GetDefaultDiscreteColorTable().c_str();

      c = ct->GetColors(dct, invert);
    }
    else if (validName)
    {
      if(!ct->ColorTableExists(ctName))
      {
        EXCEPTION1(InvalidColortableException, ctName);
      }

      // Use the specified color table. It was a valid color table.
      c = ct->GetColors(ctName, invert);
    }

    if(c != NULL)
    {
      // Set the colors into the lookup table.
      if (0 <= rampOpacity && rampOpacity <= 1.0)
      {
        // Change from 0->1.0 to 0->256
        rampOpacity *= 256.0;
        
        unsigned char *a = (unsigned char *) malloc( ct->GetNumColors() );
        
        for( unsigned int i=0; i<(unsigned int)ct->GetNumColors(); ++i )
          a[i] = (unsigned char)
            (rampOpacity * (double) i / (double) ct->GetNumColors() );
        
        SetLUTColorsAndOpacity(c, a, ct->GetNumColors());
      }
      else if (useOpacities && ctName != NULL)
      {
        const unsigned char *a = ct->GetAlphas(ctName);
        SetLUTColorsAndOpacity(c, a, ct->GetNumColors());
      }
      else
      {
        SetLUTColors(c, ct->GetNumColors());
      }

      return true;
    }
    else
      return false;
}
