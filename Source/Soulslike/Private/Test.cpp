// Fill out your copyright notice in the Description page of Project Settings.


#include "Test.h"
#include "Soulslike/DebugMacros.h"


/*This is a test file for learning UE5 specific syntax*/

ATest::ATest()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATest::BeginPlay()
{
	Super::BeginPlay();

	// UWorld* World = GetWorld();
	//
	// SetActorLocation(FVector(0.f, 0.f, 50.f));
	// SetActorRotation(FRotator(0.f, 45.0f, 0.f));
	//
	// FVector Location = GetActorLocation();
	// FVector Forward = GetActorForwardVector();
	// FVector EndLocation = Location + (Forward * 100.0f);
	//
	// DRAW_SPHERE_RED(Location);
	// DRAW_VECTOR(Location, EndLocation);

	// int32 AvgInt= Avg<int32>(1, 3);
	// UE_LOG(LogTemp, Warning, TEXT("Avg int of 1 and 3: %d"), AvgInt);
	//
	// float AvgFloat = Avg<float>(3.56f, 7.51f);
	// UE_LOG(LogTemp, Warning, TEXT("Avg int of 1 and 3: %f"), AvgFloat);
}

void ATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// float MovementRate = 50.0f;
	// float RotationRate = 45.0f;
	//
	// AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.0f, 0.0f));
	// AddActorWorldRotation(FRotator(0.0f, RotationRate * DeltaTime, 0.0f));

	RunningTime += DeltaTime;
	
	// float DeltaZ = TransformedSin();
	// AddActorWorldOffset(FVector(0.0f, 0.0f, DeltaZ));

	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	FVector EndLocation = Location + (Forward * 100.0f);

	DRAW_SPHERE_SINGLE_FRAME(Location);
	DRAW_VECTOR_SINGLE_FRAME(Location, EndLocation);

	FVector AvgVector = Avg<FVector>(Location, FVector::Zero());
	DRAW_POINT_SINGLE_FRAME(AvgVector);
}

float ATest::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float ATest::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

