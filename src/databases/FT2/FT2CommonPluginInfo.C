// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <FT2PluginInfo.h>
#include <avtFT2FileFormat.h>
#include <avtMTSDFileFormatInterface.h>
#include <avtGenericDatabase.h>

// ****************************************************************************
//  Method:  FT2CommonPluginInfo::GetDatabaseType
//
//  Purpose:
//    Returns the type of a FT2 database.
//
//  Programmer:  generated by xml2info
//  Creation:    omitted
//
// ****************************************************************************
DatabaseType
FT2CommonPluginInfo::GetDatabaseType()
{
    return DB_TYPE_MTSD;
}

// ****************************************************************************
//  Method: FT2CommonPluginInfo::SetupDatabase
//
//  Purpose:
//      Sets up a FT2 database.
//
//  Arguments:
//      list    A list of file names.
//      nList   The number of timesteps in list.
//      nBlocks The number of blocks in the list.
//
//  Returns:    A FT2 database from list.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************
avtDatabase *
FT2CommonPluginInfo::SetupDatabase(const char *const *list,
                                   int nList, int nBlock)
{
    int nTimestepGroups = nList / nBlock;
    avtMTSDFileFormat ***ffl = new avtMTSDFileFormat**[nTimestepGroups];
    for (int i = 0; i < nTimestepGroups; i++)
    {
        ffl[i] = new avtMTSDFileFormat*[nBlock];
        for (int j = 0; j < nBlock; j++)
        {
            ffl[i][j] = new avtFT2FileFormat(list[i*nBlock + j]);
        }
    }
    avtMTSDFileFormatInterface *inter
           = new avtMTSDFileFormatInterface(ffl, nTimestepGroups, nBlock);
    return new avtGenericDatabase(inter);
}
