// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayerController.h"
#include "CharacterPawn.h"

// called to bind functionality to input

void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent != nullptr);
	InputComponent->BindAction("DestroyCharacter",
		EInputEvent::IE_Pressed, this,
		&ACharacterPlayerController::DestroyCharacterPawn);
}

// Called every frame
void ACharacterPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// convert mouse position to world location
	FVector WorldLocation;
	FVector WorldRotation;
	DeprojectMousePositionToWorld(WorldLocation, WorldRotation);

	// move location to y-z plane and move pawn
	WorldLocation.X = 0;
	ACharacterPawn* CharacterPawn =
		(ACharacterPawn*)GetPawn();
	if (CharacterPawn != nullptr)
	{
		CharacterPawn->SetLocation(WorldLocation);
	}
}

// Destroys chaarcter pawn
void ACharacterPlayerController::DestroyCharacterPawn()
{
	ACharacterPawn* CharacterPawn =
		(ACharacterPawn*)GetPawn();
	if (CharacterPawn != nullptr)
	{
		CharacterPawn->Destroy();
	}
}

