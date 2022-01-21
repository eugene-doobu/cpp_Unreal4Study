// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;
	ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));
	if (SM.Succeeded()) {
		Mesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 카테고리, 로깅 수준, 형식, 인자
	// 수준에 따라 로그의 색상도 바꿀 수 있음
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 매 프레임 로그를 찍는것은 실행파일을 남기기 때문에 좋지 못함
	//UE_LOG(LogTemp, Error, TEXT("Tick %f"), DeltaTime);

	AddActorLocalRotation(FRotator(0.f, RotateSpeed * DeltaTime, 0.f));
}

