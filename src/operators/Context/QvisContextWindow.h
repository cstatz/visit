// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef QVISCONTEXTWINDOW_H
#define QVISCONTEXTWINDOW_H

#include <QvisOperatorWindow.h>
#include <AttributeSubject.h>

class ContextAttributes;
class QLabel;
class QLineEdit;
class QvisVariableButton;

// ****************************************************************************
// Class: QvisContextWindow
//
// Purpose:
//    Defines QvisContextWindow class.
//
// Notes:      Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class QvisContextWindow : public QvisOperatorWindow
{
    Q_OBJECT
  public:
    QvisContextWindow(const int type,
                         ContextAttributes *subj,
                         const QString &caption = QString::null,
                         const QString &shortName = QString::null,
                         QvisNotepadArea *notepad = 0);
    virtual ~QvisContextWindow();
    virtual void CreateWindowContents();
  protected:
    void UpdateWindow(bool doAll);
    virtual void GetCurrentValues(int which_widget);
  private slots:
    void offsetProcessText();
    void lowProcessText();
    void hiProcessText();
    void contextChanged(const QString &varName);
    void cutoffProcessText();
    void belowProcessText();
    void aboveProcessText();
  private:
    QLineEdit *offset;
    QLineEdit *low;
    QLineEdit *hi;
    QvisVariableButton *context;
    QLineEdit *cutoff;
    QLineEdit *below;
    QLineEdit *above;
    QLabel *offsetLabel;
    QLabel *lowLabel;
    QLabel *hiLabel;
    QLabel *contextLabel;
    QLabel *cutoffLabel;
    QLabel *belowLabel;
    QLabel *aboveLabel;

    ContextAttributes *atts;
};



#endif
