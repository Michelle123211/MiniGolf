// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MinigolfGameState.h"
#include "MinigolfPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MINIGOLF_API AMinigolfPlayerState : public APlayerState
{
	GENERATED_BODY()

	int32 MaxNumberOfCoins;
	float VelocityDelta;
	float MagnetDelta;
	float LaserDelta;

public:

	AMinigolfPlayerState();

	UPROPERTY(BlueprintReadOnly)
	int32 NumberOfCoins;

	UPROPERTY(BlueprintReadOnly)
	float MaxVelocity;

	UPROPERTY(BlueprintReadOnly)
	float MagnetRange;

	UPROPERTY(BlueprintReadOnly)
	float LaserRange;

	AMinigolfGameState* GameState;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Coins")
	void IncrementCoins(int32 inc);

	UFUNCTION(BlueprintCallable, Category = "Upgrades")
	void UpgradeVelocity();

	UFUNCTION(BlueprintCallable, Category = "Upgrades")
	void UpgradeMagnet();

	UFUNCTION(BlueprintCallable, Category = "Upgrades")
	void UpgradeLaser();
	
};
