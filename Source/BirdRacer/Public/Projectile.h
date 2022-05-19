// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class BIRDRACER_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Mesh used for Bullet
	UPROPERTY(VisibleAnywhere, Category = "BulletValues")
		UStaticMeshComponent* BulletMesh;

	//Location of bullet on spawn
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "BulletValues")
		FVector InitialBulletLocation;

	//Direction of bullet travel
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BulletValues")
		FVector InitialBulletDirection;



private:
	//Bullet speed
	UPROPERTY(EditAnywhere, Category = "BulletValues")
		float Speed = 1500.f;

	//Time before bullet gets destroyed
	UPROPERTY(EditAnywhere, Category = "BulletValues")
		float TimeBeforeDestroy = 4.f;

	//Time bullet has lived
	UPROPERTY(EditAnywhere, Category = "BulletValues")
		float TimeLived = 0.f;

	//ON overlap function, not sure if needed, comment in and add function if needed.
	/*UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult);*/


};
