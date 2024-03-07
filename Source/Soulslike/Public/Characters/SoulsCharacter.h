// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SoulsCharacter.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class SOULSLIKE_API ASoulsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASoulsCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& Value);

	//OLD INPUT SYSTEM
protected:
	void MoveForward(float Value);
};
