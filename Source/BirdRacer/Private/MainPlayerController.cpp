// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "Seagull.h"

AMainPlayerController::AMainPlayerController()
{
	bPauseMenuVisible = false;
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (CountdownAsset)
	{
		Countdown = CreateWidget<UUserWidget>(this, CountdownAsset);
		if (Countdown)
		{
			Countdown->AddToViewport();
			Countdown->SetVisibility(ESlateVisibility::Visible);
		}
	}

	if (WPauseMenu)
	{
		PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);
		if (PauseMenu)
		{
			PauseMenu->AddToViewport();
			PauseMenu->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	if (HUDOverlayAsset)
	{
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
		/*if (HUDOverlay)
		{
			HUDOverlay->AddToViewport();
			HUDOverlay->SetVisibility(ESlateVisibility::Visible);
		}*/
	}
	//HUDOverlay->AddToViewport();
	//HUDOverlay->SetVisibility(ESlateVisibility::Visible);

	if (TotalTimeAsset)
	{
		TotalTimeWidg = CreateWidget<UUserWidget>(this, TotalTimeAsset);
		if (TotalTimeWidg)
		{
			TotalTimeWidg->AddToViewport();
			TotalTimeWidg->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	if (NPCRaceLossAsset)
	{
		NPCRaceLoss = CreateWidget<UUserWidget>(this, NPCRaceLossAsset);
		if (NPCRaceLoss)
		{
			NPCRaceLoss->AddToViewport();
			NPCRaceLoss->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	if (NPCRaceWinAsset)
	{
		NPCRaceWin = CreateWidget<UUserWidget>(this, NPCRaceWinAsset);
		if (NPCRaceWin)
		{
			NPCRaceWin->AddToViewport();
			NPCRaceWin->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void AMainPlayerController::DisplayPauseMenu_Implementation()
{
	if (PauseMenu)
	{
		bPauseMenuVisible = true;
		PauseMenu->SetVisibility(ESlateVisibility::Visible);
	}

	bPauseMenuVisible = true;
	bShowMouseCursor = true;

	FInputModeUIOnly InputModeUIOnly; 
	SetInputMode(InputModeUIOnly);
}

void AMainPlayerController::RemovePauseMenu_Implementation()
{
	if (PauseMenu)
	{
		bPauseMenuVisible = false;
		PauseMenu->SetVisibility(ESlateVisibility::Hidden);
	}

	bPauseMenuVisible = false;
	bShowMouseCursor = false;

	GameModeOnly();
}

void AMainPlayerController::ToggleNPCRaceWin()
{
	NPCRaceWin->SetVisibility(ESlateVisibility::Visible);
}

void AMainPlayerController::ToggleNPCRaceLoss()
{
	NPCRaceLoss->SetVisibility(ESlateVisibility::Visible);
}

void AMainPlayerController::ToggleTotalTime()
{
	TotalTimeWidg->SetVisibility(ESlateVisibility::Visible);
}

void AMainPlayerController::TogglePauseMenu()
{
	if (!bPauseMenuVisible)
	{
		DisplayPauseMenu();
	}

	else
	{
		RemovePauseMenu(); 
	}
}

void AMainPlayerController::GameModeOnly()
{
	FInputModeGameOnly InputModeGameOnly;
	SetInputMode(InputModeGameOnly);
}

void AMainPlayerController::CallHUDOverlay()
{
	//Trenge eg egt denna?
}


