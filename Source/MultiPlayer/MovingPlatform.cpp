// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);//only on server 		
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ActiveTriggers > 0) 
	{
		if (HasAuthority())
		{
			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			FVector Location = GetActorLocation();
			float Distance = (GlobalStartLocation - GlobalTargetLocation).Size();
			float TravelledDistance = (Location - GlobalStartLocation).Size();
			if (TravelledDistance >= Distance)
			{
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;
			}
			Location += Direction * Speed*DeltaTime;
			SetActorLocation(Location);
		}
	}

}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}
