#pragma once

#include <string>
#include <list>

#include <maya/MFn.h>
#include <maya/MDagPath.h>
#include <maya/MString.h>
#include <maya/MDGModifier.h>
#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>
#include <maya/MSelectionList.h>
#include <maya/MItSelectionList.h>
#include <maya/MDagPath.h>
#include <maya/MFnNurbsCurve.h>
#include <maya/MPoint.h>
#include <maya/MArgList.h>
#include <maya/MSyntax.h>
#include <maya/MArgDatabase.h>
#include <maya/MDGModifier.h>

//Generates controls for any type of limb.
//Users reposition controls within the maya scene that will then be accessed by another script
class JointChainControl 
{
public:
	JointChainControl();
	JointChainControl(std::string);
	JointChainControl(std::string, std::string);
	JointChainControl(std::string, int);
	JointChainControl(std::string, std::string, int, int);
	~JointChainControl();
	int getMainJoints();
	
	virtual std::string createHorizontalControls(std::string, bool, bool, int = 0, int = 0, int = 0, int = 1);
	virtual std::string createVerticalControls(std::string, bool, bool, int = 0, int = 0, int = 0, int = 1);
	virtual std::string additionalAttributes(std::string, std::string, bool);

	std::string getChainType();
	std::string getCharacterName();

private:
	std::string chainType = "custom";
	std::string characterName = "";
	int numMainJoints = 3;


	//not yet implemented. "Helper" joints are optional joints added between main joints for more control
	int helperNum = 0;

};
