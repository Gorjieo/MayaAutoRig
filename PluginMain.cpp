#include "HumanControllerCMD.h"
#include <maya/MFnPlugin.h>

//registers the plugin and my custom MEL command with maya
MStatus initializePlugin(MObject obj)
{
	MFnPlugin plugin(obj, "Gordon Straub", "1.0");

	MStatus stat;
	stat = plugin.registerCommand("humanControls", HumanControllerCMD::creator, HumanControllerCMD::newSyntax);
	if (!stat)
		stat.perror("registerCommand failed");

	return stat;
}

MStatus uninitializePlugin(MObject obj)
{
	MFnPlugin plugin(obj);

	MStatus	stat;
	stat = plugin.deregisterCommand("humanControls");
	if (!stat)
		stat.perror("deregisterCommand failed");

	return stat;
}