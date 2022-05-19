// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCController.generated.h"

/**
 * 
 */
UCLASS()
class ANPCController : public AAIController
{
	GENERATED_BODY()

public:
		ANPCController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;

private:
	//Selecting behavior tree
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* NPCBehavior{};

	class APawn* PlayerSeagull{};

	class AActor* CPoint1{};
	class AActor* CPoint2{};
	class AActor* CPoint3{};


};
