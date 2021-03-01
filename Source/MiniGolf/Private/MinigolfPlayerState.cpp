// Fill out your copyright notice in the Description page of Project Settings.


#include "MinigolfPlayerState.h"
#include "MinigolfGameState.h"

AMinigolfPlayerState::AMinigolfPlayerState() {

	CoinValue = 10;
	MaxNumberOfCoins = 99999;

	LevelCostDelta = 50;

	StrengthDelta = 500;
	MagnetDelta = 50;
	LaserDelta = 50;

	LevelOfStrength = 0;
	MaxLevelOfStrength = 3;
	LevelOfMagnet = 0;
	MaxLevelOfMagnet = 3;
	LevelOfLaser = 0;
	MaxLevelOfLaser = 3;

	NumberOfCoins = 0;
	MaxStrength = 2000 + LevelOfStrength * StrengthDelta;
	MagnetRange = 0 + LevelOfMagnet * MagnetDelta;
	LaserRange = 0 + LevelOfLaser * LaserDelta;
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
	NumberOfCoins = NumberOfCoins + inc * CoinValue;

	// do not let more than a specific number of coins (it is enough and it won't overflow the screen)
	if (NumberOfCoins > MaxNumberOfCoins)
		NumberOfCoins = MaxNumberOfCoins;
}

// Probably would be better to create common class for all upgrades and then several instances with various parameters...

int32 AMinigolfPlayerState::GetPriceOfStrength() {

}

void AMinigolfPlayerState::UpgradeStrength()
{
	if (LevelOfStrength < MaxLevelOfStrength) {
		MaxStrength = MaxStrength + StrengthDelta;
		++LevelOfStrength;
	}
}

int32 AMinigolfPlayerState::GetPriceOfMagnet() {

}

void AMinigolfPlayerState::UpgradeMagnet()
{
	if (LevelOfMagnet < MaxLevelOfMagnet) {
		MagnetRange = MagnetRange + MagnetDelta;
		++LevelOfMagnet;
	}
}

int32 AMinigolfPlayerState::GetPriceOfLaser() {

}

void AMinigolfPlayerState::UpgradeLaser()
{
	if (LevelOfLaser < MaxLevelOfLaser) {
		LaserRange = LaserRange + LaserDelta;
		++LevelOfLaser;
	}
}
