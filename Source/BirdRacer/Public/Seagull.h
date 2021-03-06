// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Seagull.generated.h"

UCLASS()
class BIRDRACER_API ASeagull : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASeagull();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:

	//Movement
	void MoveForward(float value);
	void MoveSideways(float value);

	// Called when pressed "left ctrl" to look backwards
	void LookBackwards();

	//HUD
	bool bESCPushed;
	void ESCPushed();
	void ESCReleased();

	//Shooting
	void Shoot();

	//bool AbleToMove(float value);

	//Speed
	//int MaxAcceleration = 


public:
	//Laps and checkpoints
	//all checkpoints complete?
	bool bCheckPointsComplete = false;

	//Amount of laps completed. Gets increased by FinishLine, Checked by GameMode.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoint")
		int32 LapsCompleted = 0;

	//Last checkpoint for respawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoint")
		FVector RespawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoint")
		FRotator RespawnRotation;


	//Checkpoints reached bool
	TArray<bool> CheckPointReached;


	//Springarm and camera setup
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SeagullMesh")
		class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SeagullMesh")
		class UCameraComponent* Camera;

	//HUD
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Controller")
		class AMainPlayerController* MainPlayerController;


	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seagull")
		FVector SpeedBoostValue;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seagull")
		int32 Boost;
	void IncrementBoost(int32 Amount);


	//Ammo
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seagull")
		int Ammo = 10;

	//Projectile
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> ActorToSpawn;


	bool bGameCanPlay = true;

	void LapComplete();

	void LevelCompleteLoad();
	FTimerHandle FinishLineTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gamemode")
		int ActiveGameMode = 0;

	FVector CP1Location{};
	FVector CP2Location{};
	FVector CP3Location{};

	void LoadMain();

	//Times pressed ctrl for change of camera angle
	//int TimesPressed = 0;

	//int Timer;

	int32 GameTime{};
	int32 LapTime1{};
	int32 LapTime2{};
	int32 LapTime3{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seagull")
		int32 TotalTime{};

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> TotalTimeAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* TotalTimeWidg;*/



	FTimerHandle TimeAttackTimer;

	void AdvanceTimer();
};
