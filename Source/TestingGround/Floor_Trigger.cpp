// Fill out your copyright notice in the Description page of Project Settings.

#include "Floor_Trigger.h"
#include "Spawned_Cube.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
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
	//Change shape of cube
	Cube->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f)); //Might be redundant
	Cube->SetRelativeScale3D(FVector(3.0f, 3.0f, 0.25f));

	//Cube, acts the actual trigger.
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(RootComponent);
	//Sizing
	Trigger->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
	Trigger->SetRelativeScale3D(FVector(4.5f,4.5f,0.1f));
	Trigger->SetVisibility(true);
	//Overlap Event
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AFloor_Trigger::Triggered);
	
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
}

void AFloor_Trigger::Triggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ASpawned_Cube* myCube = Cast<ASpawned_Cube>(OtherActor); //Cast to Spawned_Cube
	if (myCube != nullptr) {
		myCube->getCube()->SetEnableGravity(false);
		UE_LOG(LogTemp, Warning, TEXT("Gravity disabled for cube"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("overlapped object is not a cube"));
	}
}