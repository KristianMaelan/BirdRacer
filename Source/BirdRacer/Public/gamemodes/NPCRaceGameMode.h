// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NPCRaceGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BIRDRACER_API ANPCRaceGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC")
		FVector CheckPoint1Location = FVector(0, 0, 0);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC")
		FVector CheckPoint2Location = FVector(0, 0, 0);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC")
		FVector CheckPoint3Location = FVector(0, 0, 0);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC")
		float EnemiesKilled = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC")
		float EnemiesToKill = 15;



};
