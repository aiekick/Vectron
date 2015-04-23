// Fill out your copyright notice in the Description page of Project Settings.

#include "VectronPrivatePCH.h"
#include "VectronPrimitive.h"

// Sets default values
AVectronPrimitive::AVectronPrimitive()
{}

AVectronPrimitive::AVectronPrimitive(const class FObjectInitializer& PCIP) : Super(PCIP)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshSpherePrimitive(TEXT("UAsset'/Engine/Content/EngineMeshes/Sphere.uasset'"));

	//primitiveMesh = StaticMeshSpherePrimitive.Object;
	
	primitiveMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Primitive VF Modifier"));
	//primitiveMeshComponent->SetStaticMesh(primitiveMesh);

	SetupSMComponentWithCollision(primitiveMeshComponent);
	
	RootComponent = primitiveMeshComponent;
}

// Called when the game starts or when spawned
void AVectronPrimitive::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVectronPrimitive::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

bool AVectronPrimitive::isVoxelInPrimitive(FVector voxelPosition)
{
	FVector closestCollisionPosition;
	float result = primitiveMeshComponent->GetDistanceToCollision(voxelPosition, closestCollisionPosition);
	if (result == 0.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AVectronPrimitive::reloadPrimitiveSM()
{
	if (primitiveMesh != nullptr)
	{
		SetupSMComponentWithCollision(primitiveMeshComponent);
		primitiveMeshComponent->SetStaticMesh(primitiveMesh);
	}
}
