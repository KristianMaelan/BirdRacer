// Fill out your copyright notice in the Description page of Project Settings.


#include "FallOffTrigger.h"

#include "Seagull.h"

AFallOffTrigger::AFallOffTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &AFallOffTrigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AFallOffTrigger::OnOverlapEnd);
}

void AFallOffTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		if (OtherActor == Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetCharacter()))
		{

			AActor* PlayerActor = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetCharacter());
			if (OtherActor == PlayerActor)
			{
				//UE_LOG(LogTemp, Warning, TEXT("Player has fallen off the map! Respawning at Last checkpoint!"));
				ASeagull* Player1 = Cast<ASeagull>(OtherActor);

				Player1->SetActorLocation(Player1->RespawnLocation);
				Player1->SetActorRotation(Player1->RespawnRotation);
			}
		}
	}
}

void AFallOffTrigger::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{

}