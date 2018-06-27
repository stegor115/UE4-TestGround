// Fill out your copyright notice in the Description page of Project Settings.

#include "Avatar.h"
#include "Spawned_Cube.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Character Movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	//Camera Boom (Big stick that keeps camera away)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; //Length of the "stick"
	CameraBoom->bUsePawnControlRotation = true; //Allows the mouse to rotate the stick relative to the player

	//Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); //Attach camera to the end of the stick of the boom
	Camera->bUsePawnControlRotation = false; //Prevents camera itself from rotating.

	//Cube
	SpawnerCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnerCube"));
	SpawnerCube->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Actions
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AAvatar::Action);
	//Camera Handling
	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &AAvatar::ZoomOut);
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &AAvatar::ZoomIn);
	//Basic Movement
	PlayerInputComponent->BindAxis("MoveForward", this, &AAvatar::MoveForward);
	PlayerInputComponent->BindAxis("MoveBackward", this, &AAvatar::MoveBackward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AAvatar::MoveLeft);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAvatar::MoveRight);
	//Mouse Turning
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

//Actions

void AAvatar::Action()
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	GetWorld()->SpawnActor<ASpawned_Cube>(SpawnerCube->GetComponentLocation(), SpawnerCube->GetComponentRotation(), SpawnInfo);
}
//Camera Handling--------------------------------------------------------------
void AAvatar::ZoomOut() 
{
	if (CameraBoom->TargetArmLength < MAX_CAMERA_DISTANCE) {
		CameraBoom->TargetArmLength += 10.0f;
	} //end if
}
void AAvatar::ZoomIn()
{
	if (CameraBoom->TargetArmLength > MIN_CAMERA_DISTANCE) {
		CameraBoom->TargetArmLength -= 10.0f;
	} //end if
}
//Movement---------------------------------------------------------------------
void AAvatar::MoveForward(float value)
{
	if (Controller && value) {
		//Finds which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		//Get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	} //end if
}

void AAvatar::MoveBackward(float value)
{
	if (Controller && value) {
		//Finds which way is backward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		//Gets "forward" vector (negative direction)
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	} //end if
}

void AAvatar::MoveLeft(float value)
{
	if (Controller && value) {
		//Finds which way is left
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		//Gets "right" vector (negative direction)
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	} //end if
}

void AAvatar::MoveRight(float value)
{
	if (Controller && value) {
		//Finds which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		//Gets right vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	} //end if
}