/*
 *
*/
#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>

#include "GameFramework/Actor.h"

using json = nlohmann::json;

class SKELETONTEST_API KeyPointsReader
{
public:
	KeyPointsReader();
	~KeyPointsReader();

    //@todo magic number
    static void ReadKeyPointsFromFile(FVector _keyPoints[17]);
};
