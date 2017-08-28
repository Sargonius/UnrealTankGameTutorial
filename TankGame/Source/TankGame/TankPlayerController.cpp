// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player doesnt possess a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// Get world location through crosshair
		// If it hits the landscape
		// Aim to this point
	}
	

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Raycast
	// If nothing
		// { return false; }
	// else
		// &HitLocation = something;
		// return true
	OutHitLocation = FVector(1.0);
	return false;
}

// Tick
	// Super
	// AimTowardsCrosshair();