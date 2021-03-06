// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class BIRDRACER_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    public:
    //base collision shape
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item")
		class USphereComponent* CollisionVolume;

    //Base mesh component
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item" )
    class UMeshComponent* Mesh{nullptr};

    //Particles when item is idle
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		class UParticleSystemComponent* IdleParticlesComponent{nullptr};

    //Smoke effect (for example)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Particles")
    class UParticleSystem* OverlapParticles{ nullptr };

    //Rotation of item
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
        bool bRotate{nullptr};

    //Rotation rate
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    float RotationRate{};


public:
    //Overlap functions
    UFUNCTION()
    virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
