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
	MoveDistance = (GlobalStartLocation - GlobalTargetLocation).Size();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
			
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

		FVector Location = GetActorLocation();
		float Distance = (GlobalTargetLocation - Location).Size();
		float TravelledDistance = (Location - GlobalStartLocation).Size();
		if (TravelledDistance >= MoveDistance)
		{
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}
		Location += Direction * Speed*DeltaTime;
		SetActorLocation(Location);


		UE_LOG(LogTemp, Warning, TEXT("Move Distance: %d, Travelled Distance : %d,Current Distance : %d!!"), MoveDistance, TravelledDistance, Distance); 
	}
}
