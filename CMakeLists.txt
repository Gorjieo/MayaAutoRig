# CMakeList.txt : CMake project for AutoRig, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

#project (AutoRig)
set(PROJECT_NAME AutoRig)

# include the project setting file
include(C:/Users/gorji/devkitBase/cmake/pluginEntry.cmake)

set(SOURCE_FILES PluginMain.cpp JointChainControl.h JointChainControl.cpp ARBaseCharacterControl.h ARBaseCharacterControl.cpp HumanControllerCMD.cpp HumanControllerCMD.h ARHumanControl.cpp ARHumanControl.h)
# SkeletonGeneratorCMD.cpp SkeletonGeneratorCMD.h ARSkeletonGenerator.h ARSkeletonGenerator.cpp


# set linking libraries
set(LIBRARIES
     Foundation     
     OpenMaya
     OpenMayaAnim
     OpenMayaUI
     OpenMayaRender
)

# Build plugin
build_plugin()
