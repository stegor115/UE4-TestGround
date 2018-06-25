// Fill out your copyright notice in the Description page of Project Settings.

#include "Avatar.h"
#include "Components/InputComponent.h"

// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	PlayerInputComponent->BindAxis("MoveForward", this, &AAvatar::MoveForward);
	PlayerInputComponent->BindAxis("MoveBackward", this, &AAvatar::MoveBackward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AAvatar::MoveLeft);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAvatar::MoveRight);
}

void AAvatar::MoveForward(float value)
{
	if (Controller && value) {
		AddMovementInput(GetActorForwardVector(), value);
	} //end if
}

void AAvatar::MoveBackward(float value)
{
	if (Controller && value) {
		AddMovementInput(GetActorForwardVector(), value);
	} //end if
}

void AAvatar::MoveLeft(float value)
{
	if (Controller && value) {
		AddMovementInput(GetActorRightVector(), value);
	} //end if
}

void AAvatar::MoveRight(float value)
{
	if (Controller && value) {
		AddMovementInput(GetActorRightVector(), value);
	} //end if
}