// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "AmmoPickup.generated.h"

/**
 * 
 */
UCLASS()
class BIRDRACER_API AAmmoPickup : public AItem
{
	GENERATED_BODY()

public:

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
		int AmmoAdditionCount = 5;

};
