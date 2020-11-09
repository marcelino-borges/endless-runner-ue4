// Fill out your copyright notice in the Description page of Project Settings.


#include "Star.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AStar::AStar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStar::BeginPlay()
{
	Super::BeginPlay();

	const TArray<UStaticMeshComponent*> Components;
	Mesh = FindComponentByClass<UStaticMeshComponent>();
	GameMode = Cast<ASidia2GameModeBase>((GetWorld()->GetAuthGameMode()));	
}

// Called every frame
void AStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float XPos = GetActorLocation().X - DeltaTime * GameMode->GameMoveSpeed;
	float YPos = GetActorLocation().Y;
	float ZPos = GetActorLocation().Z;

	SetActorLocation(FVector(XPos, YPos, ZPos));

	if (Mesh)
	{
		Mesh->AddLocalRotation(FQuat::MakeFromEuler(FVector(0.f, 0.f, DeltaTime * RotationSpeed)));
	}

}

