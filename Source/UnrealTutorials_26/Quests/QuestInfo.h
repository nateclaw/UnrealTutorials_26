// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct UNREALTUTORIALS_26_API FQuestInfo
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName QuestId = "None";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Progress = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ProgressTotal = 1;
	
	
};
