// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MinigolfGameState.h"
#include "UpgradeableProperty.h"
#include "MinigolfPlayerState.generated.h"

/**
 * A class recording player's progress (e.g. number of coins, level reached, levels of upgrades)
 * and storing important data for the current level (e.g. par, start coordinates, hole coordinates).
 */
UCLASS()
class MINIGOLF_API AMinigolfPlayerState : public APlayerState
{
	GENERATED_BODY()

	int32 MaxNumberOfCoins;

public:

	AMinigolfPlayerState();

	AMinigolfGameState* GameState;

	virtual void BeginPlay() override;

	// level info
	UPROPERTY(BlueprintReadWrite)
		int32 CurrentLevel;
	UPROPERTY(BlueprintReadWrite)
		int32 NumOfLevels;
	UPROPERTY(BlueprintReadWrite)
		FVector Start;
	UPROPERTY(BlueprintReadWrite)
		FRotator StartRotation;
	UPROPERTY(BlueprintReadWrite)
		FVector Finish;
	UPROPERTY(BlueprintReadWrite)
		int32 CurrentPar;

	// upgrades
	UPROPERTY(BlueprintReadOnly)
		UUpgradeableProperty* StrengthUpgrade;
	UPROPERTY(BlueprintReadOnly)
		UUpgradeableProperty* MagnetUpgrade;
	UPROPERTY(BlueprintReadOnly)
		UUpgradeableProperty* LaserUpgrade;

	// money info + interface
	UPROPERTY(BlueprintReadOnly)
		int32 Money;
	UPROPERTY(BlueprintReadOnly)
		int32 CoinValue;
	UFUNCTION(BlueprintCallable)
		void IncrementCoins(int32 inc);
	UFUNCTION(BlueprintCallable)
		void DecrementCoins(int32 dec);
	UFUNCTION(BlueprintCallable)
		void Pay(int32 dec);
	
};
