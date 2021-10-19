// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PersistenceComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HELLOWORLD_API UPersistenceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float SaveIntervalSec = 10.0f;
	
	UPROPERTY(EditAnywhere)
	AActor* Actor;
	
public:
	UPersistenceComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	const FString FileName = "ActorXform.json";
	FString FilePath;
	float RunningSec = 0.0f;
};

