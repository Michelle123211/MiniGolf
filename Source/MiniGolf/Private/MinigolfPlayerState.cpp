// Fill out your copyright notice in the Description page of Project Settings.


#include "MinigolfPlayerState.h"
#include "MinigolfGameState.h"

AMinigolfPlayerState::AMinigolfPlayerState() {
	CurrentLevel = 0;
	NumOfLevels = 0, 0, 0;
	Start = FVector(0, 0, 0);
	StartRotation = FRotator(0, 0, 0);
	Finish = FVector(0, 0, 0);
	CurrentPar = 0;

	MaxNumberOfCoins = 99999;
	CoinValue = 10;
	Money = 0;

	StrengthUpgrade = NewObject<UUpgradeableProperty>(UUpgradeableProperty::StaticClass());
	StrengthUpgrade->SetParameters(2000, 0, 500, 0, 3, 50); // 0th level is 2000, then +500 with each

	MagnetUpgrade = NewObject<UUpgradeableProperty>(UUpgradeableProperty::StaticClass());
	MagnetUpgrade->SetParameters(0, 240, 120, 0, 3, 50); // 0th level is 0, 1st is 240, then +120 with each

	LaserUpgrade = NewObject<UUpgradeableProperty>(UUpgradeableProperty::StaticClass());
	LaserUpgrade->SetParameters(0, 0, 1000, 0, 3, 50); // 0th level is 0, then +1000 with each
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

	// do not allow more than a specific number of coins (it is enough and it won't overflow the screen)
	if (Money > MaxNumberOfCoins)
		Money = MaxNumberOfCoins;
}

void AMinigolfPlayerState::DecrementCoins(int32 dec)
{
	int32 newValue = Money - dec * CoinValue;
	if (newValue < 0) return;

	Money = newValue;
}

void AMinigolfPlayerState::Pay(int32 price)
{
	int32 newValue = Money - price;
	if (newValue < 0) return;

	Money = newValue;
}
