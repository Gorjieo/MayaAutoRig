#pragma once

#include "ARBaseCharacterControl.h"
#include <array>

//character control generator for a bipedal human
class ARHumanControl : public ARBaseCharacterControl {
public:
	ARHumanControl();
	ARHumanControl(std::string, std::string human, bool);

	virtual std::string generateControllers() override;
private:
	std::string human = "Human";
	const std::array<std::string, 7> limbTypes = {"Root", "Spine", "LeftLeg","RightLeg","LeftArm","RightArm","Head"};

};