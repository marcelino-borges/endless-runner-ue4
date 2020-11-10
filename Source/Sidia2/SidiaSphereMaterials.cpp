// Fill out your copyright notice in the Description page of Project Settings.


#include "SidiaSphereMaterials.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"

ASidiaSphereMaterials::ASidiaSphereMaterials()
{
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ASidiaSphereMaterials::Interact()
{
	Super::Interact();

	if (FloorReference)
	{
		AStaticMeshActor* SMActor = Cast<AStaticMeshActor>(FloorReference);
		SMActor->GetStaticMeshComponent()->SetMaterial(0, MaterialsAvailable[0]);
	}
}

UMaterialInterface* ASidiaSphereMaterials::GetRandomMaterial()
{
	return MaterialsAvailable[FMath::RandRange(0, MaterialsAvailable.Num() - 1)];
}
