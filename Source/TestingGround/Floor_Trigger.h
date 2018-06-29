// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor_Trigger.generated.h"

UCLASS()
class TESTINGGROUND_API AFloor_Trigger : public AActor
{
	GENERATED_BODY()
	//Scene to act as root object
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Scene, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Scene;
	//Cube
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Cube, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Cube;
	//Plane that acts as the trigger
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = Trigger, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Trigger;
public:	
	// Sets default values for this actor's properties
	AFloor_Trigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
