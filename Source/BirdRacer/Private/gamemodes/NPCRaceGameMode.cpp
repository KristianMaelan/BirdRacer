// Fill out your copyright notice in the Description page of Project Settings.


#include "gamemodes/NPCRaceGameMode.h"

#include "Seagull.h"


void ANPCRaceGameMode::BeginPlay()
{
	Super::BeginPlay();

	ASeagull* PlayerGamer = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetPawn());

	PlayerGamer->ActiveGameMode = 1;
}
