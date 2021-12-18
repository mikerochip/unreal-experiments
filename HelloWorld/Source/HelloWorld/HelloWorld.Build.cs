// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HelloWorld : ModuleRules
{
	public HelloWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new []
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
		});
		
		PublicDependencyModuleNames.AddRange(new []
		{
			"Json",
			"JsonUtilities",
		});
	}
}
