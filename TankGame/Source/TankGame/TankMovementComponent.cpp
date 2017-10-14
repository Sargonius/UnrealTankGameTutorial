// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack) && !ensure(RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack) && !ensure(RightTrack)) { 
		//UE_LOG(LogTemp, Warning, TEXT("left %s right %s"), IsValid(LeftTrack) ? "1" : "0", IsValid(RightTrack) ? "1" : "0");
		return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{	
	UE_LOG(LogTemp, Warning, TEXT("left %s right %s"), IsValid(LeftTrack) ? "1" : "0", IsValid(RightTrack) ? "1" : "0");
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	UE_LOG(LogTemp, Warning, TEXT("left %s right %s"), IsValid(LeftTrack) ? "1" : "0", IsValid(RightTrack) ? "1" : "0");
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;

	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow);
	//UE_LOG(LogTemp, Warning, TEXT("%s - Vel: %s"), *Name, *MoveVelocityString)
}




