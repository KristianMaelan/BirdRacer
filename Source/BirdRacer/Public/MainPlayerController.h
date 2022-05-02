// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BIRDRACER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> WPauseMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* PauseMenu;

	bool bPauseMenuVisible;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD") // BlueprintNativeEvent
		void DisplayPauseMenu();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD") // BlueprintNativeEvent
		void RemovePauseMenu();

	void SwitchPauseMenu();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<UUserWidget> WPauseMenu;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	UUserWidget* PauseMenu;

	//bool bPauseMenuVisible;

	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD")
	//	void DisplayPauseMenu();

	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD")
	//	void RemovePauseMenu();

	//void TogglePauseMenu();

protected:
	virtual void BeginPlay() override; 
	
};
