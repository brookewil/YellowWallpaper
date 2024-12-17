// Fill out your copyright notice in the Description page of Project Settings.

#include "TeddyBearSpawner.h"


// Sets default values
ATeddyBearSpawner::ATeddyBearSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATeddyBearSpawner::BeginPlay()
{
	Super::BeginPlay();

	StartSpawnTimer();
	
}

// Called every frame
void ATeddyBearSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Spawns a teddy bear
void ATeddyBearSpawner::SpawnTeddyBear()
{
	// randomly pick teddy bear to spawn
	TSubclassOf<ATeddyBear> SpawnTeddyBear;
	int TeddyBearNumber = FMath::RandRange(0, 2);
	if (TeddyBearNumber == 0) {
		SpawnTeddyBear = UGreenTeddyBear;
	}
	else if (TeddyBearNumber == 1) {
		SpawnTeddyBear = UPurpleTeddyBear;
	}
	else {
		SpawnTeddyBear = UYellowTeddyBear;
	}

	// generate random spawn location
	FVector SpawnLocation{ 0 };
	SpawnLocation.SetComponentForAxis(EAxis::Y,
		FMath::RandRange(MinSpawnY, MaxSpawnY));
	SpawnLocation.SetComponentForAxis(EAxis::X,
		FMath::RandRange(MinSpawnX, MaxSpawnX));

	//Spawn teddy bear
	GetWorld()->SpawnActor<ATeddyBear>(
		SpawnTeddyBear, SpawnLocation,
		FRotator::ZeroRotator);

	// start timer again
	StartSpawnTimer();
}

// starts spawn timer
void ATeddyBearSpawner::StartSpawnTimer()
{
	// set random duration and start timer
	float TimerDuration = FMath::RandRange(
		MinSpawnDelaySeconds, MaxSpawnDelaySeconds);
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this,
		&ATeddyBearSpawner::SpawnTeddyBear,
		TimerDuration);
}

