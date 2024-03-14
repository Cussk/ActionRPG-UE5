// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SoulsAnimInstance.h"
#include "Characters/SoulsCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void USoulsAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	SoulsCharacter = Cast<ASoulsCharacter>(TryGetPawnOwner());
	if (SoulsCharacter)
	{
		SoulsCharacterMovement = SoulsCharacter->GetCharacterMovement();
	}
}

void USoulsAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (SoulsCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(SoulsCharacterMovement->Velocity);
		bIsFalling = SoulsCharacterMovement-> IsFalling();
		CharacterState = SoulsCharacter->GetCharacterState();
	}
}
