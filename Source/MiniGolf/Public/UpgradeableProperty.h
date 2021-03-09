// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UpgradeableProperty.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MINIGOLF_API UUpgradeableProperty : public UObject
{
	GENERATED_BODY()

	float FirstDelta;
	float ValueDelta;
	int32 LevelCostDelta;

public:

	UUpgradeableProperty();

	void SetParameters(float zeroValue, float firstDelta, float valueDelta, int32 level, int32 maxLevel, int32 costDelta);

	UPROPERTY(BlueprintReadOnly)
		float Value;

	UPROPERTY(BlueprintReadOnly)
		int32 CurrentLevel;

	UPROPERTY(BlueprintReadOnly)
		int32 MaxLevel;

	UFUNCTION(BlueprintCallable)
		int32 GetPrice();

	UFUNCTION(BlueprintCallable)
		void Upgrade();
	
};
