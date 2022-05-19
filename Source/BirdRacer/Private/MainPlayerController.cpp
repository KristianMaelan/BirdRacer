// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"

AMainPlayerController::AMainPlayerController()
{
	bPauseMenuVisible = false;
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (WPauseMenu)
	{
		PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);
		if (PauseMenu)
		{
			PauseMenu->AddToViewport();
			PauseMenu->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	if (WHUDOverlay)
	{
		HUDOverlay = CreateWidget<UUserWidget>(this, WHUDOverlay);
		if (HUDOverlay)
		{
			HUDOverlay->AddToViewport();
			HUDOverlay->SetVisibility(ESlateVisibility::Visible);
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


