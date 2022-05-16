// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Seagull.h"
#include "GameFramework/GameModeBase.h"
#include "TimeAttackMode.generated.h"

/**
 * 
 */
UCLASS()
class BIRDRACER_API ATimeAttackMode : public AGameModeBase
{
	GENERATED_BODY()


public:
	ATimeAttackMode();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;


	




};
