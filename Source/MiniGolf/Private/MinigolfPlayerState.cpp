// Fill out your copyright notice in the Description page of Project Settings.


#include "MinigolfPlayerState.h"
#include "MinigolfGameState.h"

AMinigolfPlayerState::AMinigolfPlayerState() {

	MaxNumberOfCoins = 99999;

	VelocityDelta = 500;
	MagnetDelta = 50;
	LaserDelta = 50;

	NumberOfCoins = 0;
	MaxVelocity = 2500;
	MagnetRange = 0;
	LaserRange = 0;
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
	NumberOfCoins = NumberOfCoins + inc;

	// do not let more than a specific number of coins (it is enough and it won't overflow the screen)
	if (NumberOfCoins > MaxNumberOfCoins)
		NumberOfCoins = MaxNumberOfCoins;
}

void AMinigolfPlayerState::UpgradeVelocity()
{
	MaxVelocity = MaxVelocity + VelocityDelta;
}

void AMinigolfPlayerState::UpgradeMagnet()
{
	MagnetRange = MagnetRange + MagnetDelta;
}

void AMinigolfPlayerState::UpgradeLaser()
{
	LaserRange = LaserRange + LaserDelta;
}
