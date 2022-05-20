// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCBird.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Seagull.h"
#include "gamemodes/NPCRaceGameMode.h"
#include "NPC/NPCController.h"

// Sets default values
ANPCBird::ANPCBird()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Detection sphere setup
	HitSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PlayerSensingSphere"));
	HitSphere->SetupAttachment(GetRootComponent());
	HitSphere->InitSphereRadius(500.f);

	//Setting movespeed through movement component
	GetCharacterMovement()->MaxWalkSpeed = 500.f;

}

// Called when the game starts or when spawned
void ANPCBird::BeginPlay()
{
	Super::BeginPlay();
	NPCMode = Cast<ANPCRaceGameMode>(GetWorld()->GetAuthGameMode());
	PlayerSeagull = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	AIController = Cast<ANPCController>(GetController());
	if (!AIController) { UE_LOG(LogTemp, Error, TEXT("Controller broke")) };

	HitSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPCBird::OnOverlap);
	HitSphere->OnComponentEndOverlap.AddDynamic(this, &ANPCBird::OnOverlapEnd);
	AIController->GetCheckpoints();

	UE_LOG(LogTemp, Error, TEXT("Enemy spawned"))
}

// Called every frame
void ANPCBird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorRotation(GetActorForwardVector().Rotation());
	/*if (AIController->bUpdateNow)
	{
		UE_LOG(LogTemp, Error, TEXT("UpdateNow true, Running NextLocationupdate"));
		AIController->NextLocationUpdate();
	}*/
}

// Called to bind functionality to input
void ANPCBird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANPCBird::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ANPCBird::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
}



