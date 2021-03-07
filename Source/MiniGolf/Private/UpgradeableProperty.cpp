// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradeableProperty.h"

UUpgradeableProperty::UUpgradeableProperty() {
	Value = 0;
	ValueDelta = 1;
	CurrentLevel = 0;
	MaxLevel = 3;
	LevelCostDelta = 50;
}

void UUpgradeableProperty::SetParameters(float zeroValue, float firstDelta, float valueDelta, int32 level, int32 maxLevel, int32 costDelta)
{
	Value = zeroValue;
	FirstDelta = firstDelta;
	ValueDelta = valueDelta;
	CurrentLevel = level;
	MaxLevel = maxLevel;
	LevelCostDelta = costDelta;
}

int32 UUpgradeableProperty::GetPrice() {
	return (CurrentLevel + 1) * LevelCostDelta;
}

void UUpgradeableProperty::Upgrade()
{
	if (CurrentLevel < MaxLevel) {
		if (CurrentLevel == 0 && FirstDelta != 0) Value = Value + FirstDelta;
		else Value = Value + ValueDelta;
		++CurrentLevel;
	}
}