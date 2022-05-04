// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "CheckPointOne.generated.h"

/**
 * 
 */
UCLASS()
class BIRDRACER_API ACheckPointOne : public AItem
{
	GENERATED_BODY()



public:

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);






	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoint")
		int CheckPointNumber{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoint")
		bool PlayerReached = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoint")
		int CheckPointsForLap = 2;
};
