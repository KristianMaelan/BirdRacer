// Fill out your copyright notice in the Description page of Project Settings.


#include "items/SpeedBoost.h"
#include "Seagull.h"

ASpeedBoost::ASpeedBoost()
{
    BoostCount = 1;
}

void ASpeedBoost::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapBegin()"));

    if (OtherActor)
    {
       ASeagull* Player1 = Cast<ASeagull>(OtherActor);

       if (Player1)
       {
           
           Player1->IncrementBoost(BoostCount); 

           //Adding multiplier for boost after pickup

       }
    }

}

void ASpeedBoost::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

    UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapEnd()"));
}