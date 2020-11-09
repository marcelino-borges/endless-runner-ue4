// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Sidia2GameModeBase.generated.h"

UCLASS()
class SIDIA2_API ASidia2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASidia2GameModeBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
	float GameMoveSpeed = 650.f;
	
};
