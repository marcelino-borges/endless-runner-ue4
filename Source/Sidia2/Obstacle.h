// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sidia2GameModeBase.h"
#include "Obstacle.generated.h"

UCLASS()
class SIDIA2_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AObstacle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int damage;

	ASidia2GameModeBase* GameMode;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float MoveSpeed = 10.f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
