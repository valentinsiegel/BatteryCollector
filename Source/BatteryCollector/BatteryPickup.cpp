// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"

ABatteryPickup::ABatteryPickup() {

	getMesh()->SetSimulatePhysics(true);

	BatteryPower = 200.f;
}

void ABatteryPickup::WasCollected_Implementation()
{
	//Calls paren for logging code
	Super::WasCollected_Implementation();
	// Destroy the object
	Destroy();
}

float ABatteryPickup::GetBatteryPower()
{
	return BatteryPower;
}
