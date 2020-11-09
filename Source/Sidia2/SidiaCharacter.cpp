// Fill out your copyright notice in the Description page of Project Settings.


#include "SidiaCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/Engine.h"
#include "Sidia2GameModeBase.h"

// Sets default values
ASidiaCharacter::ASidiaCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	FollowCamera->AspectRatio = 0.475f;
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASidiaCharacter::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	CanTakeDamage = true;	
}

// Called every frame
void ASidiaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsDead)
	{
		float axis = GetInputAxisValue("MoveRight");

		float xPos = GetActorLocation().X;
		float yPos = FMath::Clamp(GetActorLocation().Y, -MaxHorizontalSideMovement, MaxHorizontalSideMovement) + DeltaTime * MoveSpeed * axis;
		float zPos = GetActorLocation().Z;
		SetActorLocation(FVector(xPos, yPos, zPos));
	}

	if (!CanTakeDamage)
	{
		Counter += DeltaTime;

		if (Counter == DamageCooldown)
		{
			CanTakeDamage = true;
			Counter = 0;
		}
	}
}

// Called to bind functionality to input
void ASidiaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up gameplay key bindings
	check(PlayerInputComponent);

	//PlayerInputComponent->BindAxis("MoveForward", this, &ASidiaTestCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASidiaCharacter::MoveRight);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASidiaCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASidiaCharacter::TouchStopped);

}

void ASidiaCharacter::Print(FString text)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, text);
}

void ASidiaCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ASidiaCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

int ASidiaCharacter::TakeDamage(int amount)
{
	if (!IsDead && CanTakeDamage)
	{
		CanTakeDamage = false;
		CurrentHealth -= amount;

		if (CurrentHealth <= 0)
			Die();
	}

	return CurrentHealth;
}

void ASidiaCharacter::Die()
{
	IsDead = true;
	ASidia2GameModeBase* GameMode = Cast<ASidia2GameModeBase>((GetWorld()->GetAuthGameMode()));

	GameMode->GameMoveSpeed = 0.f;
}

int ASidiaCharacter::CollectStar(int amount)
{
	Stars += amount;
	return Stars;
}

void ASidiaCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value, true);
	}
}

void ASidiaCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		HorizontalDirection = Direction * Value;
	}
}

