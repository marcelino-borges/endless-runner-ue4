// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Star.h"
#include "Obstacle.h"
#include "Sidia2GameModeBase.h"
#include "PlatformUnit.generated.h"

UCLASS()
class SIDIA2_API APlatformUnit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformUnit();

protected:
	virtual void BeginPlay() override;

	void Print(FString text);

	FVector StartPosition;

	ASidia2GameModeBase* GameMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float MoveSpeed = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	TArray<USceneComponent*> ObstaclesPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	TArray<USceneComponent*> StarsPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	TArray<TSubclassOf<AObstacle>> ObstacleModel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	TSubclassOf<AStar> StarModel;

	const float YBound = 111.f;

	UFUNCTION(BlueprintCallable)
	void InstantiateAll();

	UFUNCTION(BlueprintCallable)
	void InstantiateObstacles();

	UFUNCTION(BlueprintCallable)
	void InstantiateStars();

	int SortInt(int min, int max);

public:	
	virtual void Tick(float DeltaTime) override;

};
