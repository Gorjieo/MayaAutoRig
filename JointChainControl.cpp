#include "JointChainControl.h"

JointChainControl::JointChainControl()
{
}

JointChainControl::JointChainControl(std::string type)
{
	chainType = type;
}

JointChainControl::JointChainControl(std::string type, std::string charName)
{
	chainType = type;
	characterName = charName;
}

JointChainControl::JointChainControl(std::string type, int numJoints)
{
	chainType = type;
	numMainJoints = numJoints;
}

JointChainControl::JointChainControl(std::string type, std::string charName, int numJoints, int numHelper)
{
	chainType = type;
	characterName = charName;
	numMainJoints = numJoints;
	helperNum = numHelper;
}

JointChainControl::~JointChainControl()
{
}

int JointChainControl::getMainJoints()
{
	return numMainJoints;
}

//creates a maya command for things like spines, legs, etc 
std::string JointChainControl::createVerticalControls(std::string rigType, bool vertical, bool symmetry, int offsetx, int offsety, int offsetz, int direction)
{
	std::string command;
	for (int i = 0; i < numMainJoints; ++i) {
		std::string nodeName = (getCharacterName() + getChainType() + std::to_string(i));
		command.append("CreateNURBSCircle; rename " + nodeName + "; move " + std::to_string(offsetx) + " " + std::to_string(offsety + (i * 2 * direction)) + " " + std::to_string(offsetz) + "; ");
		command.append(additionalAttributes(nodeName, rigType, symmetry));
	}
	return command;
}

//creates a maya command for things like arms
std::string JointChainControl::createHorizontalControls(std::string rigType, bool vertical, bool symmetry, int offsetx, int offsety, int offsetz, int direction)
{
	std::string command;
	for (int i = 0; i < numMainJoints; ++i) {
		std::string nodeName = (getCharacterName() + getChainType() + std::to_string(i));
		command.append("CreateNURBSCircle; rename " + nodeName + "; move " + std::to_string((direction * 2 * i) + offsetx) + " " + std::to_string(offsety) + " " + std::to_string(offsetz) + "; " + (vertical ? "rotate 0 0 90; " : ""));
		command.append(additionalAttributes(nodeName, rigType, symmetry));
	}
	return command;
}

std::string JointChainControl::additionalAttributes(std::string nodeName, std::string rigType, bool symmetry)
{

	std::string attributes;
	attributes.append("addAttr -longName aRAttributes -numberOfChildren 5 -attributeType compound; addAttr -longName aRRigType -dt \"string\" -parent aRAttributes; addAttr -longName aRCharacterName -dt \"string\" -parent aRAttributes; addAttr -longName aRSymmetry -at bool -parent aRAttributes; addAttr -longName aRControlType -dt \"string\" -parent aRAttributes; addAttr -longName aRPreviousStep -at enum -enumName \"Controls:Skeleton:Constraints:Connection\" -parent aRAttributes; ");
	attributes.append("setAttr -lock on \"" + nodeName + ".aRRigType\" -type \"string\" \"" + rigType + "\"; setAttr -lock on \"" + nodeName + ".aRCharacterName\" -type \"string\" \"" + getCharacterName() + "\"; setAttr -lock on \"" + nodeName + ".aRSymmetry\" " + std::to_string(symmetry) + "; setAttr -lock on \"" + nodeName + ".aRControlType\" -type \"string\" \"" + getChainType() + "\"; ");
	return attributes;
}

std::string JointChainControl::getChainType()
{
	return chainType;
}

std::string JointChainControl::getCharacterName()
{
	return characterName;
}

//std::string JointChainControl::createArmControls(int offsetx, int offsety, int offsetz, int direction)
//{
//	std::string command;
//	for (int i = 0; i < numMainJoints; ++i) {
//		std::string nodeName = (getCharacterName() + getChainType() + std::to_string(i));
//		command.append("CreateNURBSCircle; rename " + nodeName + "; move " + std::to_string((direction * 2 * i) + offsetx) + " " + std::to_string(offsety) + " " + std::to_string(offsetz) + ";  rotate 0 0 90; ");
//		command.append(additionalAttributes(nodeName));
//	}
//	return command;
//}

