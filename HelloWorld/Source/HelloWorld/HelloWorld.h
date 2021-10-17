// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogHelloWorld, Log, All);

#define LOG(x, ...) UE_LOG(LogHelloWorld, Log, TEXT(x), __VA_ARGS__)
#define LOG_WARNING(x, ...) UE_LOG(LogHelloWorld, Warning, TEXT(x), __VA_ARGS__)
#define LOG_ERROR(x, ...) UE_LOG(LogHelloWorld, Error, TEXT(x), __VA_ARGS__)
