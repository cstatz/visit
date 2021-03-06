// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <ProteinDataBankPluginInfo.h>
#include <avtProteinDataBankFileFormat.h>
#include <avtSTSDFileFormatInterface.h>
#include <avtGenericDatabase.h>
#include <avtProteinDataBankOptions.h>

// ****************************************************************************
//  Method:  ProteinDataBankCommonPluginInfo::GetDatabaseType
//
//  Purpose:
//    Returns the type of a ProteinDataBank database.
//
//  Programmer:  generated by xml2info
//  Creation:    omitted
//
// ****************************************************************************
DatabaseType
ProteinDataBankCommonPluginInfo::GetDatabaseType()
{
    return DB_TYPE_STSD;
}

// ****************************************************************************
//  Method: ProteinDataBankCommonPluginInfo::SetupDatabase
//
//  Purpose:
//      Sets up a ProteinDataBank database.
//
//  Arguments:
//      list    A list of file names.
//      nList   The number of timesteps in list.
//      nBlocks The number of blocks in the list.
//
//  Returns:    A ProteinDataBank database from list.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************
avtDatabase *
ProteinDataBankCommonPluginInfo::SetupDatabase(const char *const *list,
                                   int nList, int nBlock)
{
    int nTimestep = nList / nBlock;
    avtSTSDFileFormat ***ffl = new avtSTSDFileFormat**[nTimestep];
    for (int i = 0; i < nTimestep; i++)
    {
        ffl[i] = new avtSTSDFileFormat*[nBlock];
        for (int j = 0; j < nBlock; j++)
        {
            ffl[i][j] = new avtProteinDataBankFileFormat(list[i*nBlock + j], readOptions);
        }
    }
    avtSTSDFileFormatInterface *inter
           = new avtSTSDFileFormatInterface(ffl, nTimestep, nBlock);
    return new avtGenericDatabase(inter);
}

// ****************************************************************************
//  Method: ProteinDataBankCommonPluginInfo::GetReadOptions
//
//  Purpose:
//      Gets the read options.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

DBOptionsAttributes *
ProteinDataBankCommonPluginInfo::GetReadOptions() const
{
    return GetProteinDataBankReadOptions();
}

// ****************************************************************************
//  Method: ProteinDataBankCommonPluginInfo::GetWriteOptions
//
//  Purpose:
//      Gets the write options.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

DBOptionsAttributes *
ProteinDataBankCommonPluginInfo::GetWriteOptions() const
{
    return GetProteinDataBankWriteOptions();
}

