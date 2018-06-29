// Fill out your copyright notice in the Description page of Project Settings.

#include "Floor_Trigger.h"
#include "Spawned_Cube.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
AFloor_Trigger::AFloor_Trigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Scene
	Scene = CreateDefaultSubobject <USceneComponent>(TEXT("Root"));
	Scene->SetVisibility(true);
	RootComponent = Scene;
	//Cube, acts the visible obejct for the player
	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	Cube->SetupAttachment(RootComponent);
	//Set Mesh to Cube
	ConstructorHelpers::FObjectFinder<UStaticMesh>cubeMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")); //Finds the desired mesh, and ties it to cubeMesh
	Cube->SetStaticMesh(cubeMesh.Object);

	//Cube, acts the actual trigger.
	Trigger = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(RootComponent);
	//Set Mesh to Cube
	ConstructorHelpers::FObjectFinder<UStaticMesh>triggerMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")); //Finds the desired mesh, and ties it to cubeMesh
	Trigger->SetStaticMesh(triggerMesh.Object);
}

// Called when the game starts or when spawned
void AFloor_Trigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloor_Trigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Check if Spawned Cube is on the block
}

