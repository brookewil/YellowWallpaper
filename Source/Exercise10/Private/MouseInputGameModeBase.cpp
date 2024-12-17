// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseInputGameModeBase.h"

// Set default values

AMouseInputGameModeBase::AMouseInputGameModeBase()
{
	// set pawn and player controllers

	ConstructorHelpers::FObjectFinder<UClass>
		PawnClass(TEXT("Class'/Game/Exercise10/Blueprints/BP_CharacterPawn.BP_CharacterPawn_C'"));
	if (PawnClass.Object != nullptr)
	{
		DefaultPawnClass = PawnClass.Object;
	}

	ConstructorHelpers::FObjectFinder<UClass>
		ControllerClass(TEXT("Class'/Game/Exercise10/Blueprints/BP_CharacterPlayerController.BP_CharacterPlayerController_C'"));
	if (ControllerClass.Object != nullptr)
	{
		PlayerControllerClass = ControllerClass.Object;
	}
}

