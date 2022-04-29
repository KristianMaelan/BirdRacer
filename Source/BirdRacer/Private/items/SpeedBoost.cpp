// Fill out your copyright notice in the Description page of Project Settings.

#include "items/SpeedBoost.h"
#include "Seagull.h"

void ASpeedBoost::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, TEXT("You picked up a speed boost!"));

    if (OtherActor)
    {
       ASeagull* Player1 = Cast<ASeagull>(OtherActor);

       if (Player1)
       {
           Player1->SpeedBoostTime = SpeedBoostTime;
           Player1->SpeedBoostValue = SpeedBoostValue;
       }
    }

}

void ASpeedBoost::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

    //UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapEnd()"));
}