// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle_PlayerController.generated.h"
class ABall;
/**
 * 
 */



UCLASS()
class ARKANOID_API APaddle_PlayerController : public APlayerController
{
	GENERATED_BODY()

		APaddle_PlayerController();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:

	virtual void BeginPlay() override;

	void Launch();

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;
	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	void MoveHorizontal(float _AxisValue);

public:
	 void SpawnNewBall();

	 
};

