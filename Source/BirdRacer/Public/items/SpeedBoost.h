// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "CoreMinimal.h"
#include "SpeedBoost.generated.h"

/**
 * 
 */
UCLASS()
class BIRDRACER_API ASpeedBoost : public AItem
{
	GENERATED_BODY()

public:

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


public:

	//How much the speed increases, can be negative for bad pickups
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
		FVector SpeedBoostValue = FVector(500, 0, 0);

	//Time the boost is active for
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
		int SpeedBoostTime = 5.f;


};
