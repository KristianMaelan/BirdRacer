// Fill out your copyright notice in the Description page of Project Settings.


#include "gamemodes/TimeAttackMode.h"

#include "Seagull.h"
#include "Kismet/GameplayStatics.h"

ATimeAttackMode::ATimeAttackMode()
{
	
}

void ATimeAttackMode::BeginPlay()
{
	ASeagull* PlayerSeagull = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetPawn());


}

void ATimeAttackMode::Tick(float DeltaSeconds)
{
	
}
