// Fill out your copyright notice in the Description page of Project Settings.


#include "Brik.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Ball.h"

// Sets default values
ABrik::ABrik()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMesh(TEXT("StaticMesh'/Game/Meshes/SM_Brick.SM_Brick'")); 
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Brick->SetStaticMesh(BrickMesh.Object);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = SM_Brick;

}

// Called when the game starts or when spawned
void ABrik::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABrik::OnOverlapBegin);
	
}

void ABrik::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball")) {
		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrik::DestroyBrick, 0.1f, false);
	}
}

void ABrik::DestroyBrick()
{
	this->Destroy();
}

// Called every frame
void ABrik::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	srand(time(NULL));
	MovementX = rand() % 12 - 5;

	int MoveSpeed = 40;


	const FVector MoveDirection = FVector(MovementX, 0.0f, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaTime;

	if (Movement.SizeSquared() > 0.0f)
	{
		//const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, FRotator::ZeroRotator, true, &Hit);
	}
}

