// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SidiaSphere.generated.h"

UCLASS()
class SIDIA2_API ASidiaSphere : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASidiaSphere();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	FVector2D XBounds = FVector2D(-1830.0f, 940.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	FVector2D YBounds = FVector2D(-1336.0f, 1403.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	FVector CurrentDestination;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float ZValue = 240.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	UStaticMeshComponent* StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	virtual FVector GetRandomPositionInBounds();

	UFUNCTION(BlueprintCallable)
	virtual void Interact();

};
