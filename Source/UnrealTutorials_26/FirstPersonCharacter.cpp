// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"

//#include "Grabber.h"


// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(FPMappingContext, 0);		//Set in BP as IMC_Default
			Subsystem->AddMappingContext(FPLookMappingContext, 0);	//Set in BP as IMC_MouseLook
		}
	}
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//UE_LOG(LogTemp, Warning, TEXT("INPUT BOUND IN FirstPersonCharacter.cpp"));

	//DEPRECATED INPUT MAPPING
	//PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AFirstPersonCharacter::Forward);
	//PlayerInputComponent->BindAxis(TEXT("Right"), this, &AFirstPersonCharacter::Right);
	//PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	//PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);

	//PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction(TEXT("Grab"), EInputEvent::IE_Pressed, this, &AFirstPersonCharacter::Grab);
	//PlayerInputComponent->BindAction(TEXT("Grab"), EInputEvent::IE_Released, this, &AFirstPersonCharacter::Release);
	////////////////////////////////
	
	//Enhanced Input
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::EIMove); 

		// Looking
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::EIMouseLook);

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Ongoing, this, &AFirstPersonCharacter::EIJump);
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Grabbing
		EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Started, this, &AFirstPersonCharacter::Grab);
		EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Completed, this, &AFirstPersonCharacter::Release);
	}
	
	
}


// Moving our Character with IA_Move
void AFirstPersonCharacter::EIMove(const FInputActionValue& Value)
{
	const FVector2d DirectionValue = Value.Get<FVector2d>();
	if (Controller && DirectionValue != FVector2d(0.0f, 0.0f))
	{
		if (DirectionValue.Y != 0.0f) 
		{
			FVector Forward = GetActorForwardVector();
			AddMovementInput(Forward, DirectionValue.Y);
		}
		if (DirectionValue.X != 0.0f)
		{
			FVector Right = GetActorRightVector();
			AddMovementInput(Right, DirectionValue.X);
		}
		//UE_LOG(LogTemp, Warning, TEXT("IA_Move triggered"));
	}
}

// Mouse-Based Looking with IA_MouseLook
void AFirstPersonCharacter::EIMouseLook(const FInputActionValue& Value)
{
	const FVector2d LookValue = Value.Get<FVector2d>();
	if (Controller && LookValue != FVector2d(0.0, 0.0))
	{
		if (LookValue.X != 0.0f)
		{
			AddControllerYawInput(LookValue.X);
		}
		if (LookValue.Y != 0.0f)
		{
			AddControllerPitchInput(LookValue.Y);
		}
		//UE_LOG(LogTemp, Warning, TEXT("IA_MouseLook triggered"));
	}
}

// Redirects to ACharacter::Jump() 
void AFirstPersonCharacter::EIJump()
{
	//UE_LOG(LogTemp, Warning, TEXT("IA_Jump Ongoing"));
	Jump();
}

//void AFirstPersonCharacter::Forward(float AxisValue)
//{
//	//UE_LOG(LogTemp, Warning, TEXT("Forward %f"), AxisValue);
//	
//	GetCharacterMovement()->AddInputVector(GetActorForwardVector() * AxisValue);
//}

//void AFirstPersonCharacter::Right(float AxisValue)
//{
//	GetCharacterMovement()->AddInputVector(GetActorRightVector() * AxisValue);
//}

void AFirstPersonCharacter::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab() Started"));
	GetGrabber()->Grab();
}

void AFirstPersonCharacter::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab() Completed"));
	GetGrabber()->Release();
}

