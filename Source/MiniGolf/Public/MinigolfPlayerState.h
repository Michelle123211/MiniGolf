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

public:

	AMinigolfPlayerState();

	UPROPERTY(BlueprintReadOnly)
		int32 Money;

	UPROPERTY(BlueprintReadOnly)
		int32 CoinValue;

	UPROPERTY(BlueprintReadOnly)
		UUpgradeableProperty* StrengthUpgrade;

	UPROPERTY(BlueprintReadOnly)
		UUpgradeableProperty* MagnetUpgrade;

	UPROPERTY(BlueprintReadOnly)
		UUpgradeableProperty* LaserUpgrade;

	AMinigolfGameState* GameState;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void IncrementCoins(int32 inc);

	UFUNCTION(BlueprintCallable)
		void DecrementCoins(int32 dec);

	UFUNCTION(BlueprintCallable)
		void Pay(int32 dec);
	
};
