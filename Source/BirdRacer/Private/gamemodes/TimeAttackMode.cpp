// Fill out your copyright notice in the Description page of Project Settings.


#include "gamemodes/TimeAttackMode.h"
#include "Seagull.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

ATimeAttackMode::ATimeAttackMode()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATimeAttackMode::BeginPlay()
{
	 PlayerGamer = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetPawn());
	 PlayerGamer->ActiveGameMode = 0;

}

void ATimeAttackMode::Tick(float DeltaSeconds)
{
	
}

void ATimeAttackMode::PlayerFinished()
{

	//class FFTFGameInstance* SaveState = Cast<FFTFGameInstance>(GetGameInstance());
	//UGameplayStatics::OpenLevel(GetWorld()->GetFirstPlayerController()->GetPawn(), TEXT("MainMenuLevel"));

	UE_LOG(LogTemp, Warning, TEXT("Player has finished the level!"));


	//ASeagull* PlayerActor = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetPawn());
	//PlayerGamer = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	//PlayerGamer->LevelCompleteLoad();

	//GetWorldTimerManager().SetTimer(FinishLineTimer, this, &ATimeAttackMode::GoToMainMenu, 1.f, false, 5.f);
}

void ATimeAttackMode::GoToMainMenu()
{
	//Wont work, gamemode isnt actor spawned in level, has been moved to Seagull
	//UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenuLevel"));
}
