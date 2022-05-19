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
    SpringArm->TargetArmLength = 1200.f;
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
}

bool ASeagull::AbleToMove(float value)
{
    /*if (MainPlayerController)
    {
        return (value != 0.0f) && (!MainPlayerController->bPauseMenuVisible);
    }*/

    return false;
}

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

void ASeagull::LookBackwards()
{
    SpringArm->AddRelativeRotation(FRotator(0.f, 180.f, 0.f)); // Turns the SpringArm 180 degrees around to give the player a backwards view
}

void ASeagull::ESCPushed()
{
    bESCPushed = true;

    if (MainPlayerController)
    {
      //  MainPlayerController->SwitchPauseMenu();
    }
}

void ASeagull::ESCReleased()
{
    bESCPushed = false;
}

void ASeagull::LapComplete()
{
    bCheckPointsComplete = false;
    CheckPointReached[0] = false;
    CheckPointReached[1] = false;
    CheckPointReached[2] = false;
    CheckPointReached[3] = false;
	//UE_LOG(LogTemp, Warning, TEXT("CheckPoints Reset"));
}



void ASeagull::LevelCompleteLoad()
{
    GetWorldTimerManager().SetTimer(FinishLineTimer, this, &ASeagull::LoadMain, 1.f, false, 5.f);
}

void ASeagull::LoadMain()
{
    UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenuLevel"));
}