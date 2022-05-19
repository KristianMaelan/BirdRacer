// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "HoverSeagull.generated.h"

UCLASS()
class BIRDRACER_API AHoverSeagull : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHoverSeagull();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HoverSeagullMesh")
		USkeletalMeshComponent* HoverSeagullMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HoverSeagullMesh")
		USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HoverSeagullMesh")
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HoverSeagullMesh")
		USceneComponent* Root;

	//Movement
	//void MoveForward(float value);
	void MoveSideways(float value);

};
