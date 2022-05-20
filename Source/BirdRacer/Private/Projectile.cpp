// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

#include "NPCBird.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "Seagull.h"
#include "gamemodes/NPCRaceGameMode.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setting up root component
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	SetRootComponent(BulletMesh);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	AActor* PlayerActor = Cast<ASeagull>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	FRotator ShotAngle = PlayerActor->GetActorRotation();
	InitialBulletDirection = ShotAngle.Vector();

	//Overlap function, add if needed
	//BulletMesh->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnOverlap);
	BulletMesh->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnOverlap);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	{
		FVector NewLocation = GetActorLocation();
		NewLocation += InitialBulletDirection * Speed * DeltaTime;
		SetActorLocation(NewLocation);
		TimeLived += DeltaTime;

		if (TimeLived > TimeBeforeDestroy)
		{
			this->Destroy();
		}
	}
}

void AProjectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<ANPCBird>())
	{
		UE_LOG(LogTemp, Error, TEXT("Hit enemy"));
		ANPCRaceGameMode* NPCMode = Cast<ANPCRaceGameMode>(GetWorld()->GetAuthGameMode());
		NPCMode->EnemiesKilled++;
		OtherActor->Destroy();
	}

}