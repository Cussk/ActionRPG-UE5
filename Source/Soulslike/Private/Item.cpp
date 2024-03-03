// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Soulslike/DebugMacros.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	FVector EndLocation = Location + (Forward * 100.0f);

	DRAW_SPHERE_RED(Location);
	DRAW_SPHERE_BLUE(EndLocation);
	DRAW_VECTOR(Location, EndLocation);		
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
			
}

