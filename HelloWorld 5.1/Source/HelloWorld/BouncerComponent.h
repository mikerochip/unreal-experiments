// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BouncerComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HELLOWORLD_API UBouncerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float MinOffset = -1.0f;
	
	UPROPERTY(EditAnywhere)
	float MaxOffset = 1.0f;

	UPROPERTY(EditAnywhere)
	float Duration = 5.0f;

	UPROPERTY()
	float RunningSec;
	
public:
	UBouncerComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};

