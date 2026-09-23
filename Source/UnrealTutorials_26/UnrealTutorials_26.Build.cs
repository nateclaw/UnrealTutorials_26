// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealTutorials_26 : ModuleRules
{
	public UnrealTutorials_26(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"UnrealTutorials_26",
			"UnrealTutorials_26/Variant_Platforming",
			"UnrealTutorials_26/Variant_Platforming/Animation",
			"UnrealTutorials_26/Variant_Combat",
			"UnrealTutorials_26/Variant_Combat/AI",
			"UnrealTutorials_26/Variant_Combat/Animation",
			"UnrealTutorials_26/Variant_Combat/Gameplay",
			"UnrealTutorials_26/Variant_Combat/Interfaces",
			"UnrealTutorials_26/Variant_Combat/UI",
			"UnrealTutorials_26/Variant_SideScrolling",
			"UnrealTutorials_26/Variant_SideScrolling/AI",
			"UnrealTutorials_26/Variant_SideScrolling/Gameplay",
			"UnrealTutorials_26/Variant_SideScrolling/Interfaces",
			"UnrealTutorials_26/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
