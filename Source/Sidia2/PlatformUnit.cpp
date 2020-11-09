// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformUnit.h"
#include "Engine/Engine.h"
#include "Components/ActorComponent.h"
#include "Obstacle.h"

// Sets default values
APlatformUnit::APlatformUnit()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformUnit::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = GetActorLocation();

	InstantiateAll();
	GameMode = Cast<ASidia2GameModeBase>((GetWorld()->GetAuthGameMode()));
}

// Called every frame
void APlatformUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float xPos = GetActorLocation().X - DeltaTime * GameMode->GameMoveSpeed;
	float yPos = GetActorLocation().Y;
	float zPos = GetActorLocation().Z;

	SetActorLocation(FVector(xPos, yPos, zPos));

}

void APlatformUnit::Print(FString text)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Yellow, text);
}

void APlatformUnit::InstantiateAll()
{
	InstantiateObstacles();
	InstantiateStars();
}

void APlatformUnit::InstantiateObstacles()
{
	if (ObstaclesPoints.IsValidIndex(0))
	{
		for (USceneComponent* Obstacle : ObstaclesPoints)
		{
			//Sorts if instantiates or not
			if (SortInt(0, 1))
				continue;
			FActorSpawnParameters SpawnParams;
			TSubclassOf<AObstacle> SortedModel = ObstacleModel[SortInt(0, ObstacleModel.Num() - 1)];

			//If no star has been referenced, get out of this function
			if (!SortedModel)
				return;

			FVector ObstacleWorldPosition = Obstacle->GetRelativeLocation() + GetActorLocation();
			int Position = SortInt(-1, 1);

			//Ensures position is -1 or 1
			while (Position == 0)
				Position = SortInt(-1, 1);

			ObstacleWorldPosition.Y = YBound * Position;

			AActor* actor = GetWorld()->SpawnActor<AActor>(SortedModel, ObstacleWorldPosition, GetActorRotation(), SpawnParams);
		}
	}
}

void APlatformUnit::InstantiateStars()
{
	if (StarsPoints.IsValidIndex(0))
	{
		for (USceneComponent* Star : StarsPoints)
		{
			//If no star has been referenced, get out of this function
			if (!StarModel)
				return;

			//Sorts if instantiates or not
			if (SortInt(0, 1))
				continue;

			FActorSpawnParameters SpawnParams;
			FVector StarWorldPosition = Star->GetRelativeLocation() + GetActorLocation();

			//Sorts if the star will be spawned on the left, center or right
			int Position = SortInt(-1, 1);

			StarWorldPosition.Y = YBound * Position;

			GetWorld()->SpawnActor<AActor>(StarModel, StarWorldPosition, GetActorRotation(), SpawnParams);
		}
	}
}

int APlatformUnit::SortInt(int Min, int Max)
{
	return FMath::RandRange(Min, Max);
}

