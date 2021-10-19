// Fill out your copyright notice in the Description page of Project Settings.

#include "LoggerActor.h"

ALoggerActor::ALoggerActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALoggerActor::BeginPlay()
{
	Super::BeginPlay();
}

void ALoggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


