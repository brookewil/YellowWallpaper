// Fill out your copyright notice in the Description page of Project Settings.


#include "TeddyBear.h"

// Sets default values
ATeddyBear::ATeddyBear()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATeddyBear::BeginPlay()
{
	Super::BeginPlay();

	// destroy after 10 seconds
	SetLifeSpan(10);
	
}

// Called every frame
void ATeddyBear::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

