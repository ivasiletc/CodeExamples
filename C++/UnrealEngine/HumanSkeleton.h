/*
 *
*/
#pragma once

#include <vector>

#include "DrawDebugHelpers.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"


/**
 *
 */
class SKELETONTEST_API HumanSkeleton
{
public:
	HumanSkeleton();
	virtual ~HumanSkeleton();

///  keyPoints id:
///  0	Nose
///  1, 2: Left & Right Eye
///  3, 4 Left & Right Ear
///  5, 6: Left & Right Shoulder
///  7, 8: Left & Right Elbow
///  9, 10: Left & Right Wrist
///  11, 12: Left & Right Hip
///  13, 14: Left & Right Knee
///  15, 16: Left & Right Ankle
    //@todo magic number
    FVector m_keyPoints[17];

protected:
    virtual void t_DrawHumanSceleton() = 0;

private:
    virtual void m_DrawLimb(FVector _upperPart, FVector _middlePart, FVector _lowerPart) = 0;
    virtual void m_DrawBody(FVector _leftShoulder, FVector _RightShoulder, FVector _LeftHip, FVector _rightHip) = 0;
    virtual void m_DrawHead(FVector _nose, FVector _rightEye, FVector _leftEye, FVector _leftEar, FVector _rightEar) = 0;

};
