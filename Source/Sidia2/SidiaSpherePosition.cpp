// Fill out your copyright notice in the Description page of Project Settings.


#include "SidiaSpherePosition.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

ASidiaSpherePosition::ASidiaSpherePosition()
{
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ASidiaSpherePosition::Interact()
{
	Super::Interact();

	SetSpheresToGetDestination();

	if (SpheresInLevel.IsValidIndex(0))
	{
		for (AActor* Sphere : SpheresInLevel)
		{
			Sphere->SetActorLocation(GetRandomPositionInBounds());
		}
	}
}

void ASidiaSpherePosition::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASidiaSphere::StaticClass(), SpheresInLevel);

	SetSpheresToGetDestination();
}

void ASidiaSpherePosition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Adapted the Lerping actor location due to my lack of time (see Interact())
}

void ASidiaSpherePosition::SetSpheresToGetDestination()
{
	for (AActor* Sphere : SpheresInLevel)
	{
		ASidiaSphere* SphereCast = Cast<ASidiaSphere>(Sphere);

		if(SphereCast)
			SphereCast->GetRandomPositionInBounds();
	}
}
