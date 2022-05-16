// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FFTFGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BIRDRACER_API UFFTFGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "instance")
		bool bNPCRaceUnlocked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "instance")
		float TimeAttackRecord = 10.f;



};
