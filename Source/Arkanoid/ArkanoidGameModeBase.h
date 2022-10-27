// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Brik.h"
#include "ArkanoidGameModeBase.generated.h"
/**
 * 
 */
UCLASS()
class ARKANOID_API AArkanoidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AArkanoidGameModeBase();

private:

	virtual void BeginPlay() override;

	UPROPERTY()
		ABrik* SpawnBrik;

	//Ubicacion del spawneo
	const float MinSpawnY{ 4.0 };
	const float MaxSpawnY{ 4.0 };
	const float MinSpawnX{ -140 };
	const float MaxSpawnX{ 140 };
	const float MinSpawnZ{ 110 };
	const float MaxSpawnZ{ 400 };

	//Cada cuanto se spawnea
	const int BrikSpawn = 4;
};
