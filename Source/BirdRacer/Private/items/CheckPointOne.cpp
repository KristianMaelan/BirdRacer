// Fill out your copyright notice in the Description page of Project Settings.

#include "Seagull.h"
#include "items/CheckPointOne.h"

void ACheckPointOne::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);


    //UE_LOG(LogTemp, Warning, TEXT("Check point passed"));
    //UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapBegin()"));

    //if (OtherActor)
    //{
    //   ASeagull* Player1 = Cast<ASeagull>(OtherActor);

    //	if (Player1)
    //    {
    //        //ADD Array of Checkpoint bools to player character. 
    //        Player1->CheckPoints[CheckPointNumber] = true;


    //    }

    //}

}

void ACheckPointOne::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    //Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

    //UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapEnd()"));
}