// ************************************************************************* //
//                            avtH5PartFileFormat.h                           //
// ************************************************************************* //

#ifndef AVT_H5Part_FILE_FORMAT_H
#define AVT_H5Part_FILE_FORMAT_H

#include <avtMTMDFileFormat.h>
#include <H5Part.h>

#include <vector>
#include <string>




// ****************************************************************************
//  Class: avtH5PartFileFormat
//
//  Purpose:
//      Reads in H5Part files as a plugin to VisIt.
//
//  Programmer: cristina -- generated by xml2avt
//  Creation:   Mon Feb 27 13:53:31 PST 2006
//
// ****************************************************************************

class avtH5PartFileFormat : public avtMTMDFileFormat
{
  public:
                       avtH5PartFileFormat(const char *);
    virtual           ~avtH5PartFileFormat() {;};

    //
    // This is used to return unconvention data -- ranging from material
    // information to information about block connectivity.
    //
    // virtual void      *GetAuxiliaryData(const char *var, const char *type,
    //                                     int timestep, int domain,void *args, 
    //                                     DestructorFunction &);
    //

    //
    // If you know the times and cycle numbers, overload this function.
    // Otherwise, VisIt will make up some reasonable ones for you.
    //
    // virtual void        GetCycles(std::vector<int> &);
    // virtual void        GetTimes(std::vector<double> &);
    //

    virtual int            GetNTimesteps(void);

    virtual const char    *GetType(void)   { return "H5Part"; };
    virtual void           FreeUpResources(void); 

    virtual vtkDataSet    *GetMesh(int, int, const char *);
    virtual vtkDataArray  *GetVar(int, int, const char *);
    virtual vtkDataArray  *GetVectorVar(int, int, const char *);

  protected:
    // DATA MEMBERS

    virtual void           PopulateDatabaseMetaData(avtDatabaseMetaData *, int);
    std::string fname; //filename
    std::vector<float>  points; //point coordinates
    std::vector<std::vector<float> > pointvars; //point variables
    std::vector<std::string> pointvarnames; //point variables' names
    std::vector<float> minExtents; //min extents
    std::vector<float> maxExtents; //max extents


};


#endif
