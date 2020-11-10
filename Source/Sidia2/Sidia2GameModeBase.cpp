// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "Sidia2GameModeBase.h"
#include "UObject/ConstructorHelpers.h"

ASidia2GameModeBase::ASidia2GameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SidiaTest/Blueprints/SidiaCharacter_BP.SidiaCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

