// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "CountDownTimer.generated.h"

UCLASS()
class BIRDRACER_API ACountDownTimer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountDownTimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//My stuff
public:
	int32 CountdownTime;
	UTextRenderComponent* CountdownText{ nullptr };

	void UpdateTimerDisplay();

	void AdvanceTimer();

	void CountdownHasFinished();

	FTimerHandle CountdownTimerHandle;

	UPROPERTY(EditAnywhere)
		USoundBase* CountDownSound {nullptr};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
		TArray<UStaticMeshComponent*> Sprites;


};
