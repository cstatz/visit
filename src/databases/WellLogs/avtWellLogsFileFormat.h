// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                          avtWellLogsFileFormat.h                          //
// ************************************************************************* //

#ifndef AVT_WellLogs_FILE_FORMAT_H
#define AVT_WellLogs_FILE_FORMAT_H

#include <avtSTSDFileFormat.h>


// ****************************************************************************
//  Class: avtWellLogsFileFormat
//
//  Purpose:
//      Reads in WellLogs files as a plugin to VisIt.
//
//  Programmer: hari -- generated by xml2avt
//  Creation:   Fri Apr 11 23:22:06 PST 2014
//
// ****************************************************************************

class avtWellLogsFileFormat : public avtSTSDFileFormat
{
  public:
                       avtWellLogsFileFormat(const char *filename);
    virtual           ~avtWellLogsFileFormat() {;};

    virtual void      *GetAuxiliaryData(const char *var, const char *type,
                                        void *args, DestructorFunction &);

    //
    // These are used to declare what the current time and cycle are for the
    // file.  These should only be defined if the file format knows what the
    // time and/or cycle is.
    //
    // virtual int       GetCycle(void);
    // virtual double    GetTime(void);
    //

    virtual const char    *GetType(void)   { return "WellLogs"; };
    virtual void           FreeUpResources(void); 

    virtual vtkDataSet    *GetMesh(const char *);
    virtual vtkDataArray  *GetVar(const char *);
    virtual vtkDataArray  *GetVectorVar(const char *);

  protected:
    std::string               wlFilename;
    bool                      haveReadFile;
    std::vector<std::string>  wellNames;
    std::vector<int>          wellIds;
    std::vector<double>       X;
    std::vector<double>       Y;
    std::vector<double>       Z1;
    std::vector<double>       Z2;
    int                       filetype; //type of file being read in..

    void                   ReadFile();
    virtual void           PopulateDatabaseMetaData(avtDatabaseMetaData *);
};


#endif
