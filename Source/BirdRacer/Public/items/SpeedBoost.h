// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "SpeedBoost.generated.h"

/**
 * 
 */
UCLASS()
class BIRDRACER_API ASpeedBoost : public AItem
{
	GENERATED_BODY()

public:

	ASpeedBoost();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpeedBoost")
		int32 BoostCount;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


public:

	//How much the speed increases, can be negative for bad pickups
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
		float SpeedBoostValue = 500.f;

	//Time the boost is active for
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
		int SpeedBoostTime = 5.f;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpeedBoost")
		int*/


};
