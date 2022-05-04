// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/CountDownTimer.h"

#include "Seagull.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACountDownTimer::ACountDownTimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    Sprites.Init(0, 3);

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
    CountdownText->SetHorizontalAlignment(EHTA_Center);
    CountdownText->SetWorldSize(250.0f);
    CountdownText->SetTextRenderColor(FColor::Red);
    RootComponent = CountdownText;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshCom(TEXT("StaticMesh'/Game/HUD/Countdown/sphere.sphere'"));



    Sprites[0] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpriteGO"));
    Sprites[1] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sprite1"));
    Sprites[2] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sprite2"));
    //Sprites[3] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sprite3"));

    int ArraySize = Sprites.Num();
    if (SphereMeshCom.Succeeded()) {
        for (int i = 0; i < ArraySize; i++) {
            Sprites[i]->SetStaticMesh(SphereMeshCom.Object);
            //UE_LOG(LogTemp, Warning, TEXT("check"));
        }
    }

    CountdownTime = 3;



}

// Called when the game starts or when spawned
void ACountDownTimer::BeginPlay()
{
	Super::BeginPlay();
    //Sprites[0]->SetWorldLocation(FVector(760.f, -200.f, 350.f));
   // Sprites[1]->SetWorldLocation(FVector(760.f, 0.f, 350.f));
   // Sprites[2]->SetWorldLocation(FVector(760.f, 200.f, 350.f));
   // Sprites[3]->SetWorldLocation(FVector(760.f, 400.f, 350.f));

    UpdateTimerDisplay();
    GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &ACountDownTimer::AdvanceTimer, 1.0f, true);
    UWorld* World = GetWorld();
    if (World) {
        UGameplayStatics::PlaySound2D(World, CountDownSound, 1.f, 1.f, 0.f);
    }
	
}

// Called every frame
void ACountDownTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACountDownTimer::UpdateTimerDisplay()
{
    CountdownText->SetText(FText::AsNumber(CountdownTime));
}

void ACountDownTimer::AdvanceTimer()
{
    UpdateTimerDisplay();
    if (CountdownTime < 1)
    {
        CountdownHasFinished();

    }
    if (CountdownTime < 0)
    {
        //We're done counting down, so stop running the timer.
        GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
        Destroy();

    }
    CountdownTime--;
    if (CountdownTime >= 0 && CountdownTime < 3) {
        Sprites[CountdownTime]->DestroyComponent();
    }
}

void ACountDownTimer::CountdownHasFinished()
{
    ASeagull* PlayerChar = Cast<ASeagull>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
    PlayerChar->bGameCanPlay = true;
    CountdownText->SetTextRenderColor(FColor::Green);
    CountdownText->SetText(INVTEXT("GO!")); //INVTEXT == text that does not need translation / localization



}

