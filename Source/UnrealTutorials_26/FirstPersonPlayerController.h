// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FirstPersonPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class UNREALTUTORIALS_26_API AFirstPersonPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AFirstPersonPlayerController();

protected:
	/** Input Mapping Contexts */
	/*UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;*/
	
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	/** Returns true if the player should use UMG touch controls */
	bool ShouldUseTouchControls() const;

private:
	UFUNCTION()
	void OnDelayComplete();
};
