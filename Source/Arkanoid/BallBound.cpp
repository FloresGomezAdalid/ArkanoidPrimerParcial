// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Paddle_PlayerController.h"
#include "BallBound.h"


void ABallBound::BeginPlay()
{
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABallBound::OnOverlapBegin);

	PlayerControllerREF = Cast<APaddle_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

}

void ABallBound::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collision"));
	if (OtherActor->ActorHasTag("Ball")) {
		OtherActor->Destroy();

		PlayerControllerREF->SpawnNewBall();
	}

}

