// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "CharacterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class EXERCISE10_API ACharacterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// called to bind functionality to input
	virtual void SetupInputComponent() override;

	// called every frame

	virtual void PlayerTick(float DeltaTime) override;

	// destroys the character pawn
	void DestroyCharacterPawn();
	
};
