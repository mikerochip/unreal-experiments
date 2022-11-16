// Fill out your copyright notice in the Description page of Project Settings.

#include "PersistenceComponent.h"

#include "BouncerComponent.h"
#include "HelloWorld.h"
#include "Xform.h"
#include "JsonObjectConverter.h"

UPersistenceComponent::UPersistenceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	FilePath = FString::Printf(TEXT("%s/%s"), FPlatformProcess::UserPreferencesDir(), *FileName);
}

void UPersistenceComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (Actor == nullptr)
		return;

	FString Json;
	if (!FFileHelper::LoadFileToString(Json, *FilePath))
	{
		LOG_THIS("Load|Path=%s|FileDoesNotExist=%s", *FilePath, TEXT("true"));
		return;
	}
	
	LOG_THIS("Load|Path=%s|Json=%s", *FilePath, *Json);
	
	FXform Xform;
	FJsonObjectConverter::JsonObjectStringToUStruct(Json, &Xform);

	Actor->SetActorLocation(Xform.Location);
	Actor->SetActorRotation(Xform.Rotation);
	Actor->SetActorRelativeScale3D(Xform.Scale);
	UBouncerComponent* Bouncer = Actor->FindComponentByClass<UBouncerComponent>();
	if (Bouncer != nullptr)
		Bouncer->RunningSec = Xform.BounceSec;
}

void UPersistenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Actor == nullptr)
		return;

	RunningSec += DeltaTime;
	if (RunningSec < SaveIntervalSec)
		return;

	RunningSec = 0.0f;

	FString Json;
	FXform Xform;
	Xform.Location = Actor->GetActorLocation();
	Xform.Rotation = Actor->GetActorQuat();
	Xform.Scale = Actor->GetActorRelativeScale3D();
	const UBouncerComponent* Bouncer = Actor->FindComponentByClass<UBouncerComponent>();
	if (Bouncer != nullptr)
		Xform.BounceSec = Bouncer->RunningSec;
	FJsonObjectConverter::UStructToJsonObjectString(Xform, Json);

	LOG_THIS("Save|Path=%s|Json=%s", *FilePath, *Json);
	FFileHelper::SaveStringToFile(Json, *FilePath);
}
