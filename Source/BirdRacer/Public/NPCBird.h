// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCBird.generated.h"

UCLASS()
class BIRDRACER_API ANPCBird : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCBird();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
		class ANPCController* AIController{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
		class USphereComponent* HitSphere{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
		int CurrentCheckpoint = 1;

	class APawn* PlayerSeagull{};

	class ANPCRaceGameMode* NPCMode{};

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);



};
