// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SidiaSphere.h"
#include "SidiaSphereSpawn.generated.h"

/**
 * 
 */
UCLASS()
class SIDIA2_API ASidiaSphereSpawn : public ASidiaSphere
{
	GENERATED_BODY()
	
public:
	ASidiaSphereSpawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	TArray<ACharacter*> NPCS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	TSubclassOf<ACharacter> NPC_Model;

public:
	virtual void Interact() override;

	UFUNCTION(BlueprintCallable)
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void RemoveFirstNPC();
};
