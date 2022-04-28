// Fill out your copyright notice in the Description page of Project Settings.


#include "items/AmmoPickup.h"

void AAmmoPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapBegin()"));

    if (OtherActor)
    {
        //ASeagull* Player1 = Cast<ASeagull>(OtherActor);

       /* if (Player1)
        {
            Player1->Ammo += AmmoAdditionCount

        }*/
    }

}

void AAmmoPickup::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

    UE_LOG(LogTemp, Warning, TEXT("Pickup::OnOverlapEnd()"));
}