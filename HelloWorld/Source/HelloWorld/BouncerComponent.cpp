// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerComponent.h"

UBouncerComponent::UBouncerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBouncerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UBouncerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const float Control = 0.5f - 0.5f * FMath::Cos(PI * RunningSec);
	
	AActor* Actor = GetOwner();
	FVector V = Actor->GetActorLocation();
	V.Z = Control * (MaxOffset - MinOffset);
	Actor->SetActorRelativeLocation(V);

	RunningSec += DeltaTime;
}
