// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include "QvisExternalSurfaceWindow.h"

#include <ExternalSurfaceAttributes.h>

#include <QCheckBox>
#include <QLayout>


// ****************************************************************************
// Method: QvisExternalSurfaceWindow::QvisExternalSurfaceWindow
//
// Purpose: 
//   Constructor
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

QvisExternalSurfaceWindow::QvisExternalSurfaceWindow(const int type,
                         ExternalSurfaceAttributes *subj,
                         const QString &caption,
                         const QString &shortName,
                         QvisNotepadArea *notepad)
    : QvisOperatorWindow(type,subj, caption, shortName, notepad)
{
    atts = subj;
}


// ****************************************************************************
// Method: QvisExternalSurfaceWindow::~QvisExternalSurfaceWindow
//
// Purpose: 
//   Destructor
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

QvisExternalSurfaceWindow::~QvisExternalSurfaceWindow()
{
}


// ****************************************************************************
// Method: QvisExternalSurfaceWindow::CreateWindowContents
//
// Purpose: 
//   Creates the widgets for the window.
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
QvisExternalSurfaceWindow::CreateWindowContents()
{
    QGridLayout *mainLayout = new QGridLayout(0);
    topLayout->addLayout(mainLayout);

    removeGhosts = new QCheckBox(tr("Remove ghost faces?"), central);
    connect(removeGhosts, SIGNAL(toggled(bool)),
            this, SLOT(removeGhostsChanged(bool)));
    mainLayout->addWidget(removeGhosts, 0,0);

    edgesIn2D = new QCheckBox(tr("Find external edges for 2D datasets"), central);
    connect(edgesIn2D, SIGNAL(toggled(bool)),
            this, SLOT(edgesIn2DChanged(bool)));
    mainLayout->addWidget(edgesIn2D, 1,0);

}


// ****************************************************************************
// Method: QvisExternalSurfaceWindow::UpdateWindow
//
// Purpose: 
//   Updates the widgets in the window when the subject changes.
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
QvisExternalSurfaceWindow::UpdateWindow(bool doAll)
{

    for(int i = 0; i < atts->NumAttributes(); ++i)
    {
        if(!doAll)
        {
            if(!atts->IsSelected(i))
            {
                continue;
            }
        }

        switch(i)
        {
          case ExternalSurfaceAttributes::ID_removeGhosts:
            removeGhosts->blockSignals(true);
            removeGhosts->setChecked(atts->GetRemoveGhosts());
            removeGhosts->blockSignals(false);
            break;
          case ExternalSurfaceAttributes::ID_edgesIn2D:
            edgesIn2D->blockSignals(true);
            edgesIn2D->setChecked(atts->GetEdgesIn2D());
            edgesIn2D->blockSignals(false);
            break;
        }
    }
}


// ****************************************************************************
// Method: QvisExternalSurfaceWindow::GetCurrentValues
//
// Purpose: 
//   Gets values from certain widgets and stores them in the subject.
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
QvisExternalSurfaceWindow::GetCurrentValues(int which_widget)
{
}


//
// Qt Slot functions
//


void
QvisExternalSurfaceWindow::removeGhostsChanged(bool val)
{
    atts->SetRemoveGhosts(val);
    SetUpdate(false);
    Apply();
}


void
QvisExternalSurfaceWindow::edgesIn2DChanged(bool val)
{
    atts->SetEdgesIn2D(val);
    SetUpdate(false);
    Apply();
}


