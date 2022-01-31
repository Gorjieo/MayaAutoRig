#include "ARHumanControl.h"

//default constructor
ARHumanControl::ARHumanControl()
{
	
	JointChainControl spine(("Spine"), 4);
	nodeMap.insert(std::pair < std::string, JointChainControl>("Spine", spine));
	JointChainControl LLeg("LeftLeg");
	nodeMap.insert(std::pair < std::string, JointChainControl>("LeftLeg", LLeg));
	JointChainControl RLeg("RightLeg");
	nodeMap.insert(std::pair < std::string, JointChainControl>("RightLeg", RLeg));
	JointChainControl LArm("LeftArm");
	nodeMap.insert(std::pair < std::string, JointChainControl>("LeftArm", LArm));
	JointChainControl RArm("RightArm");
	nodeMap.insert(std::pair < std::string, JointChainControl>("RightArm", RArm));
	JointChainControl head("Head");
	nodeMap.insert(std::pair < std::string, JointChainControl>("Head", head));

}

ARHumanControl::ARHumanControl(std::string charName, std::string charType, bool symmetry) : ARBaseCharacterControl(charName, charType, symmetry)
{
	JointChainControl spine("Spine", charName, 4, 0);
	nodeMap.insert(std::pair < std::string, JointChainControl>("Spine", spine));
	JointChainControl LLeg("LeftLeg", charName);
	nodeMap.insert(std::pair < std::string, JointChainControl>("LeftLeg", LLeg));
	JointChainControl RLeg("RightLeg", charName);
	nodeMap.insert(std::pair < std::string, JointChainControl>("RightLeg", RLeg));
	JointChainControl LArm("LeftArm", charName);
	nodeMap.insert(std::pair < std::string, JointChainControl>("LeftArm", LArm));
	JointChainControl RArm("RightArm", charName);
	nodeMap.insert(std::pair < std::string, JointChainControl>("RightArm", RArm));
	JointChainControl head("Head", charName);
	nodeMap.insert(std::pair < std::string, JointChainControl>("Head", head));
}

//could not achieve with a switch b/c comparing strings. different joint chains have different numbers of joints
//creates offset so objects are not sitting inside each other in the scene
//only creates left side of character if character is symmetrical. a symmetrical character's right side will be handled in a different step
std::string ARHumanControl::generateControllers()
{
	std::string controllerCommand;
	for (auto controllerGenerator : nodeMap)
	{
		if ((std::get<1>(controllerGenerator).getChainType()) == "Spine") {
			controllerCommand.append((std::get<1>(controllerGenerator).createVerticalControls(this->getType(), false, this->getSymmetry(), 0, 4, 0)));
		}
		else if ((std::get<1>(controllerGenerator).getChainType()) == "LeftLeg") {
			controllerCommand.append((std::get<1>(controllerGenerator).createVerticalControls(this->getType(), false, this->getSymmetry(), 5, 3, 0, -1)));
		}

		else if ((std::get<1>(controllerGenerator).getChainType()) == "RightLeg" && this->getSymmetry() == false) {
			controllerCommand.append((std::get<1>(controllerGenerator).createVerticalControls(this->getType(), false, this->getSymmetry() , -5, 3, 0, -1)));
		}

		else if ((std::get<1>(controllerGenerator).getChainType()) == "LeftArm") {
			controllerCommand.append((std::get<1>(controllerGenerator).createHorizontalControls(this->getType(), true, this->getSymmetry(), 5, 10, 0)));
		}

		else if ((std::get<1>(controllerGenerator).getChainType()) == "RightArm" && this->getSymmetry() == false) {
			controllerCommand.append((std::get<1>(controllerGenerator).createHorizontalControls(this->getType(), true, this->getSymmetry(), -5, 10, 0, -1)));
		}

		else if ((std::get<1>(controllerGenerator).getChainType()) == "Head") {
			controllerCommand.append((std::get<1>(controllerGenerator).createVerticalControls(this->getType(), false, this->getSymmetry(), 0, 12, 0)));
		}

		else {
			controllerCommand.append((std::get<1>(controllerGenerator).createVerticalControls(this->getType(), false, this->getSymmetry(), 0, 0, 0)));

		}
	}
	return controllerCommand;
}

