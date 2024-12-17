// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TeddyBear.h"
#include "Engine/World.h"
#include "TimerManager.h" 

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeddyBearSpawner.generated.h"

UCLASS()
class EXERCISE10_API ATeddyBearSpawner : public AActor
{
	GENERATED_BODY()

private:
	//spawn delay support
	const float MinSpawnDelaySeconds{ 1 };
	const float MaxSpawnDelaySeconds{ 2 };

	//spawn location support
	const float MinSpawnY{ -200 };
	const float MaxSpawnY{ 200 };
	const float MinSpawnX{ 0 };
	const float MaxSpawnX{ 100 };

	// start spawn timer
	void StartSpawnTimer();
	
public:	
	
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "TeddyBear"),
		Category = TeddyBearBlueprints)
		TSubclassOf<ATeddyBear> UGreenTeddyBear;
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "TeddyBear"),
		Category = TeddyBearBlueprints)
		TSubclassOf<ATeddyBear> UPurpleTeddyBear;
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "TeddyBear"),
		Category = TeddyBearBlueprints)
		TSubclassOf<ATeddyBear> UYellowTeddyBear;

	UFUNCTION()
	void SpawnTeddyBear();

public:
	// Sets default values for this actor's properties

	ATeddyBearSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
