// Fill out your copyright notice in the Description page of Project Settings.


#include "SidiaSphereSpawn.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h"

ASidiaSphereSpawn::ASidiaSphereSpawn()
{
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ASidiaSphereSpawn::Interact()
{
	Super::Interact();

	if (NPC_Model)
	{
		FActorSpawnParameters SpawnParams;
		ACharacter* Actor = (ACharacter*)GetWorld()->SpawnActor<AActor>(NPC_Model, FVector(-400.f, 0.f, 240.f), FRotator(0.f, 0.f, 0.f), SpawnParams);

		if (Actor)
			NPCS.Add(Actor);

		if (NPCS.Num() > 10)
		{
			RemoveFirstNPC();
		}
	}
}

void ASidiaSphereSpawn::BeginPlay()
{
	Super::BeginPlay();
}

void ASidiaSphereSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASidiaSphereSpawn::RemoveFirstNPC()
{
	ACharacter* Actor = NPCS[0];

	NPCS.Remove(Actor);

	Actor->Destroy();
}
