// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                               avtMIPRangeRF.C                             //
// ************************************************************************* //

#include <avtMIPRangeRF.h>

#include <float.h>

#include <avtLightingModel.h>
#include <avtRay.h>
#include <avtVariablePixelizer.h>


// ****************************************************************************
//  Method: avtMIPRangeRF constructor
//
//  Arguments:
//      l      The lighting model.
//      min    The minimum value still rendered.
//      max    The maximum value still rendered.
//      p      The pixelizer for this ray function.
//
//  Programmer: Hank Childs
//  Creation:   December 13, 2000
//
// ****************************************************************************

avtMIPRangeRF::avtMIPRangeRF(avtLightingModel *l, double min, double max,
                             avtVariablePixelizer *p)
    : avtRayFunction(l)
{
    thresholdMin = min;
    thresholdMax = max;
    pix = p;
}


// ****************************************************************************
//  Method: avtMIPRangeRF destructor
//
//  Purpose:
//      Defines the destructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   February 5, 2004
//
// ****************************************************************************

avtMIPRangeRF::~avtMIPRangeRF()
{
    ;
}


// ****************************************************************************
//  Method: avtMIPRangeRF::GetRayValue
//
//  Purpose:
//      Get the pixel value of the ray using a maximum intensity projection,
//      limited to a certain range.  The pixel value is the maximum value
//      along the ray.
//
//  Arguments:
//      ray         The ray to use.
//      gradients   The gradients along the ray.
//      rgb         A place to put the color.
//      depth       The depth that the first opaque polygon is at.
//
//  Programmer: Hank Childs
//  Creation:   December 13, 2000
//
//  Modifications:
//
//    Hank Childs, Sat Feb  3 21:19:23 PST 2001
//    Had function return a color instead of a value.
//
//    Hank Childs, Tue Feb 13 18:30:07 PST 2001
//    Account for volume renderings that have opaque images inside them.
//
//    Hank Childs, Wed Nov 14 14:51:34 PST 2001
//    Added support for multiple variables.
//
//    Hank Childs, Sun Aug 31 08:04:42 PDT 2008
//    Code cleanup for lighting models.
//
// ****************************************************************************

void
avtMIPRangeRF::GetRayValue(const avtRay *ray, 
                           unsigned char rgb[3], double depth)
{
    double curMax = -1. * DBL_MAX;
    int    maxInd = -1;

    //
    // Some compilers do very poor optimizations, so make sure that we don't
    // do an offset from the pointer at each step by creating automatic
    // variables and using those.
    //
    const int     numSamples  = ray->numSamples;
    const bool   *validSample = ray->validSample;

    // Only handle one variable, even if there is more.
    const double  *sample      = ray->sample[0];

    int depthIndex = IndexOfDepth(depth, numSamples);

    for (int i = 0 ; i < depthIndex ; i++)
    {
        if (validSample[i])
        {
            if (sample[i] >= thresholdMin && sample[i] <= thresholdMax)
            {
                if (curMax < sample[i])
                {
                    curMax = sample[i];
                    maxInd = i;
                }
            }
        }
    }

    if (maxInd != -1)
    {
        pix->GetColor(curMax, 1., rgb);
        lighting->AddLighting(maxInd, ray, rgb);
    }
}


