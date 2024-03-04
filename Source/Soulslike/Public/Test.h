// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test.generated.h"

UCLASS()
class SOULSLIKE_API ATest : public AActor
{
	GENERATED_BODY()
	
public:	
	ATest();
    virtual void Tick(float DeltaTime) override;
    
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
		float Amplitude = 0.25f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.0f;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();

	template<typename T>
	T Avg(T First, T Second);
	
private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;	
};

template <typename T>
T ATest::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
