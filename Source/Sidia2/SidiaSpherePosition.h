// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SidiaSphere.h"
#include "SidiaSpherePosition.generated.h"

/**
 * 
 */
UCLASS()
class SIDIA2_API ASidiaSpherePosition : public ASidiaSphere
{
	GENERATED_BODY()
public:
	ASidiaSpherePosition();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	TArray<AActor*> SpheresInLevel;

public:
	virtual void Interact() override;

	UFUNCTION(BlueprintCallable)
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetSpheresToGetDestination();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	bool MoveToLocation = false;	
};
