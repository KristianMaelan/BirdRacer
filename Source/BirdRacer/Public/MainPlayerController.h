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

	//class AMainPlayerController(const FObjectInitializer& ObjectInitializer);

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<class UUserWidget> WPauseMenu;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	UUserWidget* PauseMenu;

	//bool bPauseMenuVisible;

	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD") // BlueprintNativeEvent
	//	void DisplayPauseMenu();

	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD") // BlueprintNativeEvent
	//	void RemovePauseMenu();

	//void SwitchPauseMenu();

	AMainPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> CountdownAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* Countdown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> WPauseMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* PauseMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> HUDOverlayAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* HUDOverlay; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> TotalTimeAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* TotalTimeWidg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> NPCRaceLossAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* NPCRaceLoss;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> NPCRaceWinAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* NPCRaceWin;

	UFUNCTION(BlueprintCallable)
		void ToggleNPCRaceWin();

	UFUNCTION(BlueprintCallable)
		void ToggleNPCRaceLoss();

	UFUNCTION(BlueprintCallable)
		void ToggleTotalTime();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
	bool bPauseMenuVisible;

	UFUNCTION(BlueprintNativeEvent)
	void DisplayPauseMenu();

	UFUNCTION(BlueprintNativeEvent)
	void RemovePauseMenu();

	UFUNCTION(BlueprintCallable)
	void TogglePauseMenu();

	UFUNCTION(BlueprintCallable)
	void CallHUDOverlay();

	void GameModeOnly();

protected:
	virtual void BeginPlay() override; 
	

public:

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<UUserWidget> WPauseMenu;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	UUserWidget* PauseMenu;

	//bool bPauseMenuVisible;

	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD") // BlueprintNativeEvent
	//	void DisplayPauseMenu();
	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "HUD") // BlueprintNativeEvent
	//	void RemovePauseMenu();

	//void SwitchPauseMenu();

protected:
	//virtual void BeginPlay() override; 
	

};
