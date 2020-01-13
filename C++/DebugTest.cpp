/*
 *
*/
#include "DebugTest.h"

ADebugTest::ADebugTest()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

    // Make object visible by adding mesh to it.
    m_AddStaticMesh();

    KeyPointsReader::ReadKeyPointsFromFile(m_keyPoints);

    ADebugTest::t_DrawHumanSceleton();
}

void ADebugTest::m_AddStaticMesh()
{
    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    VisualMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

    if (CubeVisualAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
        VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
}

// Called when the game starts or when spawned
void ADebugTest::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
//@todo call GetWorld() only once
void ADebugTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    ADebugTest::t_DrawHumanSceleton();
}

void ADebugTest::t_DrawHumanSceleton()
{
    m_DrawLimb(m_keyPoints[5], m_keyPoints[7], m_keyPoints[9]);
    m_DrawLimb(m_keyPoints[6], m_keyPoints[8], m_keyPoints[10]);
    m_DrawLimb(m_keyPoints[11], m_keyPoints[13], m_keyPoints[15]);
    m_DrawLimb(m_keyPoints[12], m_keyPoints[14], m_keyPoints[16]);

    m_DrawBody(m_keyPoints[5], m_keyPoints[6], m_keyPoints[11], m_keyPoints[12]);
    m_DrawHead(m_keyPoints[0], m_keyPoints[1], m_keyPoints[2], m_keyPoints[3], m_keyPoints[4]);
}


void ADebugTest::m_DrawLimb(FVector _upperPart, FVector _middlePart, FVector _lowerPart)
{
    DrawDebugLine(
        GetWorld(),
        _upperPart,
        _middlePart,
        FColor(255, 0, 0),
        false, -1, 0,
        7.333
    );

    DrawDebugLine(
        GetWorld(),
        _middlePart,
        _lowerPart,
        FColor(255, 0, 0),
        false, -1, 0,
        7.333
    );
}

void ADebugTest::m_DrawBody(FVector _leftShoulder, FVector _rightShoulder, FVector _leftHip, FVector _rightHip)
{
    DrawDebugLine(
        GetWorld(),
        _leftShoulder,
        _rightShoulder,
        FColor(255, 0, 0),
        false, -1, 0,
        7.333
    );

    DrawDebugLine(
        GetWorld(),
        _rightShoulder,
        _rightHip,
        FColor(255, 0, 0),
        false, -1, 0,
        7.333
    );

    DrawDebugLine(
        GetWorld(),
        _rightHip,
        _leftHip,
        FColor(255, 0, 0),
        false, -1, 0,
        7.333
    );

    DrawDebugLine(
        GetWorld(),
        _leftHip,
        _leftShoulder,
        FColor(255, 0, 0),
        false, -1, 0,
        7.333
    );

}

//@todo - make box, not a sphere
void ADebugTest::m_DrawHead(FVector _nose, FVector _rightEye, FVector _leftEye, FVector _leftEar, FVector _rightEar)
{
    DrawDebugSphere(
        GetWorld(),
        _nose,
        3,
        3,
        FColor(255, 0, 0)
    );
    DrawDebugSphere(
        GetWorld(),
        _rightEye,
        3,
        3,
        FColor(255, 0, 0)
    );
    DrawDebugSphere(
        GetWorld(),
        _leftEye,
        3,
        3,
        FColor(255, 0, 0)
    );
    DrawDebugSphere(
        GetWorld(),
        _leftEar,
        3,
        3,
        FColor(255, 0, 0)
    );
    DrawDebugSphere(
        GetWorld(),
        _rightEar,
        3,
        3,
        FColor(255, 0, 0)
    );
}
