// Fill out your copyright notice in the Description page of Project Settings.


#include "MinigolfPlayerState.h"
#include "MinigolfGameState.h"

AMinigolfPlayerState::AMinigolfPlayerState() {
	MaxNumberOfCoins = 99999;
	CoinValue = 10;
	Money = 0;

	StrengthUpgrade = NewObject<UUpgradeableProperty>(UUpgradeableProperty::StaticClass());
	StrengthUpgrade->SetParameters(2000, 500, 0, 3, 50);

	MagnetUpgrade = NewObject<UUpgradeableProperty>(UUpgradeableProperty::StaticClass());
	MagnetUpgrade->SetParameters(0, 50, 0, 3, 50);

	LaserUpgrade = NewObject<UUpgradeableProperty>(UUpgradeableProperty::StaticClass());
	LaserUpgrade->SetParameters(0, 50, 0, 3, 50);
}

void AMinigolfPlayerState::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (!IsValid(World)) return;

	GameState = World->GetGameState<AMinigolfGameState>();
	if (!IsValid(GameState)) return;
}

void AMinigolfPlayerState::IncrementCoins(int32 inc)
{
	Money = Money + inc * CoinValue;

	// do not let more than a specific number of coins (it is enough and it won't overflow the screen)
	if (Money > MaxNumberOfCoins)
		Money = MaxNumberOfCoins;
}

void AMinigolfPlayerState::DecrementCoins(int32 dec)
{
	Money = Money - dec * CoinValue;
	// Change implementation to the following one:
	//int32 newValue = NumberOfCoins - dec * CoinValue;
	//if (newValue < 0) return;

	//NumberOfCoins = newValue;
}

void AMinigolfPlayerState::Pay(int32 price)
{
	Money = Money - price;
}
