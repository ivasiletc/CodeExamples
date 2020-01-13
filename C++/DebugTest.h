/*
 *
*/
#pragma once

#include "HumanSkeleton.h"
#include "KeyPointsReader.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugTest.generated.h"

UCLASS()
class SKELETONTEST_API ADebugTest : public AActor, public HumanSkeleton
{
	GENERATED_BODY()

public:
	ADebugTest();

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* VisualMesh;

    UWorld* ThisWorld;

    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    virtual void t_DrawHumanSceleton() override;

private:
    virtual void m_AddStaticMesh();

    virtual void m_DrawLimb(FVector _upperPart, FVector _middlePart, FVector _lowerPart) override;
    virtual void m_DrawBody(FVector _leftShoulder, FVector _rightShoulder, FVector _leftHip, FVector _rightHip) override;
    virtual void m_DrawHead(FVector _nose, FVector _rightEye, FVector _leftEye, FVector _leftEar, FVector _rightEar) override;

};
