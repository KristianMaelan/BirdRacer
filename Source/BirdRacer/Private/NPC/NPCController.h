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


	//Get checkpoint locations, 
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC")
	FVector CPoint1{};

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC")
	FVector CPoint2{};

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC")
	FVector CPoint3{};

	bool bUpdateNow = true;

	UFUNCTION(BlueprintCallable)
		void GetCheckpoints();

	UFUNCTION(BlueprintCallable)
		void NextLocationUpdate();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC")
		int LastCheckPoint = 1;


};
