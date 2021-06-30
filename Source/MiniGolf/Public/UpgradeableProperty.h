// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UpgradeableProperty.generated.h"

/**
 * A class representing an upgrade (strength, magnetic hole, laser-sight).
 */
UCLASS(BlueprintType)
class MINIGOLF_API UUpgradeableProperty : public UObject
{
	GENERATED_BODY()

	float FirstDelta; // difference in value in the second level compared to the first (may be different than ValueDelta)
	float ValueDelta; // difference in value in the next level
	int32 LevelCostDelta; // difference in cost of the next level

public:

	UUpgradeableProperty();

	// initializes all necessary data - initial value, deltas for cost and value, maximum level
	void SetParameters(float zeroValue, float firstDelta, float valueDelta, int32 level, int32 maxLevel, int32 costDelta);

	UPROPERTY(BlueprintReadOnly)
		float Value;

	UPROPERTY(BlueprintReadOnly)
		int32 CurrentLevel;

	UPROPERTY(BlueprintReadOnly)
		int32 MaxLevel;

	// returns price of the next level
	UFUNCTION(BlueprintCallable)
		int32 GetPrice();

	// increases level
	UFUNCTION(BlueprintCallable)
		void Upgrade();
	
};
