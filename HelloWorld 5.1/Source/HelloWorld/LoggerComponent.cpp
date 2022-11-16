// Fill out your copyright notice in the Description page of Project Settings.

#include "LoggerComponent.h"
#include "HelloWorld.h"

ULoggerComponent::ULoggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void ULoggerComponent::BeginPlay()
{
	Super::BeginPlay();
	
	LOG_THIS("LogIntervalSec=%f", LogIntervalSec);
}

void ULoggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	RunningSec += DeltaTime;
	if (RunningSec >= LogIntervalSec)
	{
		LOG_THIS("RunningTickSec=%f LogIntervalSec=%f", RunningSec, LogIntervalSec);
		RunningSec = 0.0f;
	}
}
