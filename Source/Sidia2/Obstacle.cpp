// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<ASidia2GameModeBase>((GetWorld()->GetAuthGameMode()));
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float xPos = GetActorLocation().X - DeltaTime * GameMode->GameMoveSpeed;
	float yPos = GetActorLocation().Y;
	float zPos = GetActorLocation().Z;

	SetActorLocation(FVector(xPos, yPos, zPos));

}

