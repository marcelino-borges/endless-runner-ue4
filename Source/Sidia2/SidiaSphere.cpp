// Fill out your copyright notice in the Description page of Project Settings.


#include "SidiaSphere.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

// Sets default values
ASidiaSphere::ASidiaSphere()
{
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASidiaSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASidiaSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASidiaSphere::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector ASidiaSphere::GetRandomPositionInBounds()
{
	float X = FMath::RandRange(XBounds.GetMin(), XBounds.GetMax());
	float Y = FMath::RandRange(YBounds.GetMin(), YBounds.GetMax());
	CurrentDestination = FVector(X, Y, ZValue);

	return CurrentDestination;
}

void ASidiaSphere::Interact()
{
}

