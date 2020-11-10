// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SidiaCharacter.generated.h"

UCLASS()
class SIDIA2_API ASidiaCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	ASidiaCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float MoveSpeed = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float DamageCooldown = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int MaxHealth = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	int Stars;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	USoundBase* DamageSfx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	bool IsDead = false;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float MaxHorizontalSideMovement = 147.f;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Print(FString text);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

public:	
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable)
	int TakeDamage(int amount);

	UFUNCTION(BlueprintCallable)
	virtual void Die();

	UFUNCTION(BlueprintCallable)
	virtual int CollectStar(int amount);

private:
	FVector HorizontalDirection;

	float Counter = 0.f;

	bool CanTakeDamage = true;


};
