// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MinigolfGameState.generated.h"

/**
 * 
 */
UCLASS()
class MINIGOLF_API AMinigolfGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	
};
