// Fill out your copyright notice in the Description page of Project Settings.

#include "FinishLine.h"
#include "Seagull.h"
#include "gamemodes/TimeAttackMode.h"
#include "Kismet/GameplayStatics.h"

AFinishLine::AFinishLine()
{
	OnActorBeginOverlap.AddDynamic(this, &AFinishLine::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AFinishLine::OnOverlapEnd);
}


void AFinishLine::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		if (OtherActor == Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetCharacter()))
		{
			
		AActor* PlayerActor = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetCharacter());
		if (OtherActor == PlayerActor)
		{
			//UE_LOG(LogTemp, Warning, TEXT("FINISH LINE PASSED"));
			ASeagull* Player1 = Cast<ASeagull>(OtherActor);

			if (Player1->bCheckPointsComplete)
			{
				UE_LOG(LogTemp, Warning, TEXT("Player has finished a lap!"));
				Player1->RespawnLocation = GetActorLocation();
				Player1->RespawnRotation = Player1->GetActorRotation();
				Player1->LapComplete();


				Player1->LapsCompleted += 1;
			}
			if (Player1->LapsCompleted == 3)
			{
				//JOAKIM, PLZ FIX HUD
				//Loads main menu after the race is complete
				Player1->LevelCompleteLoad();
			}
				
			
		}
		}
		/*
		 //Not sure if this is needed yet
		else if (OtherActor == ABirdNPC)
		{
			ABirdNPC* NPC = Cast<ABirdNPC>(OtherActor);
			if (NPC->CheckPointsComplete)
			{
				NPC->LapsCompleted += 1;
			}
		}*/
	}
}

void AFinishLine::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{

	}
}
