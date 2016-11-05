// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Provides a spawn box
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	// Provides a random point in spawn box to spawn objects. 
	// BlueprintPure garantee no side effects thus can be called from blueprint (implies blueprint callable)
	UFUNCTION(BlueprintPure, Category = "Spawing")
	FVector GetRandomPointInVolume();

protected:

	// Holds a Pickup to spawn
	// EditAnywhere means can be modified from property window
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

	// Identify the spawn timer for the object
	FTimerHandle SpawnTimer;

	// Highest spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayHigh;

	// Lowest spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayLow;

private:

	// Variable containing a spawn box
	// VisibleAnywhere means accessible but not editable from property window, BlueprintReadOnly = cannot be modified by blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;

	void SpawnPickup();

	float SpawnDelay;
};
