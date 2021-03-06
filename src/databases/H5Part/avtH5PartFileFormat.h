// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                            avtH5PartFileFormat.h                          //
// ************************************************************************* //

#ifndef AVT_H5PART_FILE_FORMAT_H
#define AVT_H5PART_FILE_FORMAT_H

#include <visit-config.h>

#include <avtMTSDFileFormat.h>

// H5Part
#include <H5Part.h>
#include <H5Block.h>
#include <H5BlockTypes.h>

// FastBit
#ifdef HAVE_LIBFASTQUERY
  #include <fastbit-config.h>

  #if FASTBIT_IBIS_INT_VERSION < 1020000
    #error "The H5Part plugin requires FastBit 1.2.0 or newer."
  #endif

  #include "HistogramCache.h"
  // #include "hdf5_fastquery.h"
#endif

// STL
#include <vector>
#include <map>
#include <string>

class DBOptionsAttributes;

#ifdef HAVE_LIBFASTQUERY
class avtIdentifierSelection;
class avtHistogramSpecification;
#endif


// ****************************************************************************
//  Class: avtH5PartFileFormat
//
//  Purpose:
//      Reads in H5Part files as a plugin to VisIt.
//
//  Programmer: ghweber -- generated by xml2avt
//  Creation:   Tue Feb 9 13:44:50 PST 2010
//
//  Modifications:
//    Kurt Stockinger, Tue Aug 28 17:35:50 PDT 2007
//    Added support for field data
//
//    Gunther H. Weber, Fri Apr 17 13:03:47 PDT 2009
//    Added option to reject file if FastBit index is present.
//
//    Gunther H. Weber, Tue Nov 10 19:48:28 PST 2009
//    Removed unused data members.
//
//    Gunther H. Weber, Tue Feb  9 17:16:20 PST 2010
//    Complete restructuring. Recreated plugin as MTSD that supports
//    domain decomposition and rewrote major portions using original
//    pieces. Merged with HDF_UC plugin.
//
// ****************************************************************************

class avtH5PartFileFormat : public avtMTSDFileFormat
{
  public:
                       avtH5PartFileFormat(const char *, const DBOptionsAttributes *);
    virtual           ~avtH5PartFileFormat();

#ifdef HAVE_LIBFASTQUERY
    //
    // This is used to return unconvention data -- ranging from material
    // information to information about block connectivity.
    //
    virtual void      *GetAuxiliaryData(const char *var, int timestep, 
                                        const char *type, void *args, 
                                        DestructorFunction &);
#endif
    //
    // If you know the times and cycle numbers, overload this function.
    // Otherwise, VisIt will make up some reasonable ones for you.
    //
    // virtual void        GetCycles(std::vector<int> &);
    // virtual void        GetTimes(std::vector<double> &);
    //

    virtual int            GetNTimesteps(void);

    virtual const char    *GetType(void) { return "H5Part"; };
    virtual void           FreeUpResources(void); 

#ifdef HAVE_LIBFASTQUERY 
    virtual bool           CanCacheVariable(const char *) { return !useFastBitIndex; /* FIXME: Field variables can be cached */ };
    virtual void           RegisterDataSelections(const std::vector<avtDataSelection_p>&,
                               std::vector<bool> *);
#endif

    virtual vtkDataSet    *GetMesh(int, const char *);
    virtual vtkDataArray  *GetVar(int, const char *);
    virtual vtkDataArray  *GetVectorVar(int, const char *);

    virtual void           ActivateTimestep(int ts);

  protected:
    // DATA MEMBERS
    // ... Constants
    static const int       maxVarNameLen = 256; // Maximum variable name length used in H5Part calls

    // ... Reader options
    bool                   enableDomainDecomposition;

    std::string            variablePathPrefix;
    
// ... File information
    H5PartFile            *file;
    enum { cartesianCoordSystem, cylindricalCoordSystem, sphericalCoordSystem }
                           coordType;
    int                    particleNSpatialDims;
    typedef std::map<std::string, h5part_int64_t>
                           VarNameToInt64Map_t;
    VarNameToInt64Map_t    particleVarNameToTypeMap;
    VarNameToInt64Map_t    particleVarNameToFastBitMap;
    VarNameToInt64Map_t    fieldScalarVarNameToTypeMap;
    VarNameToInt64Map_t    fieldVectorVarNameToTypeMap;
    VarNameToInt64Map_t    fieldVectorVarNameToFieldRankMap;
    h5part_int64_t         numTimestepsInFile;
    h5part_int64_t         activeTimeStep;

    // The name of the current variable which contains the particle id
    std::string            idVariableName;
    // The name of the default variable which contains the particle id
    std::string            defaultIdVariableName;
    // The name of the variable which contains the sorted particle id
    std::string            defaultSortedVariableName;

    virtual void           PopulateDatabaseMetaData(avtDatabaseMetaData *, int);
    virtual void           GetCycles(std::vector<int> &c);
    virtual void           GetTimes(std::vector<double> &t);

  private:
    void                   SelectParticlesToRead( const char * = 0 );
    vtkDataSet            *GetParticleMesh(int);
    vtkDataSet            *GetFieldMesh(int, const char *);
    vtkDataArray          *GetFieldVar(int, const char*);
    void                   GetSubBlock(h5part_int64_t gridDims[3], h5part_int64_t subBlockDims[6]);
    std::string            DoubleToString(double x);

    std::vector<int>       cycles;
    std::vector<double>    times;
  
    void GetDecomp( h5part_int64_t nObjects,
                    h5part_int64_t &firstIndex,
                    h5part_int64_t &lastIndex,
                    h5part_int64_t &total );

    const std::string getVariablePathPrefix( int timestep );

#ifdef HAVE_LIBFASTQUERY

    void                   ConstructHistogram(avtHistogramSpecification *spec);

    avtIdentifierSelection
                          *ConstructIdentifiersFromDataRangeSelection(
                                  std::vector<avtDataSelection *> &);
    void                   ConstructIdQueryString(const std::vector<double>&,
                                  const std::string &, std::string& );
    void                   PerformQuery();

    const std::string getFastBitIndexPathPrefix( int timestep );
  
    // Is there an active query? If value is stringQuery,
    // "queryString" contains the current query that needs to be run
    // to get the data selection (queryResults).  If value is
    // idListQuery, "queryIdList" contains a list of particle ids
    // (likely from a named selection).
    enum { noQuery = 0, stringQuery, idListQuery } querySpecified;

    bool                   useFastBitIndex;
    std::string            fastBitIndexPathPrefix;
  
    // Are the query results (queryResults) valid? This variable is
    // set to false by RegisterDataSelection to indicate that there is
    // a new queryString or queryIdList and that PerformQuery needs to
    // be called to update queryResults
    bool                   queryResultsValid;
    // Is there an active data selection, i.e., does queryResults
    // contain a valid list of particles indices to load for an active
    // query?
    bool                   dataSelectionActive;
    // String of a possible active stringQuery
    std::string            queryString;
    // List of ids (values if "idVariableName") for a named selection query
    std::vector<double>    queryIdList;
    // Result from a current query
    std::vector<uint64_t>   queryResults;

    // The HDF5_FastQuery reader. Used mainly to read index
    // information from file.
    // HDF5_FQ                fqReader;

    // Histogram cache for already computed histograms
    HistogramCache         histoCache;
#endif
};

#endif
