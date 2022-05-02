// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"


//void AMainPlayerController::BeginPlay()
//{
//	if (WPauseMenu)
//	{
//		PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);
//
//		if (PauseMenu)
//		{
//			PauseMenu->AddToViewport();
//			PauseMenu->SetVisibility(ESlateVisibility::Hidden);
//		}
//	}
//}
//
//
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

