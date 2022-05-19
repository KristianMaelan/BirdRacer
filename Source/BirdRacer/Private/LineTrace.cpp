// Fill out your copyright notice in the Description page of Project Settings.


#include "LineTrace.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ALineTrace::ALineTrace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALineTrace::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALineTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult* Hit = new FHitResult();
	FVector Start = GetActorLocation();
	FVector End = Start + FVector(1000, 0, 0);

	GetWorld()->LineTraceSingleByChannel(*Hit, Start, End, ECC_Visibility);
	if (Hit)
	{
		UKismetSystemLibrary::DrawDebugLine(GetWorld(), Start, Hit->Location, FColor(100, 0, 0));
		UKismetSystemLibrary::DrawDebugSphere(GetWorld(), Hit->Location, 5, 5, FLinearColor::White);
	}
	else
	{
		UKismetSystemLibrary::DrawDebugLine(GetWorld(), Start, End, FColor(100, 0, 0));
		UKismetSystemLibrary::DrawDebugSphere(GetWorld(), End, 5, 5, FLinearColor::White);
	}

}

