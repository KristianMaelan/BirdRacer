// Fill out your copyright notice in the Description page of Project Settings.

#include "FinishLine.h"
#include "Seagull.h"

AFinishLine::AFinishLine()
{
	OnActorBeginOverlap.AddDynamic(this, &AFinishLine::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AFinishLine::OnOverlapEnd);
}


void AFinishLine::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		if (OtherActor == Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetPawn()))
		{
			
		AActor* PlayerActor = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (OtherActor == PlayerActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("FINISH LINE PASSED"));
			ASeagull* Player1 = Cast<ASeagull>(OtherActor);

			if (Player1->bCheckPointsComplete)
			{
				Player1->LapsCompleted += 1;
			}
		}
		}
		/*
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
