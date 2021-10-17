// Fill out your copyright notice in the Description page of Project Settings.


#include "LoggerComponent.h"
#include "HelloWorld.h"

#define LOG_THIS(x, ...) \
	LOG("%s::%s() " x, \
	*StaticClass()->GetFName().ToString(), \
	*FString(__FUNCTION__), \
	## __VA_ARGS__)

// Sets default values for this component's properties
ULoggerComponent::ULoggerComponent()
{
	LOG_THIS("LogTickSec=%f", LogTickSec);
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}


void ULoggerComponent::BeginPlay()
{
	Super::BeginPlay();
	
	GetOwner()->PrimaryActorTick.bCanEverTick = true;
	GetOwner()->PrimaryActorTick.bStartWithTickEnabled = true;
	
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
