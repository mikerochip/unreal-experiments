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
	
	LOG_THIS("LogTickSec=%f", LogTickSec);
}

void ULoggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	RunningTickSec += DeltaTime;
	if (RunningTickSec >= LogTickSec)
	{
		LOG_THIS("RunningTickSec=%f LogTickSec=%f", RunningTickSec, LogTickSec);
		RunningTickSec = 0.0f;
	}
}
