#include "ARBaseCharacterControl.h"

//abstract class stores the root node in a map. 
//all characters have a root node but everything else might be different
ARBaseCharacterControl::ARBaseCharacterControl()
{
	JointChainControl root("Root", 0);
	nodeMap.insert(std::pair<std::string,JointChainControl> ("Root", root));
}

ARBaseCharacterControl::ARBaseCharacterControl(std::string charName, std::string charType, bool symmetry)
{
	name = charName;
	type = charType;
	isSymmetrical = symmetry;
	JointChainControl root("Root", charName, 0, 0);
	nodeMap.insert(std::pair < std::string, JointChainControl>("Root", root));
}

std::string ARBaseCharacterControl::getName() const
{
	return name;
}

std::string ARBaseCharacterControl::getType() const
{
	return type;
}

bool ARBaseCharacterControl::getSymmetry() const
{
	return isSymmetrical;
}
