#pragma once

#include <map>
#include <utility>
#include "JointChainControl.h"

//abstract class from which all future characters will be derived from. Allows for polymorphic character control generation
class ARBaseCharacterControl {
public:
	ARBaseCharacterControl();
	ARBaseCharacterControl(std::string, std::string, bool);
	std::string getName() const;
	std::string getType() const;
	bool getSymmetry() const;
	std::map<std::string, JointChainControl> nodeMap;

	virtual std::string generateControllers() = 0;
private:
	std::string name;
	std::string type;
	bool isSymmetrical;
};