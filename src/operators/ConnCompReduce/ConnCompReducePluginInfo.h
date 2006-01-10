// ************************************************************************* //
//  File: ConnCompReducePluginInfo.h
// ************************************************************************* //

#ifndef CONNCOMPREDUCE_PLUGIN_INFO_H
#define CONNCOMPREDUCE_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class ConnCompReduceAttributes;

// ****************************************************************************
//  Class: ConnCompReducePluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an ConnCompReduce operator
//
//  Programmer: whitlocb -- generated by xml2info
//  Creation:   Fri Jan 6 18:12:21 PST 2006
//
//  Modifications:
//
// ****************************************************************************

class ConnCompReduceGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
    virtual bool  EnabledByDefault() const;
};

class ConnCompReduceCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual ConnCompReduceGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class ConnCompReduceGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual ConnCompReduceCommonPluginInfo
{
  public:
    virtual const char *GetMenuName() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, QvisNotepadArea *notepad);
};

class ConnCompReduceViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual ConnCompReduceCommonPluginInfo
{
  public:
    virtual AttributeSubject *GetClientAtts();
    virtual AttributeSubject *GetDefaultAtts();
    virtual void SetClientAtts(AttributeSubject *atts);
    virtual void GetClientAtts(AttributeSubject *atts);

    virtual void InitializeOperatorAtts(AttributeSubject *atts,
                                        const ViewerPlot *plot,
                                        const bool fromDefault);

    static void InitializeGlobalObjects();
  private:
    static ConnCompReduceAttributes *defaultAtts;
    static ConnCompReduceAttributes *clientAtts;
};

class ConnCompReduceEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual ConnCompReduceCommonPluginInfo
{
  public:
    virtual avtPluginFilter *AllocAvtPluginFilter();
};

class ConnCompReduceScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual ConnCompReduceCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, void *data);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual char *GetLogString();
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
