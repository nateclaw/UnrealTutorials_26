// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestManager.h"
#include "QuestMarker.generated.h"


class UParticleSystemComponent;
//class AQuestManager;

UCLASS()
class UNREALTUTORIALS_26_API AQuestMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestMarker();


	UFUNCTION(BlueprintCallable)
	void RefreshVisibility();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* ParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ShowAtProgress = 0;

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, BlueprintCallable)
	AQuestManager* GetQuestManager() const;
};
