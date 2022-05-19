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

	/*if (WPauseMenu)
	{
		PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);

		if (PauseMenu)
		{
			PauseMenu->AddToViewport();
			PauseMenu->SetVisibility(ESlateVisibility::Hidden);
		}
	}*/

	if (WPauseMenu)
	{
		PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);
		if (PauseMenu)
		{
			PauseMenu->AddToViewport();
			PauseMenu->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void AMainPlayerController::DisplayPauseMenu_Implementation()
{
	/*if (PauseMenu)
	{
		bPauseMenuVisible = true;
		PauseMenu->SetVisibility(ESlateVisibility::Visible);
	}*/

	bPauseMenuVisible = true;
	bShowMouseCursor = true;

	FInputModeGameAndUI InputModeGameAndUI;
	SetInputMode(InputModeGameAndUI); 
}

void AMainPlayerController::RemovePauseMenu_Implementation()
{
	/*if (PauseMenu)
	{
		bPauseMenuVisible = false;
		PauseMenu->SetVisibility(ESlateVisibility::Hidden);
	}*/

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

//void AMainPlayerController::DisplayPauseMenu()
//{
//
//}

//void AMainPlayerController::DisplayPauseMenu_Implementation() 
//{
//	if (PauseMenu)
//	{
//		bPauseMenuVisible = true;
//		PauseMenu->SetVisibility(ESlateVisibility::Visible);
//
//		FInputModeGameAndUI InputModeGameAndUI;
//
//		SetInputMode(InputModeGameAndUI);
//		bShowMouseCursor = true;
//	}
//}
//

//void AMainPlayerController::RemovePauseMenu()
//{
//
//}	

//
//void AMainPlayerController::RemovePauseMenu_Implementation() 
//{
//	if (PauseMenu)
//	{
//		FInputModeGameOnly InputModeGameOnly;
//
//		SetInputMode(InputModeGameOnly);
//		bShowMouseCursor = false;
//
//		bPauseMenuVisible = false;
//		//PauseMenu->SetVisibility(ESlateVisibility::Hidden);
//	}
//}
//
//void AMainPlayerController::SwitchPauseMenu()
//{
//	if (bPauseMenuVisible)
//	{
//		RemovePauseMenu();
//	}
//
//	else
//	{
//		DisplayPauseMenu();
//	}
//}

