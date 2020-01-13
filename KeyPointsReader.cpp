/*
 *
*/
#include "KeyPointsReader.h"

KeyPointsReader::KeyPointsReader()
{
}

KeyPointsReader::~KeyPointsReader()
{
}

void KeyPointsReader::ReadKeyPointsFromFile(FVector _keyPoints[17])
{
    //@todo hardcode path
    std::ifstream inputFile("E:\\UE4_Proj_E\\SkeletonTest\\Source\\SkeletonTest\\Input.json");

    if (!inputFile)
    {
        UE_LOG(LogTemp, Warning, TEXT("######   Unable to open file   ######"));
    }

    json j;
    inputFile >> j;
    auto keyPoints = j.get<std::unordered_map<std::string, json>>();

    int index = 0;
    for (auto i : keyPoints["keypoints"])
    {
        //std::cout << i["position"]["x"] << endl;
        _keyPoints[index].X = i["position"]["x"];
        _keyPoints[index].Y = 0;
        _keyPoints[index].Z = 500 - i["position"]["y"];
        index++;
    }
}
