// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawned_Cube.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
ASpawned_Cube::ASpawned_Cube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Good reference to make a basic object in C++, avoiding blueprints
	//A good idea in the future, Blueprints might help a lot to make first, then try to replicate.
	//Cube
	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	Cube->SetupAttachment(RootComponent);
	//Set Mesh to Cube
	ConstructorHelpers::FObjectFinder<UStaticMesh>cubeMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")); //Finds the desired mesh, and ties it to cubeMesh
	Cube->SetStaticMesh(cubeMesh.Object);
	//Physics
	Cube->SetSimulatePhysics(true);
	//Add Force Here
	Flinger = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Flinger"));
	Flinger->Velocity = FVector(5000.0f, 0.0f, 0.0f);
}

// Called when the game starts or when spawned
void ASpawned_Cube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawned_Cube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

