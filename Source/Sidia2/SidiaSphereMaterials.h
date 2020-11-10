// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SidiaSphere.h"
#include "SidiaSphereMaterials.generated.h"

/**
 * 
 */
UCLASS()
class SIDIA2_API ASidiaSphereMaterials : public ASidiaSphere
{
	GENERATED_BODY()
public:
	ASidiaSphereMaterials();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	AActor* FloorReference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	TArray<UMaterialInstance*> MaterialsAvailable;
public:
	virtual void Interact() override;

	UFUNCTION(BlueprintCallable)
	virtual UMaterialInterface* GetRandomMaterial();
	
};
