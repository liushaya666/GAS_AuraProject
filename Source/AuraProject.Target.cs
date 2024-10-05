// Copyright liusha

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraProjectTarget : TargetRules
{
	public AuraProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "AuraProject" } );
	}
}
