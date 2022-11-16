// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Xform.generated.h"

USTRUCT()
struct FXform
{
	GENERATED_BODY()

	UPROPERTY()
	FVector Location;
	
	UPROPERTY()
	FQuat Rotation;

	UPROPERTY()
	FVector Scale;

	UPROPERTY()
	float BounceSec;
};
