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

	void MoveForward(float value);

	void MoveSideways(float value);

	// Called when pressed "left ctrl" to look backwards
	void LookBackwards();

	//HUD
	bool bESCPushed;
	void ESCPushed();
	void ESCReleased();

	bool AbleToMove(float value);


public:
	bool CheckPointsComplete = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoint")
		int32 LapsCompleted = 0;


<<<<<<< HEAD

=======
>>>>>>> parent of 53147e2 (yeet)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SeagullMesh")
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SeagullMesh")
		class UCameraComponent* Camera;

	//HUD
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Controller")
		class AMainPlayerController* MainPlayerController;

<<<<<<< HEAD

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Seagull")
		FVector SpeedBoostValue;

=======
>>>>>>> parent of 53147e2 (yeet)




};
