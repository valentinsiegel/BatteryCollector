// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"

ABatteryPickup::ABatteryPickup() {

	getMesh()->SetSimulatePhysics(true);
}

void ABatteryPickup::WasCollected_Implementation()
{
	//Calls paren for logging code
	Super::WasCollected_Implementation();
	// Destroy the object
	Destroy();
}
