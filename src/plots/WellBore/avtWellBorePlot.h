// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                               avtWellBorePlot.h                           //
// ************************************************************************* //

#ifndef AVT_WellBore_PLOT_H
#define AVT_WellBore_PLOT_H


#include <avtPlot.h>

#include <WellBoreAttributes.h>

class     avtWellBoreNameMapper;
class     avtLevelsLegend;
class     avtLevelsMapper;
class     avtLookupTable;
class     avtWellBoreFilter;


// ****************************************************************************
//  Class:  avtWellBorePlot
//
//  Purpose:
//      A concrete type of avtPlot, this is the WellBore plot.
//
//  Programmer: brugger -- generated by xml2avt
//  Creation:   Wed Aug 27 14:59:19 PST 2008
//
//  Modifications:
//      Eric Brugger, Mon Nov 10 09:13:30 PST 2008
//      Added the ability to display well bore names and stems.
//
// ****************************************************************************

class avtWellBorePlot : public avtSurfaceDataPlot
{
  public:
                                avtWellBorePlot();
    virtual                    ~avtWellBorePlot();

    virtual const char         *GetName(void) { return "WellBorePlot"; };

    static avtPlot             *Create();

    virtual void                SetAtts(const AttributeGroup*);
    void                        SetLegend(bool);
    void                        SetLineWidth(int);

  protected:
    WellBoreAttributes          atts;

    avtWellBoreFilter          *WellBoreFilter;

    avtLevelsMapper            *levelsMapper;
    avtLevelsLegend            *levelsLegend;
    avtWellBoreNameMapper      *decoMapper;
    avtLegend_p                 levLegendRefPtr;
    avtLookupTable             *avtLUT;

    virtual avtMapperBase      *GetMapper(void);
    virtual avtDataObject_p     ApplyOperators(avtDataObject_p);
    virtual avtDataObject_p     ApplyRenderingTransformation(avtDataObject_p);
    virtual void                CustomizeBehavior(void);
    virtual void                CustomizeMapper(avtDataObjectInformation &);

    virtual avtLegend_p         GetLegend(void) { return NULL; };
    virtual avtDecorationsMapper *GetDecorationsMapper(void);

    void                        SetColors();
};


#endif
