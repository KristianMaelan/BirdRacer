// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/NPCController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "gamemodes/NPCRaceGameMode.h"
#include "Kismet/GameplayStatics.h"


ANPCController::ANPCController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void ANPCController::BeginPlay()
{
	Super::BeginPlay();


	PlayerSeagull = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	//Setting up and fixing behaviorTree, also sets the locations of the checkpoints
	if (NPCBehavior)
	{
		RunBehaviorTree(NPCBehavior);
		UE_LOG(LogTemp, Error, TEXT("Enemy Behavior loaded"))
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BehaviorTree not loaded!"));
	}
}

void ANPCController::Tick(float DeltaSeconds)
{
	//bUpdateNow = GetBlackboardComponent()->GetValueAsBool(TEXT("UpdateNext"));

}

void ANPCController::GetCheckpoints()
{
	UE_LOG(LogTemp, Error, TEXT("GetCheckpoints called"));
	ANPCRaceGameMode* NPCMode = Cast<ANPCRaceGameMode>(GetWorld()->GetAuthGameMode());

	CPoint1 = NPCMode->CheckPoint1Location;
	CPoint2 = NPCMode->CheckPoint2Location;
	CPoint3 = NPCMode->CheckPoint3Location;

	GetBlackboardComponent()->SetValueAsVector(TEXT("CP1"), CPoint1);
	GetBlackboardComponent()->SetValueAsVector(TEXT("CP2"), CPoint2);
	GetBlackboardComponent()->SetValueAsVector(TEXT("CP3"), CPoint3);
}

void ANPCController::NextLocationUpdate()
{
	GetBlackboardComponent()->SetValueAsBool(TEXT("UpdateNext"), false);
	if (LastCheckPoint == 1)
	{
		UE_LOG(LogTemp, Error, TEXT("Next Checkpoint is 2"));
		GetBlackboardComponent()->SetValueAsVector(TEXT("NextLocation"), CPoint2);
		GetBlackboardComponent()->SetValueAsBool(TEXT("UpdateNext"), false);
		LastCheckPoint = 2;
	}
	else if (LastCheckPoint == 2)
	{
		GetBlackboardComponent()->SetValueAsVector(TEXT("NextLocation"), CPoint3);
		LastCheckPoint = 3;
	}
	else if (LastCheckPoint == 3)
	{
		GetBlackboardComponent()->SetValueAsVector(TEXT("NextLocation"), CPoint1);
		LastCheckPoint = 1;
	}
	else if (!LastCheckPoint)
	{
		UE_LOG(LogTemp, Error, TEXT("No next checkpoint!"));
	}
	UE_LOG(LogTemp, Error, TEXT("Checkpoint2 ->"), *CPoint1.ToString());
}

