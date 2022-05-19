// Fill out your copyright notice in the Description page of Project Settings.


#include "Seagull.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASeagull::ASeagull()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Springarm
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
    SpringArm->bDoCollisionTest = false;
    SpringArm->SetUsingAbsoluteRotation(false);

    SpringArm->SetRelativeRotation(FRotator(-30.f, 0.f, 0.f));
    SpringArm->TargetArmLength = 1200.f; //1200.f
    SpringArm->bEnableCameraLag = false;
    SpringArm->CameraLagSpeed = 5.f;

    SpringArm->SetupAttachment(GetRootComponent()); //GetRootComponent()


    //Camera
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->bUsePawnControlRotation = false; // Rotate camera based on controller
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    bUseControllerRotationYaw = false;

    SpringArm->bUsePawnControlRotation = false;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritYaw = true;
    SpringArm->bInheritRoll = false;

    //HUD
    bESCPushed = false;

    //Checkpoints and laps
    CheckPointReached.Init(false, 4);

    //Speed, Acceleration and Deceleration
    GetCharacterMovement()->MaxAcceleration = 5000.f;
    GetCharacterMovement()->BrakingDecelerationFlying = 500.f;
    GetCharacterMovement()->MaxFlySpeed = 2000.f;
}

// Called when the game starts or when spawned
void ASeagull::BeginPlay()
{
	Super::BeginPlay();
	
    MainPlayerController = Cast<AMainPlayerController>(GetController());

    GetCharacterMovement()->MovementMode = MOVE_Flying;
    

}

// Called every frame
void ASeagull::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

   //int Timer =+ GetWorld()->GetDeltaSeconds(); 

}

// Called to bind functionality to input
void ASeagull::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ASeagull::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveSideways"), this, &ASeagull::MoveSideways);

    PlayerInputComponent->BindAction("LookBackwards", IE_Pressed, this, &ASeagull::LookBackwards);

    PlayerInputComponent->BindAction("ESC", IE_Pressed, this, &ASeagull::ESCPushed);
    PlayerInputComponent->BindAction("ESC", IE_Released, this, &ASeagull::ESCReleased);

    PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &ASeagull::Shoot);
}

//bool ASeagull::AbleToMove(float value)
//{
//    if (MainPlayerController)
//    {
//        return (value != 0.0f) && (!MainPlayerController->bPauseMenuVisible);
//    }
//
//    return false;
//}

void ASeagull::MoveForward(float value)
{
        if (bGameCanPlay)
        {

            //if (AbleToMove(value))
            {
                FVector Direction = GetActorForwardVector();
                AddMovementInput(Direction, value);

                //AddActorLocalOffset

            }
        }
}

void ASeagull::MoveSideways(float value)
{
    float TurnSpeed = value * 2; //Multiply by wanted quantity

	if (bGameCanPlay)
	{
		
    //if (AbleToMove(value))
    {
        AddActorLocalRotation(FRotator(0, TurnSpeed, 0));
    }
	}
}

void ASeagull::Shoot() 
{
        UWorld* World = GetWorld();
        if (World)
        {
            FVector Location = GetActorLocation();
            
            //The projectile will be spawned in on center of Mesh
            World->SpawnActor<AActor>(ActorToSpawn, Location + FVector(0.f, 0.f, 0.f), GetActorRotation());
            

        }

    UE_LOG(LogTemp, Warning, TEXT("Shooting"));
}

void ASeagull::LookBackwards()
{
    //int TimesPressed = 0;

    SpringArm->AddRelativeRotation(FRotator(0.f, 180.f, 0.f)); // Turns the SpringArm 180 degrees around to give the player a backwards view

    //if (TimesPressed == 0)
    //{
    //    SpringArm->AddRelativeRotation(FRotator(0.f, 180.f, 0.f)); // Turns the SpringArm 180 degrees around to give the player a backwards view

    //    TimesPressed = 1;
    //}

    //if (TimesPressed == 1)
    //{
    //    //Camera->AddRelativeLocation(FVector(200.f, 0.f, -50.f));
    //    SpringArm->TargetArmLength = 500.f;
    //    SpringArm->AddRelativeRotation(FRotator(30.f, 0.f, 0.f));

    //    TimesPressed = 0;
    //}
}

void ASeagull::IncrementBoost(int32 Amount)
{
    Boost += Amount; 

    //Speed = Speed * Amount; eller Speed = Speed * (0.5 * Amount) elns
}

void ASeagull::ESCPushed()
{
    UE_LOG(LogTemp, Warning, TEXT("ESC Pushed"));
    bESCPushed = true;

    if (MainPlayerController)
    {
        UE_LOG(LogTemp, Warning, TEXT("a"));
        MainPlayerController->TogglePauseMenu();
        UE_LOG(LogTemp, Warning, TEXT("b"));
    }
}

void ASeagull::ESCReleased()
{
    bESCPushed = false;
}

//Resets all checkpoints and sets them as incomplete
void ASeagull::LapComplete()
{
    bCheckPointsComplete = false;
    CheckPointReached[0] = false;
    CheckPointReached[1] = false;
    CheckPointReached[2] = false;
    CheckPointReached[3] = false;
	//UE_LOG(LogTemp, Warning, TEXT("CheckPoints Reset"));
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Lap time: "), Timer); 
    //FString PrintTime = FString::Printf(TEXT("Lap time: %d"), (Timer.ToString()));

   /* if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, PrintTime);
    }*/
}



void ASeagull::LevelCompleteLoad()
{
    //0 = Time attack, 1 NPCRace
	if (ActiveGameMode == 0)
	{
        
        UE_LOG(LogTemp, Warning, TEXT("Time Attack Mode completed!"));
    GetWorldTimerManager().SetTimer(FinishLineTimer, this, &ASeagull::LoadMain, 1.f, false, 5.f);
	}
    else if (ActiveGameMode == 1)
	{

        UE_LOG(LogTemp, Warning, TEXT("NPCRace Gamemode completed!"));
        GetWorldTimerManager().SetTimer(FinishLineTimer, this, &ASeagull::LoadMain, 1.f, false, 5.f);
	}

}

//Loads main menu, done in seagull because GetWorld Requires object, and it fit in here nicely with the other functions.
void ASeagull::LoadMain()
{
    UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenuLevel"));
}