// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "EnhancedInputSubsystems.h"

AFirstPersonPlayerController::AFirstPersonPlayerController()
{
}

void AFirstPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.ExecutionFunction = FName("OnDelayComplete");
	LatentInfo.Linkage = 0;
	LatentInfo.UUID = 1;
	UKismetSystemLibrary::DelayUntilNextFrame(this, LatentInfo);
}

void AFirstPersonPlayerController::OnDelayComplete()
{
	UE_LOG(LogTemp, Warning, TEXT("DelayUntilNextFrame completed — now running next frame."));
	
}
void AFirstPersonPlayerController::SetupInputComponent()
{
	// Only add input mappings and touch UI to local players
	//if (IsLocalController())
	//{
	//	// Add regular input mappings
	//	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("PLAYER IS LOCAL!"));
	//		Subsystem->AddMappingContext(FPMappingContext, 0);
	//	}
	//}
}

