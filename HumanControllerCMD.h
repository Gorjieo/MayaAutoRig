#pragma once
#include "ARHumanControl.h"

//custom Maya command, inherits from a maya api class.
//creates a human character control object and passes arguments in from the maya command line
//provides undo/redo functionality
class HumanControllerCMD : public MPxCommand
{
public:
	virtual MStatus doIt(const MArgList&);
	virtual MStatus undoIt();
	virtual MStatus redoIt();
	virtual bool isUndoable() const { return true; }

	static void* creator() { return new HumanControllerCMD; }
	static MSyntax newSyntax();

private:
	MDGModifier dgMod;

};