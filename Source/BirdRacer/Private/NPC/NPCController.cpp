// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/NPCController.h"

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
	GetCheckpoints();


	PlayerSeagull = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (NPCBehavior)
	{
		RunBehaviorTree(NPCBehavior);
		


	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BehaviorTree not loaded!"));
	}
}

void ANPCController::Tick(float DeltaSeconds)
{
	
}

void ANPCController::GetCheckpoints()
{
	ANPCRaceGameMode* NPCMode = Cast<ANPCRaceGameMode>(GetWorld()->GetAuthGameMode());

	CPoint1 = NPCMode->CheckPoint1Location;
	CPoint2 = NPCMode->CheckPoint2Location;
	CPoint3 = NPCMode->CheckPoint3Location;
}
