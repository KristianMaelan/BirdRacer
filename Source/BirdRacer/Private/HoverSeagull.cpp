// Fill out your copyright notice in the Description page of Project Settings.


#include "HoverSeagull.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Camera/CameraActor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AHoverSeagull::AHoverSeagull()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Root
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(Root);

	//Mesh
	HoverSeagullMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SeagullMesh"));
	HoverSeagullMesh->SetupAttachment(GetRootComponent());

	//SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetUsingAbsoluteRotation(false);

	SpringArm->SetRelativeRotation(FRotator(-30.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 1200.f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 5.f;

	SpringArm->SetupAttachment(GetRootComponent());


	//Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = false; // Rotate camera based on controller
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	bUseControllerRotationYaw = false;

	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = false;

}

// Called when the game starts or when spawned
void AHoverSeagull::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHoverSeagull::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHoverSeagull::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AHoverSeagull::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveSideways"), this, &AHoverSeagull::MoveSideways);

}

//void AHoverSeagull::MoveForward(float value)
//{
//	//FVector Direction = GetActorForwardVector();
//	//FVector Force = 500000.f * value;
//	//AddMovementInput(Direction, value);
//	//HoverSeagullMesh->AddForce(Force);
//}

void AHoverSeagull::MoveSideways(float value)
{
	float TurnSpeed = value * 2; //Multiply by wanted quantity

	AddActorLocalRotation(FRotator(0, TurnSpeed, 0));
}

