// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MinigolfGameState.h"
#include "UpgradeableProperty.h"
#include "MinigolfPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MINIGOLF_API AMinigolfPlayerState : public APlayerState
{
	GENERATED_BODY()

		int32 MaxNumberOfCoins;

	int32 LevelCostDelta;

	float StrengthDelta;
	float MagnetDelta;
	float LaserDelta;

	int32 LevelOfMagnet;
	int32 MaxLevelOfMagnet;
	int32 LevelOfLaser;
	int32 MaxLevelOfLaser;

public:

	AMinigolfPlayerState();

	UPROPERTY(BlueprintReadOnly)
		int32 NumberOfCoins;

	UPROPERTY(BlueprintReadOnly)
		int32 CoinValue;

	UPROPERTY(BlueprintReadOnly)
		UUpgradeableProperty* StrengthUpgrade;

	UPROPERTY(BlueprintReadOnly)
		float MaxStrength;
	UPROPERTY(BlueprintReadOnly)
		int32 LevelOfStrength;
	UPROPERTY(BlueprintReadOnly)
		int32 MaxLevelOfStrength;

	UPROPERTY(BlueprintReadOnly)
		float MagnetRange;

	UPROPERTY(BlueprintReadOnly)
		float LaserRange;

	AMinigolfGameState* GameState;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Coins")
		void IncrementCoins(int32 inc);

	UFUNCTION(BlueprintCallable, Category = "Upgrades")
		int32 GetPriceOfStrength();

	UFUNCTION(BlueprintCallable, Category = "Upgrades")
		void UpgradeStrength();

	UFUNCTION(BlueprintCallable, Category = "Upgrades")
		int32 GetPriceOfMagnet();

	UFUNCTION(BlueprintCallable, Category = "Upgrades")
		void UpgradeMagnet();

	UFUNCTION(BlueprintCallable, Category = "Upgrades")
		int32 GetPriceOfLaser();

	UFUNCTION(BlueprintCallable, Category = "Upgrades")
		void UpgradeLaser();
	
};
