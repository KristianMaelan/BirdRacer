// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "FinishLine.generated.h"

/**
 * 
 */
UCLASS()
class BIRDRACER_API AFinishLine : public ATriggerBox
{
	GENERATED_BODY()


public:
	AFinishLine();


	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);



};
