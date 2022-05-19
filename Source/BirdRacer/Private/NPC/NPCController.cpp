// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/NPCController.h"

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
	


}

void ANPCController::Tick(float DeltaSeconds)
{
	
}
