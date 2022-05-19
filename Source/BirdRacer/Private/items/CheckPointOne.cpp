// Fill out your copyright notice in the Description page of Project Settings.

#include "items/CheckPointOne.h"
#include "Seagull.h"

void ACheckPointOne::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    //Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);


    //UE_LOG(LogTemp, Warning, TEXT("Check point passed"));
    

    if (OtherActor)
    {
        ASeagull* Player1 = Cast<ASeagull>(OtherActor);
        if (Player1)
        {
            //Sets checkpoint as reached and adds it as the respawn location;
            Player1->CheckPointReached[CheckPointNumber] = true;
            Player1->RespawnLocation = GetActorLocation();
            Player1->RespawnRotation = Player1->GetActorRotation();

        	//Sets all checkpoints as reached for a lap to complete

        	if (CheckPointNumber == CheckPointsForLap)
		    {
                Player1->bCheckPointsComplete = true;
		    }
        }
    }
}

void ACheckPointOne::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    //Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

    //UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapEnd()"));
}

void ACheckPointOne::LocationForNPC()
{
	
}
