// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Weapon.h"

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

void AWeapon::AttachMeshToSocket(USceneComponent* InParent, const FName InSocketName) const
{
	const FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
	StaticMeshComponent->AttachToComponent(InParent, TransformRules, InSocketName);
}

void AWeapon::Equip(USceneComponent* InParent, const FName InSocketName)
{
	AttachMeshToSocket(InParent, InSocketName);
	ItemState = EItemstate::EIS_Equipped;
	
	if(EquipSound)
		UGameplayStatics::PlaySoundAtLocation(this, EquipSound, GetActorLocation(), GetActorRotation());
	
	if (SphereComponent)
		SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AWeapon::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void AWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}
