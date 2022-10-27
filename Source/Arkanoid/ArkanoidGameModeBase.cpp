// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArkanoidGameModeBase.h"

AArkanoidGameModeBase::AArkanoidGameModeBase()
{
}

void AArkanoidGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < BrikSpawn; i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawn aleatorio de bricks"));
		int SpawnBricksNumber = FMath::RandRange(0, 2);

		FVector SpawnLocation{ 0 };
		SpawnLocation.Y = FMath::RandRange(MinSpawnY, MaxSpawnY);
		SpawnLocation.Z = FMath::RandRange(MinSpawnZ, MaxSpawnZ);
		SpawnLocation.X = FMath::RandRange(MinSpawnX, MaxSpawnX);

		SpawnBrik = GetWorld()->SpawnActor<ABrik>(SpawnLocation, FRotator::ZeroRotator);
	}
}
