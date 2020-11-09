// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sidia2GameModeBase.h"
#include "Star.generated.h"

UCLASS()
class SIDIA2_API AStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStar();

	ASidia2GameModeBase* GameMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float MoveSpeed = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int Value = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float RotationSpeed = 10.f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
