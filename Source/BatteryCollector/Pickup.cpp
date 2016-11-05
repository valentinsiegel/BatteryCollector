// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "Pickup.h"


// Sets default values
APickup::APickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//create the mesh
	pickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("pickupMesh"));
	RootComponent = pickupMesh;

	//pickup is active by default
	isActivated = true;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APickup::isActive()
{
	return isActivated;
}

void APickup::setActive(bool newState)
{
	isActivated = newState;
}

void APickup::WasCollected_Implementation()
{
	// Get the name of the object
	FString PickupDebugString = GetName();
	// Prints a log with name of the object
	UE_LOG(LogClass, Log, TEXT("You have collected %s"), *PickupDebugString);
}



