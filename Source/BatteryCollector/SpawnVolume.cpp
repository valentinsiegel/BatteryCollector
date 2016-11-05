// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "Pickup.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//initialize a spawn volume
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("whereToSpawn"));
	RootComponent = WhereToSpawn;

	// Initialize default spawn delays
	SpawnDelayHigh = 4.5f;
	SpawnDelayLow = 1.0f;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	// Compute the first pickup spawn when volume is spawned
	SpawnDelay = FMath::RandRange(SpawnDelayLow, SpawnDelayHigh);
	// We give a handler corresponding to the timer & a callback to spawn the pickup
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Will return a random point in the volume
FVector ASpawnVolume::GetRandomPointInVolume()
{
	// The origin of the box
	FVector volumeOrigin = WhereToSpawn->Bounds.Origin;
	// The range of the box
	FVector volumeExtend = WhereToSpawn->Bounds.BoxExtent;

	// uses a math lib to return the random point
	return UKismetMathLibrary::RandomPointInBoundingBox(volumeOrigin, volumeExtend);
}

void ASpawnVolume::SpawnPickup()
{
	// Check if we have something to spawn
	if (WhatToSpawn != NULL) {

		// Check if we have a valid word
		UWorld * const World = GetWorld();
		if (World != NULL) {

			// Set the spawn parameters
			FActorSpawnParameters SpawningParams;
			SpawningParams.Owner = this;
			SpawningParams.Instigator = Instigator;

			// We get our random point in volume
			FVector SpawnLocation = GetRandomPointInVolume();

			// Additionnaly sets a random rotation
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::Rand() * 360.0f;
			SpawnRotation.Pitch = FMath::Rand() * 360.0f;
			SpawnRotation.Roll = FMath::Rand() * 360.0f;

			// Finally spawn the Pickup
			APickup* const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawningParams);

			// We reset a spawn timer to spawn the next pickup
			SpawnDelay = FMath::RandRange(SpawnDelayLow, SpawnDelayHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
		
		}
	}
}

