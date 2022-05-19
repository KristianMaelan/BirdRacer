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
		TSubclassOf<class UUserWidget> WPauseMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* PauseMenu;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
	bool bPauseMenuVisible;

	UFUNCTION(BlueprintNativeEvent)
	void DisplayPauseMenu();

	UFUNCTION(BlueprintNativeEvent)
	void RemovePauseMenu();

	UFUNCTION(BlueprintCallable)
	void TogglePauseMenu();

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
