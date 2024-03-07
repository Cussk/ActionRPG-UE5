// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SoulsCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ASoulsCharacter::ASoulsCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASoulsCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
	
}

void ASoulsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASoulsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASoulsCharacter::Move);
	}

	//PlayerInputComponent->BindAxis("MoveForward", this, &ASoulsCharacter::MoveForward);

}

void ASoulsCharacter::Move(const FInputActionValue& Value)
{
	const FVector MoveAxisValue = Value.Get<FVector>();

	if(Controller)
	{
		AddMovementInput(MoveAxisValue, MoveAxisValue.X);
		AddMovementInput(MoveAxisValue, MoveAxisValue.Y);
	}
}


//OLD INPUT SYSTEM

void ASoulsCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.0f)
	{
		FVector ForwardVector = GetActorForwardVector();
		AddMovementInput(ForwardVector, Value);
	}
}

