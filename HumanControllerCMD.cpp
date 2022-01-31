#pragma once
#include "HumanControllerCMD.h"
#include <cstring>

//flags for maya command line arguments
const char* nameFlag = "-n", * nameLongFlag = "-name";
const char* typeFlag = "-t", * typeLongFlag = "-type";
const char* symmetryFlag = "-sym", * symmetryLongFlag = "-symmetry";

//registers flags with maya
MSyntax HumanControllerCMD::newSyntax() {
	MSyntax syntax;

	syntax.addFlag(nameFlag, nameLongFlag, MSyntax::kString);
	syntax.addFlag(typeFlag, typeLongFlag, MSyntax::kString);
	syntax.addFlag(symmetryFlag, symmetryLongFlag, MSyntax::kBoolean);

	return syntax;
}

//creates human controls
MStatus HumanControllerCMD::doIt(const MArgList &args)
{
	MString defaultName = "Jerry";
	MString defaultType = "Human";
	bool defaultSym = false;

	MArgDatabase argData(syntax(), args);

	if (argData.isFlagSet(nameFlag))
		argData.getFlagArgument(nameFlag, 0, defaultName);

	if (argData.isFlagSet(typeFlag))
		argData.getFlagArgument(typeFlag, 0, defaultType);

	if (argData.isFlagSet(symmetryFlag))
		argData.getFlagArgument(symmetryFlag, 0, defaultSym);

	std::string inputName = defaultName.asChar();
	std::string inputType = defaultType.asChar();

	ARHumanControl humanControllerGen = ARHumanControl(inputName, inputType, defaultSym);

	dgMod.commandToExecute(MString(humanControllerGen.generateControllers().c_str()));
	
	return redoIt();
}

//redo functionality
MStatus HumanControllerCMD::redoIt()
{
	return dgMod.doIt();
}

//undo functionality
MStatus HumanControllerCMD::undoIt()
{
	return dgMod.undoIt();
}