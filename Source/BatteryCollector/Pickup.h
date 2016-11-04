// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Getter for the pickup mesh
	FORCEINLINE class UStaticMeshComponent* getMesh() const { return pickupMesh; } 

	UFUNCTION(BlueprintPure, Category="Pickup")
	bool isActive();

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void setActive(bool newState);

protected:

	//if the pickup can be used
	bool isActivated;

private:

	//Static mesh to represent the pickup object
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* pickupMesh;
	
	
};
