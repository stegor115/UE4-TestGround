// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawned_Cube.generated.h"

UCLASS()
class TESTINGGROUND_API ASpawned_Cube : public AActor
{
	GENERATED_BODY()
	//Cube
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Cube, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Cube;
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* Flinger;

public:	
	// Sets default values for this actor's properties
	ASpawned_Cube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UStaticMeshComponent* getCube();
	
	
};
